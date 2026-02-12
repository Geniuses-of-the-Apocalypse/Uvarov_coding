/* 2. Создать класс Money (Класс для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей
и типа unsigned char - для копеек.) и класс BitString (Класс для работы с битовыми строками не более чем из 100 бит.
Битовая строка должна быть представлена массивом типа unsigned char, каждый элемент которого принимает значение 0 или 1.).*/

#include <iostream>
using namespace std;

// -----------------------------
// Класс BitString — битовая строка
// -----------------------------
class BitString {
protected:
    unsigned char bits[100]; // массив бит
    int length; // длина строки
    
public:
    BitString() { 
        length = 0; 
        for(int i = 0; i < 100; i++) 
            bits[i] = 0; 
    }
    
    // Методы для получения длины
    int getLength() const { return length; }
    
    // Дружественные функции для операторов ввода/вывода
    friend istream& operator>>(istream& in, BitString& bs);
    friend ostream& operator<<(ostream& out, const BitString& bs);
};

// Оператор ввода для BitString
istream& operator>>(istream& in, BitString& bs) {
    cout << "\n--- Ввод BitString ---\n";
    do {
        cout << "Длина строки (1-100): ";
        in >> bs.length;
    } while (bs.length < 1 || bs.length > 100);
    
    in.ignore(10000, '\n');
    cout << "Введите биты (0 или 1) по одному:\n";
    for (int i = 0; i < bs.length; i++) {
        int v;
        while (true) {
            cout << "Бит " << i + 1 << ": ";
            in >> v;
            if (v == 0 || v == 1) break;
            cout << "Ошибка! Введите 0 или 1.\n";
        }
        bs.bits[i] = v;
    }
    return in;
}

// Оператор вывода для BitString
ostream& operator<<(ostream& out, const BitString& bs) {
    out << "\n--- Вывод BitString ---\n";
    for (int i = 0; i < bs.length; i++) 
        out << (int)bs.bits[i];
    out << endl;
    return out;
}

// -----------------------------
// Класс Money — работа с денежными суммами
// -----------------------------
class Money {
protected:
    long rub; // рубли
    unsigned char kop; // копейки (0–99)
    
public:
    Money() { 
        rub = 0; 
        kop = 0; 
    }
    
    // Методы для получения значений
    long getRubles() const { return rub; }
    unsigned char getKopecks() const { return kop; }
    
    // Дружественные функции для операторов ввода/вывода
    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};

// Оператор ввода для Money
istream& operator>>(istream& in, Money& m) {
    cout << "\n--- Ввод Money ---\n";
    cout << "Введите рубли: "; 
    in >> m.rub;
    int k;
    cout << "Введите копейки: "; 
    in >> k;
    
    if (k < 0) k = 0;
    m.rub += k / 100;
    m.kop = k % 100;
    
    return in;
}

// Оператор вывода для Money
ostream& operator<<(ostream& out, const Money& m) {
    out << "\n--- Вывод Money ---\n";
    out << m.rub << " руб. " << (int)m.kop << " коп." << endl;
    return out;
}

// -----------------------------
// Главная функция
// -----------------------------
int main() {
    cout << "=== Работа с BitString ===" << endl;
    
    // Демонстрация BitString через операторы
    BitString B;
    cin >> B;
    cout << B;
    
    cout << "\n=== Работа с Money ===" << endl;
    
    // Демонстрация Money через операторы
    Money M;
    cin >> M;
    cout << M;
    
    return 0;
}
