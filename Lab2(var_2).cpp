#include <iostream>
#include <cmath>

using namespace std;

// Структура vector3D
struct vector3D {
    double x, y, z;
    
    // Методы для структуры
    void init(double x_val, double y_val, double z_val);
    void read();
    void display();
    string toString();
};

// Реализация методов структуры
void vector3D::init(double x_val, double y_val, double z_val) {
    x = x_val;
    y = y_val;
    z = z_val;
}

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
    string result = "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
    return result;
}

// Внешние функции для операций с векторами
vector3D add(vector3D v1, vector3D v2) {
    vector3D result;
    result.init(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    return result;
}

vector3D subtract(vector3D v1, vector3D v2) {
    vector3D result;
    result.init(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    return result;
}

double dotProduct(vector3D v1, vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vector3D multiplyByScalar(vector3D v, double scalar) {
    vector3D result;
    result.init(v.x * scalar, v.y * scalar, v.z * scalar);
    return result;
}

bool areEqual(vector3D v1, vector3D v2) {
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

double length(vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

int compareLength(vector3D v1, vector3D v2) {
    double len1 = length(v1);
    double len2 = length(v2);
    if (abs(len1 - len2) < 1e-10) return 0;
    return (len1 > len2) ? 1 : -1;
}

// Демонстрация работы со структурой
int main() {
    cout << "Лабораторная работа № 2. Структуры и классы" << endl;
    cout << "Класс vector3D\n" << endl;
    
    cout << "=== РАБОТА СО СТРУКТУРОЙ ===" << endl;
    
    vector3D v1, v2;
    
    cout << "Введите первый вектор:" << endl;
    v1.read();
    
    cout << "Введите второй вектор:" << endl;
    v2.read();
    
    cout << "\nРезультаты операций:" << endl;
    cout << "Вектор 1: ";
    v1.display();
    cout << endl;
    
    cout << "Вектор 2: ";
    v2.display();
    cout << endl;
    
    vector3D sum = add(v1, v2);
    cout << "Сумма: ";
    sum.display();
    cout << endl;
    
    vector3D diff = subtract(v1, v2);
    cout << "Разность: ";
    diff.display();
    cout << endl;
    
    double dot = dotProduct(v1, v2);
    cout << "Скалярное произведение: " << dot << endl;
    
    vector3D scaled = multiplyByScalar(v1, 2.5);
    cout << "Вектор 1 умноженный на 2.5: ";
    scaled.display();
    cout << endl;
    
    cout << "Векторы равны: " << (areEqual(v1, v2) ? "Да" : "Нет") << endl;
    
    cout << "Длина вектора 1: " << length(v1) << endl;
    cout << "Длина вектора 2: " << length(v2) << endl;
    
    int cmp = compareLength(v1, v2);
    if (cmp == 0) {
        cout << "Длины векторов равны" << endl;
    } else if (cmp > 0) {
        cout << "Длина вектора 1 больше" << endl;
    } else {
        cout << "Длина вектора 2 больше" << endl;
    }
    
    // Демонстрация toString
    cout << "\nДемонстрация метода toString:" << endl;
    cout << "Вектор 1 как строка: " << v1.toString() << endl;
    cout << "Вектор 2 как строка: " << v2.toString() << endl;

    return 0;
}
