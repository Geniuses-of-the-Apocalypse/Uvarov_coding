package ru.guu_java;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Тестирование класса Complex ===\n");

        // 1. Тест init и display
        System.out.println("1. Тест init и display:");
        Complex z1 = new Complex();
        z1.init(2f, 3f);
        System.out.print("z1 = ");
        z1.display();  // 2.0 + 3.0i

        // 2. Тест конструктора через init
        Complex z2 = new Complex();
        System.out.println("Ввод z2:");
        z2.read();
        System.out.print("z2 = ");
        z2.display();  // 4.0 + -1.0i
        System.out.println();

        // 3. Тест сложения
        System.out.println("2. Тест сложения (z1 + z2):");
        Complex sum = z1.add(z2);
        System.out.print("z1 + z2 = ");
        sum.display();  // 6.0 + 2.0i
        System.out.println();

        // 4. Тест вычитания
        System.out.println("3. Тест вычитания (z1 - z2):");
        Complex sub = z1.sub(z2);
        System.out.print("z1 - z2 = ");
        sub.display();  // -2.0 + 4.0i
        System.out.println();

        // 5. Тест умножения
        System.out.println("4. Тест умножения (z1 * z2):");
        Complex mul = z1.mul(z2);
        System.out.print("z1 * z2 = ");
        mul.display();  // (2*4 - 3*(-1)) + (2*(-1) + 3*4)i = (8+3) + (-2+12)i = 11.0 + 10.0i
        mul.display();

        // 6. Тест деления
        System.out.println("5. Тест деления (z1 / z2):");
        Complex div = z1.div(z2);
        System.out.print("z1 / z2 = ");
        div.display();  // (8 + (-3))/(16+1) + ((12 - (-2))/17)i = 5/17 + 14/17i ≈ 0.294 + 0.823i
        System.out.println();

        // 7. Тест сравнения
        System.out.println("6. Тест сравнения (equals):");
        Complex z3 = new Complex();
        z3.init(2f, 3f);
        System.out.print("z3 = ");
        z3.display();
        System.out.println("z1 == z3 " + z1.equ(z3));  // true
        System.out.println("z1 == z2 " + z1.equ(z2));  // false
        System.out.println();

        // 8. Тест сопряжённого числа
        System.out.println("7. Тест сопряжённого числа:");
        Complex conj = z1.conj();
        System.out.print("Сопряжённое для z1 = ");
        conj.display();  // 2.0 + -3.0i
        System.out.println();
    }
}