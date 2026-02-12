package ru.guu_java;

import java.util.Scanner;

public class Complex {
    private float a, b;

    public void init(float a_val, float b_val) {
        a = a_val;
        b = b_val;
    }

    public void read() {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите действительную часть: ");
        a = in.nextFloat();
        System.out.print("Введите мнимую часть: ");
        b = in.nextFloat();
    }

    public String tostring() {
        return a + " + " + b + "i";
    }

    public void display() {
        System.out.println(tostring());
    }

    public Complex add(Complex other) {
        Complex res = new Complex();
        res.a = a + other.a;
        res.b = b + other.b;
        return res;
    }

    public Complex sub(Complex other) {
        Complex res = new Complex();
        res.a = a - other.a;
        res.b = b - other.b;
        return res;
    }

    public Complex mul(Complex other) {
        // (ac - bd, ad + bc)
        Complex res = new Complex();
        res.a = (a * other.a - b * other.b);
        res.b = (a * other.b + b * other.a);
        return res;
    }

    public Complex div(Complex other) {
        // (ac + bd, bc – ad)/(c*c + d*d)
        Complex res = new Complex();
        if (other.a == 0 && other.b == 0) {
            throw new ArithmeticException("Деление на ноль");
        }
        res.a = (a * other.a + b * other.b) / (other.a * other.a + other.b * other.b);
        res.b = (b * other.a - a * other.b) / (other.a * other.a + other.b * other.b);
        return res;
    }

    public boolean equ(Complex other) {
        return this.a == other.a && this.b == other.b;
    }

    public Complex conj() {
        Complex res = new Complex();
        res.init(this.a, -this.b);
        return res;
    }
}
