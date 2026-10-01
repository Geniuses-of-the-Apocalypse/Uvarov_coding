# b0fa23c85d643c9d753244eb3a99cce4

from dataclasses import dataclass
from enum import Enum
from typing import Generic, TypeVar, Union

T = TypeVar("T")
E = TypeVar("E")


class LoadState(Enum):
    LOADING = "loading"
    SUCCESS = "success"
    ERROR = "error"


@dataclass(frozen=True)
class User:
    name: str
    age: int
    email: str


@dataclass(frozen=True)
class Success(Generic[T]):
    value: T


@dataclass(frozen=True)
class Failure(Generic[E]):
    error: E


Result = Union[Success[T], Failure[E]]


def load_users() -> Result[list[User], str]:
    users = [
        User("Vova", 30, "vova@mail.ru"),
        User("Gleb", 25, "gleb@mail.ru"),
    ]
    if not users:
        return Failure("Список пользователей пуст")
    return Success(users)


result = load_users()

match result:
    case Success(value):
        print("Пользователи:", value)
    case Failure(error):
        print("Ошибка:", error)