package ru.guu_java.lab2;

import java.util.Scanner;

public class Lorry extends Car{
    private int cap;

    public Lorry(String mark, int cyl, int power, int cap) {
        super(mark, cyl, power);
        this.cap = cap;
    }

    public Lorry() {
        super();
        cap = 0;
    }

    public Lorry(Lorry other) {
        super(other.mark, other.cyl, other.power);
        this.cap = other.cap;
    }

    @Override
    public void setMark(String mark) { super.setMark(mark);}

    public void setCap(int cap) {this.cap = cap;}
    public int getCap() {return cap;}

    public void addCap(int addCap) {this.cap += addCap;}

    @Override
    public String toString() {return super.toString() + "\n" + "Грузоподъемность кузова: " + cap + " тонн";}

    @Override
    public void read() {
        super.read();
        Scanner scan = new Scanner(System.in);
        System.out.print("Введите грузоподъемность кузова (в тоннах): ");
        cap = scan.nextInt();
    }
}
