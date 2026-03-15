package ru.guu_java.lab4;

class Person implements Comparable<Person> {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person other) {
        if (this.age < other.age) return -1;
        if (this.age > other.age) return 1;
        return 0;
    }

    @Override
    public String toString() {
        return name + "(" + age + ")";
    }
}
