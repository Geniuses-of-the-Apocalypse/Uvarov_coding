#include <iostream>
using namespace std;

template<typename T>
void Myswap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Пузырьковая сортировка
template<typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Myswap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Шаблонная функция для вычисления медианы (сортирует исходный массив)
template<typename T>
double median(T arr[], int size) {
    if (size <= 0) {
        throw "Массив не может быть пустым";
    }

    T* sortedArr = new T[size];
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }

    bubbleSort(sortedArr, size);
    double result;
    if (size % 2 == 0) {
        result = (sortedArr[size / 2 - 1] + sortedArr[size / 2]) / 2.0;
    }
    else {
        result = sortedArr[size / 2];
    }

    return result;
    delete[] sortedArr;
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr1[] = { 5, 2, 8, 1, 9 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Медиана [5, 2, 8, 1, 9]: " << median(arr1, size1) << endl;

    int arr2[] = { 4, 1, 3, 2 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Медиана [4, 1, 3, 2]: " << median(arr2, size2) << endl;

    return 0;
}
