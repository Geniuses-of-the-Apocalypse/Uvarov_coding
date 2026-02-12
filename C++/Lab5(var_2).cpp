/*2.	Создать класс Pair (пара чисел); определить методы изменения полей и сравнения пар: пара p1 больше пары р2,
если (first.pl > first.р2) или (first.pl =first.р2) и (second.pl > second.р2). Определить класс-наследник Fraction с полями: 
целая часть числа и дробная часть числа. Определить полный набор методов сравнения.*/

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
    Pair() : first(0.0), second(0.0) {}
    
    // Конструктор с параметрами
    Pair(double f, double s) : first(f), second(s) {
        if (f < 0 || s < 0) {
            cout << "Ошибка: значения не могут быть отрицательными!" << endl;
            exit(1);
        }
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
    int iPart;
    double fPart;
public:
    // Конструктор без параметров
    Fraction() : Pair(), iPart(0), fPart(0.0) {}
    // Конструктор с параметрами
    Fraction(int i, double f) : Pair(i, f), iPart(i), fPart(f) {
        if (i < 0 || f < 0) {
            cout << "Ошибка: значения не могут быть отрицательными!" << endl;
            exit(1);
        }
    }
    // Методы установки
    void setIPart(int i) {
        if (i < 0) {
            cout << "Ошибка: недопустимое значение integerPart!" << endl;
            exit(1);
        }
        iPart = i;
    }
    void setFPart(double f) {
        if (f < 0) {
            cout << "Ошибка: недопустимое значение fractionalPart!" << endl;
            exit(1);
        }
        fPart = f;
    }
    // Методы получения
    int getIPart() { return iPart; }
    double getFPart() { return fPart; }
    // Полный набор сравнений
    bool operator>(Fraction &f) {
        if (iPart > f.iPart)
            return true;
        if (iPart == f.iPart && fPart > f.fPart)
            return true;
        return false;
    }
    bool operator<(Fraction &f) {
        if (iPart < f.iPart)
            return true;
        if (iPart == f.iPart && fPart < f.fPart)
            return true;
        return false;
    }
    bool operator==(Fraction &f) {
        return iPart == f.iPart && fPart == f.fPart;
    }
    bool operator!=(Fraction &f) {
        return !(*this == f);
    }
    // Преобразование в строку
    string toString() {
        return "[" + to_string(iPart) + " + " + to_string(fPart) + "]";
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
    bool result1 = p1 > p2;
    bool result2 = p1 < p2;
    bool result3 = f1 > f2;
    bool result4 = f1 < f2;
    
    cout << "p1 > p2: ";
    if (result1) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    cout << "p1 < p2: ";
    if (result2) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    cout << "f1 > f2: ";
    if (result3) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    cout << "f1 < f2: ";
    if (result4) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
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
