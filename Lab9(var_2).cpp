#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T, int Size>
class CircularBuffer {
private:
    T data[Size]; // Хранилище данных
    int head; // Индекс следующего места для записи
    int count; // Количество элементов в буфере
public:
    CircularBuffer() : head(0), count(0) {}

    void add(const T& value) {
        data[head] = value;
        head = (head + 1) % Size;
        if (count < Size) count++;
    }

    void clear() {
        head = 0;
        count = 0;
    }

    string toString() const {
        stringstream ss;
        for (auto i = 0; i < count; i++) {
            auto index = (head - count + i + Size) % Size;
            ss << data[index] << " ";
        }
        return ss.str();
    }

    friend ostream& operator<<(ostream& out, const CircularBuffer& buf) {
        for (auto i = 0; i < buf.count; i++) {
            auto index = (buf.head - buf.count + i + Size) % Size;
            out << buf.data[index] << " ";
        }
        return out;
    }

    friend istream& operator>>(istream& in, CircularBuffer& buf) {
        int n;
        cout << "Сколько элементов добавить (не больше " << Size << "): ";
        in >> n;
        if (n > Size) n = Size;
        for (auto i = 0; i < n; i++) {
            T value{};
            cout << "Введите элемент " << i + 1 << ": ";
            in >> value;
            buf.add(value);
        }
        return in;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    
    CircularBuffer<int, 5> intBuf;
    cout << "=== Ввод значений для буфера int ===" << endl;
    cin >> intBuf;
    cout << "\nСодержимое буфера: " << intBuf << endl;
    cout << "toString(): " << intBuf.toString().c_str() << endl;
    
    cout << "\nДобавляем еще 3 элемента (перезапишет старые):" << endl;
    intBuf.add(100);
    intBuf.add(200);
    intBuf.add(300);
    cout << "Буфер после добавления: " << intBuf << endl;
    
    cout << "\nОчищаем буфер..." << endl;
    intBuf.clear();
    cout << "Буфер после очистки: " << intBuf << endl;
    
    CircularBuffer<double, 4> dblBuf;
    cout << "\n=== Ввод значений для буфера double ===" << endl;
    cin >> dblBuf;
    cout << "Содержимое буфера double: " << dblBuf << endl;
    return 0;
}
