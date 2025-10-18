#include <iostream>
#include <string>
using namespace std;

// ===== Класс Pair =====
class Pair {
protected:
    double first;
    double second;
public:
    // Конструктор без параметров
    Pair() {
        first = 0;
        second = 0;
    }
    // Конструктор с параметрами
    Pair(double f, double s) {
        if (f < 0 || s < 0) {
            cout << "Ошибка: значения не могут быть отрицательными!" << endl;
            exit(1);
        }
        first = f;
        second = s;
    }
    // Методы установки
    void setFirst(double f) {
        if (f < 0) {
            cout << "Ошибка: недопустимое значение first!" << endl;
            exit(1);
        }
        first = f;
    }
    void setSecond(double s) {
        if (s < 0) {
            cout << "Ошибка: недопустимое значение second!" << endl;
            exit(1);
        }
        second = s;
    }
    // Методы получения
    double getFirst() { return first; }
    double getSecond() { return second; }
    // Методы сравнения
    bool operator>(Pair &p) {
        return (first > p.first) || ((first == p.first) && (second > p.second));
    }
    bool operator<(Pair &p) {
        return (first < p.first) || ((first == p.first) && (second < p.second));
    }
    bool operator==(Pair &p) {
        return (first == p.first) && (second == p.second);
    }
    bool operator!=(Pair &p) {
        return !(*this == p);
    }
    // Преобразование в строку
    string toString() {
        return "(" + to_string(first) + ", " + to_string(second) + ")";
    }
    // Метод вывода
    void print() {
        cout << toString() << endl;
    }
};

// ===== Класс-наследник Fraction =====
class Fraction : public Pair {
private:
    int integerPart;
    double fractionalPart;
public:
    // Конструктор без параметров
    Fraction() : Pair() {
        integerPart = 0;
        fractionalPart = 0.0;
    }
    // Конструктор с параметрами
    Fraction(int i, double f) : Pair(i, f) {
        if (i < 0 || f < 0) {
            cout << "Ошибка: значения не могут быть отрицательными!" << endl;
            exit(1);
        }
        integerPart = i;
        fractionalPart = f;
    }
    // Методы установки
    void setIntegerPart(int i) {
        if (i < 0) {
            cout << "Ошибка: недопустимое значение integerPart!" << endl;
            exit(1);
        }
        integerPart = i;
    }
    void setFractionalPart(double f) {
        if (f < 0) {
            cout << "Ошибка: недопустимое значение fractionalPart!" << endl;
            exit(1);
        }
        fractionalPart = f;
    }
    // Методы получения
    int getIntegerPart() { return integerPart; }
    double getFractionalPart() { return fractionalPart; }
    // Полный набор сравнений
    bool operator>(Fraction &f) {
        if (integerPart > f.integerPart)
            return true;
        if (integerPart == f.integerPart && fractionalPart > f.fractionalPart)
            return true;
        return false;
    }
    bool operator<(Fraction &f) {
        if (integerPart < f.integerPart)
            return true;
        if (integerPart == f.integerPart && fractionalPart < f.fractionalPart)
            return true;
        return false;
    }
    bool operator==(Fraction &f) {
        return integerPart == f.integerPart && fractionalPart == f.fractionalPart;
    }
    bool operator!=(Fraction &f) {
        return !(*this == f);
    }
    // Преобразование в строку
    string toString() {
        return "[" + to_string(integerPart) + " + " + to_string(fractionalPart) + "]";
    }
    // Вывод
    void print() {
        cout << toString() << endl;
    }
};

// ===== Главная функция =====
int main() {
    cout << "Лабораторная работа №1. Наследование" << endl;
    
    // Создание объектов Pair
    cout << "\n=== Создание объектов Pair ===" << endl;
    Pair p1(2.5, 3.7);
    Pair p2(2.5, 2.8);
    cout << "p1 = "; p1.print();
    cout << "p2 = "; p2.print();
    
    // Создание объектов Fraction
    cout << "\n=== Создание объектов Fraction ===" << endl;
    Fraction f1(3, 0.5);
    Fraction f2(3, 0.3);
    cout << "f1 = "; f1.print();
    cout << "f2 = "; f2.print();
    
    // Демонстрация сравнения
    cout << "\n=== Сравнение объектов ===" << endl;
    cout << "p1 > p2: " << (p1 > p2 ? "true" : "false") << endl;
    cout << "p1 < p2: " << (p1 < p2 ? "true" : "false") << endl;
    cout << "f1 > f2: " << (f1 > f2 ? "true" : "false") << endl;
    cout << "f1 < f2: " << (f1 < f2 ? "true" : "false") << endl;
    
    // Демонстрация принципа подстановки
    cout << "\n=== Принцип подстановки ===" << endl;
    Pair* basePtr = &f1;
    cout << "Pair* указатель на Fraction: " << basePtr->toString() << endl;
    
    // Массивы объектов
    cout << "\n=== Массивы объектов ===" << endl;
    Pair pairs[2] = {Pair(1, 2), Pair(3, 4)};
    Fraction fractions[2] = {Fraction(2, 0.1), Fraction(2, 0.9)};
    
    cout << "Массив Pair: ";
    for (int i = 0; i < 2; i++) {
        pairs[i].print();
    }
    
    cout << "Массив Fraction: ";
    for (int i = 0; i < 2; i++) {
        fractions[i].print();
    }
    
    cout << "\nПрограмма завершена успешно!" << endl;
    return 0;
}
