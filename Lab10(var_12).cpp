#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class Graph {
private:
    T data[50];
    int count;

public:
    Graph() : count(0) {}

    // Поиск элемента
    bool find(const T& value) const {
        for (auto i = 0; i < count; i++) {
            if (data[i] == value)
                return true;
        }
        return false;
    }

    // Добавление элемента
    void add(const T& value) {
        if (count < 50) {
            // Проверяем, нет ли уже такого элемента
            if (!find(value)) {
                data[count++] = value;
            }
            else {
                cout << "Элемент " << value << " уже существует в графе!" << endl;
            }
        }
        else {
            cout << "Граф переполнен!" << endl;
        }
    }

    // Удаление элемента
    void remove(const T& value) {
        auto index = -1;
        for (auto i = 0; i < count; i++) {
            if (data[i] == value) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (auto i = index; i < count - 1; i++) {
                data[i] = data[i + 1];
            }
            count--;
            cout << "Элемент " << value << " удален из графа." << endl;
        }
        else {
            cout << "Элемент не найден!" << endl;
        }
    }

    // Возврат содержимого в строке
    string toString() const {
        if (count == 0) {
            return "(пустой граф)";
        }

        stringstream ss;
        for (auto i = 0; i < count; i++) {
            ss << data[i];
            if (i < count - 1) {
                ss << " ";
            }
        }
        return ss.str();
    }

    // Вывод содержимого в поток
    friend ostream& operator<<(ostream& out, const Graph& g) {
        out << g.toString();
        return out;
    }

    // Чтение содержимого из потока
    friend istream& operator>>(istream& in, Graph& g) {
        g.clear(); // Очищаем перед чтением новых данных

        int n;
        cout << "Введите количество вершин: ";
        in >> n;

        if (n > 50) {
            n = 50;
            cout << "Ограничено до 50 вершин" << endl;
        }

        for (auto i = 0; i < n; i++) {
            T value{};
            cout << "Введите значение вершины " << i + 1 << ": ";
            in >> value;
            g.add(value);
        }
        return in;
    }

    // Очистка содержимого
    void clear() {
        count = 0;
        cout << "Граф очищен." << endl;
    }

    // Дополнительные полезные методы
    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

    T get(int index) const {
        if (index >= 0 && index < count) {
            return data[index];
        }
        throw out_of_range("Индекс вне диапазона");
    }
};

// Пример использования
int main() {
    setlocale(LC_ALL, "RU");

    Graph<int> graph;

    // Добавление элементов
    graph.add(10);
    graph.add(20);
    graph.add(30);
    graph.add(40);

    // Вывод через оператор <<
    cout << "Граф: " << graph << endl;

    // Поиск элемента
    cout << "Поиск 20: " << (graph.find(20) ? "найден" : "не найден") << endl;
    cout << "Поиск 50: " << (graph.find(50) ? "найден" : "не найден") << endl;

    // Использование toString
    cout << "toString(): " << graph.toString() << endl;

    // Удаление элемента
    graph.remove(20);
    cout << "После удаления: " << graph << endl;

    // Очистка
    graph.clear();
    cout << "После очистки: " << graph << endl;
    return 0;
}
