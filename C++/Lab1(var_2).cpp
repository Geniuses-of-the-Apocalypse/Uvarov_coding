#include <iostream>
#include <cmath>

using namespace std;

struct Pair {
    double first;
    double second;
    
    void init(double a, double b);
    void read();
    void display();
    double power();
};

void Pair::init(double a, double b) {
    if (a == 0 && b <= 0) {
        cout << "Ошибка: ноль нельзя возводить в неположительную степень!" << endl;
        cout << "Значения по умолчанию (1, 1)" << endl;
        first = 1;
        second = 1;
        return;
    }
    first = a;
    second = b;
}

void Pair::read() {
    double a, b;
    cout << "Введите дробное число (основание): ";
    cin >> a;
    cout << "Введите дробное число (показатель): ";
    cin >> b;
    init(a, b);
}

void Pair::display() {
    cout << "first = " << first << ", second = " << second;
}

double Pair::power() {
    if (first == 0 && second <= 0) {
        cout << "Ошибка вычисления: ноль нельзя возводить в неположительную степень!" << endl;
        return 0;
    }
    return pow(first, second);
}

Pair make_Pair(double a, double b) {
    if (a == 0 && b <= 0) {
        cout << "Ошибка: 0 нельзя возводить в неположительную степень!" << endl;
        cout << "Объекта с значениями по умолчанию (1, 1)" << endl;
        Pair p;
        p.init(1, 1);
        return p;
    }
    Pair p;
    p.init(a, b);
    return p;
}

int main() {
    cout << "=== Лабораторная работа №1. Структура-пара ===\n" << endl;

    cout << "=== 1. Статический объект ===" << endl;
    Pair p1;
    p1.init(2.5, 3.7);
    p1.display();
    cout << "\nРезультат возведения в степень: " << p1.power() << endl;

    cout << "\n=== 2. Ввод с клавиатуры ===" << endl;
    Pair p2;
    p2.read();
    p2.display();
    cout << "\nРезультат возведения в степень: " << p2.power() << endl;

    cout << "\n=== 3. Внешняя функция make_Pair ===" << endl;
    Pair p3 = make_Pair(5.0, -2.8);
    p3.display();
    cout << "\nРезультат возведения в степень: " << p3.power() << endl;

    cout << "\n=== 4. Массив объектов ===" << endl;
    Pair arr[3];
    
    arr[0].init(4.0, 0.5);
    arr[1].init(0.0, 3.0);
    arr[2].init(8.0, 1.0/3.0);
    
    for (int i = 0; i < 3; i++) {
        cout << "\nОбъект " << i + 1 << ": ";
        arr[i].display();
        cout << "\nРезультат возведения в степень: " << arr[i].power() << endl;
    }

    cout << "\n=== 5. Динамический объект ===" << endl;
    Pair* p4 = new Pair;
    p4->init(10, -3.9);
    p4->display();
    cout << "\nРезультат возведения в степень: " << p4->power() << endl;
    delete p4;

    cout << "\n=== 6. Демонстрация обработки ошибок ===" << endl;
    
    cout << "Попытка создать объект с (0, -2):" << endl;
    Pair p5;
    p5.init(0, -2);
    p5.display();
    cout << "\nРезультат возведения в степень: " << p5.power() << endl;
    
    cout << "\nПопытка создать через make_Pair(0, 0):" << endl;
    Pair p6 = make_Pair(0, 0);
    p6.display();
    cout << "\nРезультат возведения в степень: " << p6.power() << endl;

    cout << "\n=== 7. Демонстрация различных случаев ===" << endl;
    
    Pair case1 = make_Pair(0.0, 5.0);
    cout << "Ноль в положительной степени: ";
    case1.display();
    cout << " = " << case1.power() << endl;
    
    Pair case2 = make_Pair(1.0, 100.0);
    cout << "Единица в любой степени: ";
    case2.display();
    cout << " = " << case2.power() << endl;
    
    Pair case3 = make_Pair(-8.0, 1.0/3.0);
    cout << "Отрицательное основание в дробной степени: ";
    case3.display();
    cout << " = " << case3.power() << endl;
    
    Pair case4 = make_Pair(16.0, 0.25);
    cout << "Дробная степень: ";
    case4.display();
    cout << " = " << case4.power() << endl;

    return 0;
}
