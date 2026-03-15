package ru.guu_java.lab2;

public class Main {
    public static void main(String[] args) {
        // ТЕСТЫ ДЛЯ CAR
        System.out.println("<<< ТЕСТИРОВАНИЕ КЛАССА CAR >>>\n");

        // Тест 1: Конструктор с параметрами
        System.out.println("ТЕСТ 1: Конструктор с параметрами");
        Car car1 = new Car("Toyota", 4, 150);
        System.out.println(car1);
        System.out.println();

        // Тест 2: Конструктор по умолчанию
        System.out.println("ТЕСТ 2: Конструктор по умолчанию");
        Car car2 = new Car();
        System.out.println(car2);
        System.out.println();

        // Тест 3: Конструктор копирования
        System.out.println("ТЕСТ 3: Конструктор копирования");
        Car car3 = new Car(car1);
        System.out.println("Копия car1:");
        System.out.println(car3);
        System.out.println();

        // Тест 4: Сеттеры
        System.out.println("ТЕСТ 4: Сеттеры");
        car2.setMark("Honda");
        car2.setCyl(6);
        car2.setPower(200);
        System.out.println("После установки значений:");
        System.out.println(car2);
        System.out.println();

        // Тест 5: Метод addPower()
        System.out.println("ТЕСТ 5: Метод addPower()");
        System.out.println("Текущая мощность car1: " + car1.addPower());
        car1.addPower(50);
        System.out.println("После addPower(50): " + car1.addPower());
        System.out.println();

        // Тест 6: toString()
        System.out.println("ТЕСТ 6: toString()");
        System.out.println("car1:\n" + car1);
        System.out.println("car2:\n" + car2);
        System.out.println("car3:\n" + car3);

        System.out.println("\n---------------------------------\n");

        // ТЕСТЫ ДЛЯ LORRY
        System.out.println("<<< ТЕСТИРОВАНИЕ КЛАССА LORRY >>>\n");

        // Тест 7: Конструктор с параметрами
        System.out.println("ТЕСТ 7: Конструктор с параметрами");
        Lorry lorry1 = new Lorry("Volvo", 6, 400, 20);
        System.out.println(lorry1);
        System.out.println();

        // Тест 8: Конструктор по умолчанию
        System.out.println("ТЕСТ 8: Конструктор по умолчанию");
        Lorry lorry2 = new Lorry();
        System.out.println(lorry2);
        System.out.println();

        // Тест 9: Конструктор копирования
        System.out.println("ТЕСТ 9: Конструктор копирования");
        Lorry lorry3 = new Lorry(lorry1);
        System.out.println("Копия lorry1:");
        System.out.println(lorry3);
        System.out.println();

        // Тест 10: Наследованные методы (из Car)
        System.out.println("ТЕСТ 10: Наследованные методы из Car");
        System.out.println("Марка lorry1: " + lorry1.getMark());
        System.out.println("Цилиндры lorry1: " + lorry1.getCyl());
        System.out.println("Мощность lorry1: " + lorry1.addPower());
        System.out.println();

        // Тест 11: Специфичные методы Lorry
        System.out.println("ТЕСТ 11: методы Lorry");
        System.out.println("Грузоподъемность lorry1: " + lorry1.getCap());
        lorry1.setCap(25);
        System.out.println("После setCap(25): " + lorry1.getCap());
        lorry1.addCap(5);
        System.out.println("После addCap(5): " + lorry1.getCap() + " (ожидается 30)");
        System.out.println();

        // Тест 12: toString() с наследованием
        System.out.println("ТЕСТ 12: toString()");
        System.out.println("lorry1:\n" + lorry1 + "\n");
        System.out.println("lorry2:\n" + lorry2 + "\n");
        System.out.println("lorry3:\n" + lorry3 + "\n");
    }
}