package ru.guu_java.lab2;

import java.util.Scanner;

public class Car {
    protected String mark;
    protected int cyl;
    protected int power;

    public Car(String mark, int cyl, int power) {
        this.mark = mark;
        this.cyl = cyl;
        this.power = power;
    }

    public Car() {
        mark = "Нет информации";
        cyl = 0;
        power = 0;
    }

    public Car(Car s) {
        mark = s.mark;
        cyl = s.cyl;
        power = s.power;
    }

    public void setMark(String mark) {this.mark = mark;}
    public void setCyl(int cyl) {this.cyl = cyl;}
    public void setPower(int power) {this.power = power;}
    public void addPower(int addPower) {this.power += addPower;}

    public String getMark() {return mark;}
    public int getCyl() {return cyl;}
    public int addPower() {return power;}

    @Override
    public String toString() {
        return "Торговая марка: " + mark + "\n" + "Количество цилиндров: " + cyl + "\n" + "Мощность: " + mark;
    }

    public void read() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Введите торговую марку ");
        mark = scan.nextLine();
        System.out.print("Введите количество цилиндров ");
        cyl = scan.nextInt();
        System.out.print("Введите мощность ");
        power = scan.nextInt();
    }
}
