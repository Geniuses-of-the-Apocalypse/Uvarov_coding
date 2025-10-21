#include <iostream>
#include <stdexcept>
using namespace std;

// Базовый класс Array
class Array {
protected:
    static const int MAX_SIZE = 256;
    unsigned char* data;
    int size;

public:
    Array() : data(nullptr), size(0) {}
    
    Array(int n, unsigned char value = 0) : size(n) {
        if (n < 0) {
            throw invalid_argument("Неверный размер");
        }
        if (n > MAX_SIZE) {
            throw invalid_argument("Неверный размер");
        }
        data = new unsigned char[size];
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }
    
    // Конструктор копирования
    Array(const Array& other) : size(other.size) {
        data = new unsigned char[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    virtual ~Array() { delete[] data; }
    
    int getSize() const { return size; }
    
    // Оператор индексирования с проверкой границ
    unsigned char& operator[](int index) {
        if (index < 0) {
            throw out_of_range("Индекс за границами");
        }
        if (index >= size) {
            throw out_of_range("Индекс за границами");
        }
        return data[index];
    }
    
    // Виртуальный метод сложения массивов
    virtual Array* add(const Array& other) const {
        int newSize;
        if (size > other.size) {
            newSize = size;
        } else {
            newSize = other.size;
        }
        
        Array* result = new Array(newSize);
        for (int i = 0; i < newSize; i++) {
            unsigned char val1;
            if (i < size) {
                val1 = data[i];
            } else {
                val1 = 0;
            }
            
            unsigned char val2;
            if (i < other.size) {
                val2 = other.data[i];
            } else {
                val2 = 0;
            }
            
            (*result)[i] = val1 + val2;
        }
        return result;
    }
    
    virtual void print(ostream& os) const {
        os << "[";
        for (int i = 0; i < size; i++) {
            os << (int)data[i];
            if (i < size - 1) {
                os << ", ";
            }
        }
        os << "]";
    }
};

// Перегрузка оператора вывода для Array
ostream& operator<<(ostream& os, const Array& arr) {
    arr.print(os);
    return os;
}

// Класс Fraction для работы с дробными числами
class Fraction : public Array {
private:
    int digits;  // количество цифр в дробной части
    bool sign;   // знак числа

public:
    Fraction() : Array(), digits(2), sign(true) {}
    
    Fraction(int places, bool positive = true, unsigned char value = 0) 
        : Array(places, value), digits(places), sign(positive) {}
    
    // Переопределение виртуального метода сложения для дробей
    virtual Array* add(const Array& other) const override {
        // Проверка типа с помощью dynamic_cast
        const Fraction* otherFraction = dynamic_cast<const Fraction*>(&other);
        if (!otherFraction) {
            throw invalid_argument("Только дроби с дробями");
        }
        
        // Используем максимальное количество цифр
        int maxDigits;
        if (digits > otherFraction->digits) {
            maxDigits = digits;
        } else {
            maxDigits = otherFraction->digits;
        }
        
        Fraction* result = new Fraction(maxDigits);
        
        // Поэлементное сложение цифр
        for (int i = 0; i < maxDigits; i++) {
            unsigned char val1;
            if (i < size) {
                val1 = data[i];
            } else {
                val1 = 0;
            }
            
            unsigned char val2;
            if (i < otherFraction->size) {
                val2 = otherFraction->data[i];
            } else {
                val2 = 0;
            }
            
            (*result)[i] = val1 + val2;
        }
        
        if (sign == otherFraction->sign) {
            result->sign = sign;
        } else {
            result->sign = true;
        }
        return result;
    }
    
    virtual void print(ostream& os) const override {
        if (sign) {
            os << "+";
        } else {
            os << "-";
        }
        os << "0.";
        for (int i = 0; i < size; i++) {
            os << (int)data[i];
        }
    }
};

// Класс BitString для работы с битовыми строками
class BitString : public Array {
public:
    BitString() : Array() {}
    
    BitString(int bits, unsigned char value = 0) : Array(bits, value) {
        // Гарантируем что значения только 0 или 1
        for (int i = 0; i < size; i++) {
            if (data[i] != 0) {
                data[i] = 1;
            } else {
                data[i] = 0;
            }
        }
    }
    
    // Переопределение виртуального метода сложения для битовых строк
    virtual Array* add(const Array& other) const override {
        const BitString* otherBitString = dynamic_cast<const BitString*>(&other);
        if (!otherBitString) {
            throw invalid_argument("Только биты с битами");
        }

        int maxBits;
        if (size > otherBitString->size) {
            maxBits = size;
        } else {
            maxBits = otherBitString->size;
        }
        
        BitString* result = new BitString(maxBits);
        
        // Побитовое ИЛИ
        for (int i = 0; i < maxBits; i++) {
            bool bit1;
            if (i < size) {
                bit1 = (data[i] != 0);
            } else {
                bit1 = false;
            }
            
            bool bit2;
            if (i < otherBitString->size) {
                bit2 = (otherBitString->data[i] != 0);
            } else {
                bit2 = false;
            }
            
            if (bit1 || bit2) {
                (*result)[i] = 1;
            } else {
                (*result)[i] = 0;
            }
        }
        
        return result;
    }
    
    virtual void print(ostream& os) const override {
        os << "b\"";
        // Выводим биты от старшего к младшему
        for (int i = size - 1; i >= 0; i--) {
            if (data[i]) {
                os << '1';
            } else {
                os << '0';
            }
        }
        os << "\"";
    }
};

// Главная функция
int main() {
    cout << "Лабораторная №2: Виртуальные методы\n" << endl;

    // Создаем объекты разных типов
    Array arr(3, 5);
    Fraction frac1(3, true, 1);  // +0.111
    Fraction frac2(2, true, 2);  // +0.22
    BitString bits1(4, 1);       // 1111
    BitString bits2(3, 1);       // 111

    cout << "Объекты созданы:" << endl;
    cout << "Массив: " << arr << endl;
    cout << "Дробь 1: " << frac1 << endl;
    cout << "Дробь 2: " << frac2 << endl;
    cout << "Биты 1: " << bits1 << endl;
    cout << "Биты 2: " << bits2 << endl;

    // Демонстрация сложения через виртуальные методы
    cout << "\nСложение:" << endl;
    Array* sum1 = frac1.add(frac2);
    cout << "Дроби: " << frac1 << " + " << frac2 << " = " << *sum1 << endl;
    delete sum1;

    Array* sum2 = bits1.add(bits2);
    cout << "Биты: " << bits1 << " + " << bits2 << " = " << *sum2 << endl;
    delete sum2;

    // Демонстрация работы оператора []
    cout << "\nОператор []:" << endl;
    cout << "frac1[0] = " << (int)frac1[0] << endl;
    frac1[0] = 9;
    cout << "После frac1[0] = 9: " << frac1 << endl;

    // Демонстрация полиморфизма через указатели базового класса
    cout << "\nПолиморфизм:" << endl;
    Array* objects[] = { &frac1, &bits1 };
    cout << "Через Array*: " << *objects[0] << endl;
    cout << "Через Array*: " << *objects[1] << endl;

    // Обработка ошибок
    cout << "\nОбработка ошибок:" << endl;
    try {
        frac1[10] = 5;  // выход за границы массива
    } catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        frac1.add(bits1);  // попытка сложить разные типы
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    cout << "\nПрограмма завершена!" << endl;
    return 0;
}
