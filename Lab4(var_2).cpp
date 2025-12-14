#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class vector3D {
private:
    double x, y, z;

public:
    // Конструкторы
    vector3D() : x(0), y(0), z(0) {}
    vector3D(double a, double b, double c) : x(a), y(b), z(c) {}
    vector3D(const vector3D& other) : x(other.x), y(other.y), z(other.z) {}
    
    // Метод toString для строкового представления
    string toString() const;
    
    // Математические операции через перегрузку операторов
    vector3D operator+(const vector3D& other) const;
    vector3D operator-(const vector3D& other) const;
    double operator*(const vector3D& other) const; // скалярное произведение
    vector3D operator*(double scalar) const; // умножение на скаляр
    
    // Операции сравнения
    bool operator==(const vector3D& other) const;
    bool operator!=(const vector3D& other) const;
    bool operator>(const vector3D& other) const; // сравнение длин
    bool operator<(const vector3D& other) const; // сравнение длин
    bool operator>=(const vector3D& other) const; // сравнение длин
    bool operator<=(const vector3D& other) const; // сравнение длин
    
    // Вычисление длины вектора
    double length() const;
    
    // Геттеры
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    
    // Дружественные функции для ввода-вывода
    friend ostream& operator<<(ostream& os, const vector3D& vec);
    friend istream& operator>>(istream& is, vector3D& vec);
};

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const vector3D& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

// Перегрузка оператора ввода
istream& operator>>(istream& is, vector3D& vec) {
    cout << "Введите координату x: ";
    is >> vec.x;
    cout << "Введите координату y: ";
    is >> vec.y;
    cout << "Введите координату z: ";
    is >> vec.z;
    return is;
}

// Реализация методов
string vector3D::toString() const {
    return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
}

// Реализация перегруженных операций
vector3D vector3D::operator+(const vector3D& other) const {
    return vector3D(x + other.x, y + other.y, z + other.z);
}

vector3D vector3D::operator-(const vector3D& other) const {
    return vector3D(x - other.x, y - other.y, z - other.z);
}

double vector3D::operator*(const vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

vector3D vector3D::operator*(double scalar) const {
    return vector3D(x * scalar, y * scalar, z * scalar);
}

bool vector3D::operator==(const vector3D& other) const {
    return (x == other.x && y == other.y && z == other.z);
}

bool vector3D::operator!=(const vector3D& other) const {
    return !(*this == other);
}

bool vector3D::operator>(const vector3D& other) const {
    return this->length() > other.length();
}

bool vector3D::operator<(const vector3D& other) const {
    return this->length() < other.length();
}

bool vector3D::operator>=(const vector3D& other) const {
    return this->length() >= other.length();
}

bool vector3D::operator<=(const vector3D& other) const {
    return this->length() <= other.length();
}

double vector3D::length() const {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    cout << "Лабораторная работа №2. Перегрузка операций" << endl;
    cout << "Класс vector3D\n" << endl;
    
    // Создание объектов
    cout << "Вводим вектор a:" << endl;
    vector3D a;
    cin >> a;
    
    cout << "\nВводим вектор b:" << endl;
    vector3D b;
    cin >> b;
    
    vector3D c(b);
    
    cout << "\nВектор a = " << a << endl;
    cout << "Вектор b = " << b << endl;
    cout << "Вектор c (копия b) = " << c << endl;
    
    // Демонстрация операций
    cout << "\n=== МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ ===" << endl;
    
    vector3D sum = a + b;
    cout << "a + b = " << sum << endl;
    
    vector3D diff = a - b;
    cout << "a - b = " << diff << endl;
    
    double dot = a * b;
    cout << "a * b (скалярное произведение) = " << dot << endl;
    
    vector3D scaled = a * 2;
    cout << "a * 2 = " << scaled << endl;
    
    cout << "\nДлина a = " << a.length() << endl;
    cout << "Длина b = " << b.length() << endl;
    
    cout << "\n=== ОПЕРАЦИИ СРАВНЕНИЯ ===" << endl;
    cout << "a длиннее b? " << ((a > b) ? "Да" : "Нет") << endl;
    cout << "a короче b? " << ((a < b) ? "Да" : "Нет") << endl;
    cout << "a == b? " << ((a == b) ? "Да" : "Нет") << endl;
    cout << "a != b? " << ((a != b) ? "Да" : "Нет") << endl;
    
    // Статический массив
    cout << "\n=== СТАТИЧЕСКИЙ МАССИВ ===" << endl;
    cout << "Введите координаты для массива из 2 векторов:" << endl;
    vector3D arr[2];
    for (int i = 0; i < 2; i++) {
        cout << "\nВектор arr[" << i << "]:" << endl;
        cin >> arr[i];
    }
    
    cout << "\nСтатический массив:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    
    // Динамический массив
    cout << "\n=== ДИНАМИЧЕСКИЙ МАССИВ ===" << endl;
    int n;
    cout << "Введите количество векторов в динамическом массиве: ";
    cin >> n;
    vector3D* dynArr = new vector3D[n];
    for (int i = 0; i < n; i++) {
        cout << "\nВектор dynArr[" << i << "]:" << endl;
        cin >> dynArr[i];
    }
    
    cout << "\nДинамический массив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "dynArr[" << i << "] = " << dynArr[i] << endl;
    }
    delete[] dynArr;
    
    return 0;
}
