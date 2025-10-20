#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// 1. Собственные исключения

// 1.1 Пустой класс
class EmptyException {};

// 1.2 Независимый класс с полями
class CustomException {
private:
    string message;
    double a_val, b_val;
public:
    CustomException(const string& msg, double a, double b) 
        : message(msg), a_val(a), b_val(b) {}
    
    string getMessage() const { return message; }
    double getA() const { return a_val; }
    double getB() const { return b_val; }
};

// 1.3 Наследник от стандартного исключения
class MyMathException : public runtime_error {
private:
    double a_val, b_val;
public:
    MyMathException(const string& msg, double a, double b) 
        : runtime_error(msg), a_val(a), b_val(b) {}
    
    double getA() const { return a_val; }
    double getB() const { return b_val; }
};

// 2. Реализации функции решения уравнения

// 2.1 Без спецификации исключений
double solveEquation1(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            throw invalid_argument("Уравнение 0x + 0 = 0 имеет бесконечное количество решений");
        } else {
            throw invalid_argument("Уравнение 0x + " + to_string(b) + " = 0 не имеет решений");
        }
    }
    return -b / a;
}

// 2.2 С собственными исключениями
double solveEquation2(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            throw EmptyException();  // Пустой класс
        } else {
            throw CustomException("Уравнение не имеет решений", a, b);  // Независимый класс
        }
    }
    
    if (a == -1 && b > 1e100) {  // Примерная проверка больших чисел
        throw MyMathException("Возможное переполнение", a, b);
    }
    
    return -b / a;
}

// 3. Главная функция с обработкой исключений
int main() {
    cout << "Лабораторная работа №1: Исключения" << endl;
    cout << "Решение уравнения ax + b = 0" << endl << endl;
    
    // Тестовые случаи
    double test_cases[][2] = {
        {2, 4},     // нормальный случай: 2x + 4 = 0 -> x = -2
        {0, 5},     // нет решений: 0x + 5 = 0
        {0, 0},     // бесконечно решений: 0x + 0 = 0
        {-1, 10},   // нормальный случай: -x + 10 = 0 -> x = 10
        {3, 0}      // нормальный случай: 3x + 0 = 0 -> x = 0
    };
    
    const char* descriptions[] = {
        "2x + 4 = 0",
        "0x + 5 = 0", 
        "0x + 0 = 0",
        "-x + 10 = 0",
        "3x + 0 = 0"
    };
    
    // Демонстрация всех вариантов
    for (int variant = 1; variant <= 2; variant++) {
        cout << "=== Вариант " << variant << " ===" << endl;
        
        for (int i = 0; i < 5; i++) {
            double a = test_cases[i][0];
            double b = test_cases[i][1];
            
            cout << "Уравнение: " << descriptions[i] << " -> ";
            
            try {
                double result;
                
                if (variant == 1) {
                    result = solveEquation1(a, b);
                    cout << "x = " << result;
                } else {
                    result = solveEquation2(a, b);
                    cout << "x = " << result;
                }
                
            } 
            // Обработка стандартных исключений
            catch (const invalid_argument& e) {
                cout << "Ошибка (invalid_argument): " << e.what();
            }
            catch (const runtime_error& e) {
                cout << "Ошибка (runtime_error): " << e.what();
            }
            // Обработка собственных исключений
            catch (const EmptyException&) {
                cout << "Ошибка (EmptyException): Уравнение имеет бесконечное количество решений";
            }
            catch (const CustomException& e) {
                cout << "Ошибка (CustomException): " << e.getMessage() 
                     << " (a=" << e.getA() << ", b=" << e.getB() << ")";
            }
            catch (const MyMathException& e) {
                cout << "Ошибка (MyMathException): " << e.what()
                     << " (a=" << e.getA() << ", b=" << e.getB() << ")";
            }
            // Общий обработчик
            catch (...) {
                cout << "Неизвестная ошибка";
            }
            
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}
