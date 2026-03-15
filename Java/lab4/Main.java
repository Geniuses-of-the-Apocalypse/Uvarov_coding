package ru.guu_java.lab4;

class Main {
    public static void main(String[] args) {
        QueueTempl<Person> queue = new QueueTempl<>();

        queue.add(new Person("Анна", 25));
        queue.add(new Person("Иван", 30));
        queue.add(new Person("Мария", 22));
        queue.add(new Person("Петр", 28));
        queue.add(new Person("Ольга", 27));

        System.out.println("До сортировки: " + queue);

        queue.heapSort();

        System.out.println("После сортировки: " + queue);

        // Проверка остальных методов
        System.out.println("\nПервый элемент: " + queue.peek());
        System.out.println("Размер очереди: " + queue.size());

        System.out.println("\nУдаляем все элементы:");
        while (!queue.isEmpty()) {
            System.out.println("Удален: " + queue.dequeue());
        }

        System.out.println("Очередь пуста? " + queue.isEmpty());
    }

}
