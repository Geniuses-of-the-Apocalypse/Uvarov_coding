#include <iostream>
#include <cmath>

using namespace std;

class vector3D {
private:
    double x, y, z;

public:
    // Конструкторы
    vector3D(); // Конструктор без аргументов
    vector3D(double x_val, double y_val, double z_val); // Конструктор инициализации
    vector3D(const vector3D& other); // Конструктор копирования
    
    // Методы
    void read();
    void display();
    string toString();
    
    // Математические операции
    vector3D add(vector3D other);
    vector3D subtract(vector3D other);
    double dotProduct(vector3D other);
    vector3D multiplyByScalar(double scalar);
    bool areEqual(vector3D other);
    double length();
    int compareLength(vector3D other);
    
    // Геттеры для доступа к координатам
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }
};

// Реализация конструкторов
vector3D::vector3D() {
    x = 0;
    y = 0;
    z = 0;
}

vector3D::vector3D(double x_val, double y_val, double z_val) {
    x = x_val;
    y = y_val;
    z = z_val;
}

vector3D::vector3D(const vector3D& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

// Реализация методов
void vector3D::read() {
    cout << "Введите координату x: ";
    cin >> x;
    cout << "Введите координату y: ";
    cin >> y;
    cout << "Введите координату z: ";
    cin >> z;
}

void vector3D::display() {
    cout << "(" << x << ", " << y << ", " << z << ")";
}

string vector3D::toString() {
    return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
}

vector3D vector3D::add(vector3D other) {
    return vector3D(x + other.x, y + other.y, z + other.z);
}

vector3D vector3D::subtract(vector3D other) {
    return vector3D(x - other.x, y - other.y, z - other.z);
}

double vector3D::dotProduct(vector3D other) {
    return x * other.x + y * other.y + z * other.z;
}

vector3D vector3D::multiplyByScalar(double scalar) {
    return vector3D(x * scalar, y * scalar, z * scalar);
}

bool vector3D::areEqual(vector3D other) {
    return x == other.x && y == other.y && z == other.z;
}

double vector3D::length() {
    return sqrt(x * x + y * y + z * z);
}

int vector3D::compareLength(vector3D other) {
    double len1 = length();
    double len2 = other.length();
    if (abs(len1 - len2) < 1e-10) return 0;
    return (len1 > len2) ? 1 : -1;
}

int main() {
    cout << "Лабораторная работа №1. Конструкторы" << endl;
    cout << "Класс vector3D\n" << endl;
    
    // Демонстрация различных способов создания объектов
    cout << "=== РАЗЛИЧНЫЕ СПОСОБЫ СОЗДАНИЯ ОБЪЕКТОВ ===" << endl;
    
    // 1. Конструктор без аргументов
    cout << "1. Конструктор без аргументов:" << endl;
    vector3D v1;
    cout << "v1 = ";
    v1.display();
    cout << endl;
    
    // 2. Конструктор инициализации
    cout << "\n2. Конструктор инициализации:" << endl;
    vector3D v2(1.0, 2.0, 3.0);
    cout << "v2 = ";
    v2.display();
    cout << endl;
    
    vector3D v3(4.5, -2.1, 0.8);
    cout << "v3 = ";
    v3.display();
    cout << endl;
    
    // 3. Конструктор копирования
    cout << "\n3. Конструктор копирования:" << endl;
    vector3D v4(v2);
    cout << "v4 (копия v2) = ";
    v4.display();
    cout << endl;
    
    // 4. Создание с помощью ввода с клавиатуры
    cout << "\n4. Ввод с клавиатуры:" << endl;
    vector3D v5;
    cout << "Введите координаты для v5:" << endl;
    v5.read();
    cout << "v5 = ";
    v5.display();
    cout << endl;
    
    // Демонстрация работы с массивом объектов
    cout << "\n=== МАССИВ ОБЪЕКТОВ ===" << endl;
    vector3D arr[3];
    
    // Инициализация элементов массива разными способами
    arr[0] = vector3D(); // конструктор без аргументов
    arr[1] = vector3D(1.0, 0.0, 0.0); // единичный вектор по x
    arr[2] = vector3D(0.0, 1.0, 0.0); // единичный вектор по y
    
    cout << "Массив векторов:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = ";
        arr[i].display();
        cout << ", длина = " << arr[i].length() << endl;
    }
    
    // Демонстрация всех математических операций
    cout << "\n=== МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ ===" << endl;
    
    vector3D a(1, 2, 3);
    vector3D b(4, 5, 6);
    
    cout << "Вектор a = ";
    a.display();
    cout << endl;
    
    cout << "Вектор b = ";
    b.display();
    cout << endl;
    
    // Сложение
    vector3D sum = a.add(b);
    cout << "a + b = ";
    sum.display();
    cout << endl;
    
    // Вычитание
    vector3D diff = a.subtract(b);
    cout << "a - b = ";
    diff.display();
    cout << endl;
    
    // Скалярное произведение
    double dot = a.dotProduct(b);
    cout << "a · b = " << dot << endl;
    
    // Умножение на скаляр
    vector3D scaled = a.multiplyByScalar(2.5);
    cout << "a * 2.5 = ";
    scaled.display();
    cout << endl;
    
    // Сравнение векторов
    cout << "a == b: " << (a.areEqual(b) ? "Да" : "Нет") << endl;
    
    vector3D a_copy(a);
    cout << "a == a_copy: " << (a.areEqual(a_copy) ? "Да" : "Нет") << endl;
    
    // Длины векторов
    cout << "Длина a: " << a.length() << endl;
    cout << "Длина b: " << b.length() << endl;
    
    // Сравнение длин
    int cmp = a.compareLength(b);
    if (cmp == 0) {
        cout << "Длины векторов a и b равны" << endl;
    } else if (cmp > 0) {
        cout << "Длина вектора a больше длины вектора b" << endl;
    } else {
        cout << "Длина вектора a меньше длины вектора b" << endl;
    }
    
    // Демонстрация toString
    cout << "\n=== МЕТОД toString ===" << endl;
    cout << "a как строка: " << a.toString() << endl;
    cout << "b как строка: " << b.toString() << endl;

    return 0;
}
