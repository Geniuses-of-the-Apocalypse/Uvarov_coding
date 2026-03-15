package ru.guu_java.lab5;
import static ru.guu_java.lab5.getFirstTwoChars.getFTC;

public class Main {
    public static void main(String[] args) {
        String text = "Используя регулярные выражения вернуть первые два символа каждого слова";

        String result = getFTC(text);
        System.out.println("Исходный текст: " + text);
        System.out.println("Результат: " + result);
    }
}
