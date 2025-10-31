/* 2. Создать класс Money (Класс для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей
и типа unsigned char - для копеек.) и класс BitString (Класс для работы с битовыми строками не более чем из 100 бит.
Битовая строка должна быть представлена массивом типа unsigned char, каждый элемент которого принимает значение 0 или 1.).*/
#include <iostream>
using namespace std;
// -----------------------------
// Абстрактный базовый класс
// -----------------------------
class Base {
public:
    virtual void Input() = 0;
    virtual void Output() = 0;
    virtual ~Base() {}
};
// -----------------------------
// Класс BitString — битовая строка
// -----------------------------
class BitString : public Base {
protected:
    unsigned char bits[100]; // массив бит
    int length; // длина строки
public:
    BitString() { length = 0; for(int i=0;i<100;i++) bits[i]=0; }
    void Input() override {
        cout << "\n--- Ввод BitString ---\n";
        do {
            cout << "Длина строки (1-100): ";
            cin >> length;
        } while (length < 1 || length > 100);
        cin.ignore(10000, '\n'); // очищаем буфер перед вводом битов
        cout << "Введите биты (0 или 1) по одному:\n";
        for (int i = 0; i < length; i++) {
            int v;
            while (true) {
                cout << "Бит " << i + 1 << ": ";
                cin >> v;
                if (v == 0 || v == 1) break;
                cout << "Ошибка! Введите 0 или 1.\n";
            }
            bits[i] = v;
        }
    }
    void Output() override {
        cout << "\n--- Вывод BitString ---\n";
        for (int i = 0; i < length; i++) cout << (int)bits[i];
        cout << endl;
    }
};
// -----------------------------
// Класс Money — работа с денежными суммами
// -----------------------------
class Money : public Base {
protected:
    long rub; // рубли
    unsigned char kop; // копейки (0–99)
    void normalize(long k) { // нормализация копеек
        if (k < 0) k = 0;
        rub += k / 100;
        kop = k % 100;
    }
public:
    Money() { rub = 0; kop = 0; }
    void Input() override {
        cout << "\n--- Ввод Money ---\n";
        cout << "Введите рубли: "; cin >> rub;
        int k;
        cout << "Введите копейки: "; cin >> k;
        normalize(k);
    }
    void Output() override {
        cout << "\n--- Вывод Money ---\n";
        cout << rub << " руб. " << (int)kop << " коп." << endl;
    }
};
// -----------------------------
// Главная функция
// -----------------------------
int main() {
    Base* ptr;
    // Демонстрация BitString
    BitString B;
    ptr = &B;
    ptr->Input();
    ptr->Output();
    // Демонстрация Money
    Money M;
    ptr = &M;
    ptr->Input();
    ptr->Output();
    return 0;
}
