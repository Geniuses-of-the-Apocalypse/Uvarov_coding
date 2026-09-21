import csv
from typing import Optional

from fastapi import FastAPI, HTTPException, Depends
from pydantic import BaseModel

app = FastAPI(title="CSV Revenue API")


def parse_csv(data: str) -> list[dict]:
    return list(csv.DictReader(data.splitlines()))


def compute_revenue(rows: list[dict]) -> float:
    return sum(map(lambda x: float(x["quantity"]) * float(x["price"]), rows))


def top_item(rows: list[dict]) -> Optional[dict]:
    if not rows:
        return None
    best = max(
        rows,
        key=lambda x: float(x["quantity"]) * float(x["price"])
    )
    return {
        "date": best["date"],
        "item": best["item"],
        "quantity": float(best["quantity"]),
        "price": float(best["price"]),
        "revenue": float(best["quantity"]) * float(best["price"]),
    }


class CSVRequest(BaseModel):
    data: str


def get_rows(payload: CSVRequest) -> list[dict]:
    rows = parse_csv(payload.data)
    if not rows:
        raise HTTPException(status_code=400, detail="CSV пустой или не распарсился")
    return rows


@app.post("/parse")
def parse_endpoint(payload: CSVRequest):
    rows = parse_csv(payload.data)
    return {"rows": rows, "count": len(rows)}


@app.post("/revenue")
def revenue_endpoint(rows: list[dict] = Depends(get_rows)):
    return {"revenue": compute_revenue(rows)}


@app.post("/top-item")
def top_item_endpoint(rows: list[dict] = Depends(get_rows)):
    return {"top_item": top_item(rows)}


@app.post("/report")
def report_endpoint(rows: list[dict] = Depends(get_rows)):
    return {
        "rows": rows,
        "revenue": compute_revenue(rows),
        "top_item": top_item(rows),
    }