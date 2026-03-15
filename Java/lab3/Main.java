package ru.guu_java.lab3;

public class Main {
    public static void main(String[] args) {
        // ===== Fraction =====
        Fraction f1 = new Fraction(5.3456, 2);
        Fraction f2 = new Fraction(-2.1111, 3);
        Array f3 = f1.add(f2);

        System.out.println("Fraction:");
        System.out.println("f1 = " + f1);
        System.out.println("f2 = " + f2);
        System.out.println("f1 + f2 = " + f3);
        System.out.println();

        // ===== BitString =====
        BitString b1 = new BitString("1010110");
        BitString b2 = new BitString("1100011");
        Array b3 = b1.add(b2);

        System.out.println("BitString:");
        System.out.println("b1 = " + b1);
        System.out.println("b2 = " + b2);
        System.out.println("b1 + b2 = " + b3);
        System.out.println();

        // ===== Полиморфизм =====
        Array a1 = new Fraction(3.14, 2);
        Array a2 = new Fraction(1.11, 2);
        Array a3 = a1.add(a2);
        System.out.println("Полиморфизм:");
        System.out.println("a1 + a2 = " + a3);
    }
}