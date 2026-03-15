package ru.guu_java.lab4;

/**
 * Класс для пирамидальной сортировки
 */
class HeapSorter {

    public static <T extends Comparable<T>> void sort(T[] arr) {
        if (arr.length <= 1) return;

        int n = arr.length;

        // 1. Построение кучи (превращаем массив в max-heap)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // 2. Извлекаем элементы из кучи по одному
        for (int i = n - 1; i > 0; i--) {
            // Перемещаем текущий корень в конец
            T temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Восстанавливаем кучу для уменьшенного массива
            heapify(arr, i, 0);
        }
    }

    /**
     * Преобразует поддерево в кучу
     * @param arr массив
     * @param n размер кучи
     * @param i индекс корня поддерева
     */
    private static <T extends Comparable<T>> void heapify(T[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Если левый больше корня
        if (left < n && arr[left].compareTo(arr[largest]) > 0)
            largest = left;

        // Если правый больше текущего наибольшего
        if (right < n && arr[right].compareTo(arr[largest]) > 0)
            largest = right;

        // Если наибольший элемент не корень
        if (largest != i) {
            T swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }
}
