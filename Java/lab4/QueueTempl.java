package ru.guu_java.lab4;

import java.util.NoSuchElementException;

public class QueueTempl<T extends Comparable<T>> {

    private class QueueItem {
        private T data;
        private QueueItem next;

        public QueueItem(T data, QueueItem next) {
            this.data = data;
            this.next = next;
        }

        public T getData() {
            return data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public QueueItem getNext() {
            return next;
        }

        public void setNext(QueueItem next) {
            this.next = next;
        }
    }

    private QueueItem head;
    private QueueItem tail;
    private int size;

    public QueueTempl() {
        head = null;
        tail = null;
        size = 0;
    }

    public void add(T element) {
        QueueItem newItem = new QueueItem(element, null);
        if (isEmpty()) {
            head = newItem;
            tail = newItem;
        } else {
            tail.setNext(newItem);
            tail = newItem;
        }
        size++;
    }

    public T dequeue() {
        if (isEmpty()) throw new NoSuchElementException("Очередь пуста");
        T data = head.getData();
        head = head.getNext();
        if (head == null) tail = null;
        size--;
        return data;
    }

    public T peek() {
        if (isEmpty()) throw new NoSuchElementException("Очередь пуста");
        return head.getData();
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int size() {
        return size;
    }

    public void clear() {
        head = null;
        tail = null;
        size = 0;
    }

    public void heapSort() {
        if (size <= 1) return;

        // Преобразуем очередь в массив
        @SuppressWarnings("unchecked")
        T[] arr = (T[]) new Comparable[size];
        QueueItem curr = head;
        for (int i = 0; i < size; i++) {
            arr[i] = curr.getData();
            curr = curr.getNext();
        }

        // Используем отдельный класс для сортировки
        HeapSorter.sort(arr);

        // Восстанавливаем очередь
        rebuildQueue(arr);
    }

    private void rebuildQueue(T[] arr) {
        head = null;
        tail = null;
        size = 0;
        for (T item : arr) {
            add(item);
        }
    }

    @Override
    public String toString() {
        if (isEmpty()) return "QueueTempl{}";
        StringBuilder sb = new StringBuilder("QueueTempl{");
        QueueItem curr = head;
        while (curr != null) {
            sb.append(curr.getData());
            curr = curr.getNext();
            if (curr != null) sb.append(", ");
        }
        sb.append("}");
        return sb.toString();
    }
}