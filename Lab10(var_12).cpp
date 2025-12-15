#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class Graph {
private:
    // Хранение вершин
    T vertices[50];
    int vertexCount;

    int edges[50][50]; // 0 - нет ребра, 1 - есть ребро

    static const int MAX_VERTICES = 50; // Максимальное количество вершин

public:
    Graph() : vertexCount(0) {
        // Инициализация матрицы рёбер нулями
        for (int i = 0; i < MAX_VERTICES; i++) {
            for (int j = 0; j < MAX_VERTICES; j++) {
                edges[i][j] = 0;
            }
        }
    }

    // ===== Методы для работы с вершинами =====

    // Поиск вершины по значению, возвращает индекс
    int findVertex(const T& value) const {
        for (int i = 0; i < vertexCount; i++) {
            if (vertices[i] == value)
                return i;
        }
        return -1;
    }

    // Добавление вершины
    bool addVertex(const T& value) {
        if (vertexCount >= MAX_VERTICES) {
            cout << "Достигнуто максимальное количество вершин (" << MAX_VERTICES << ")!" << endl;
            return false;
        }

        if (findVertex(value) != -1) {
            cout << "Вершина " << value << " уже существует!" << endl;
            return false;
        }

        vertices[vertexCount] = value;
        vertexCount++;
        return true;
    }

    // Удаление вершины (и всех связанных рёбер)
    bool removeVertex(const T& value) {
        int index = findVertex(value);
        if (index == -1) {
            cout << "Вершина " << value << " не найдена!" << endl;
            return false;
        }

        // Удаляем вершину, сдвигая оставшиеся
        for (int i = index; i < vertexCount - 1; i++) {
            vertices[i] = vertices[i + 1];
        }

        // Удаляем все рёбра, связанные с этой вершиной
        // Сдвигаем строки и столбцы в матрице смежности
        for (int i = index; i < vertexCount - 1; i++) {
            for (int j = 0; j < vertexCount; j++) {
                edges[i][j] = edges[i + 1][j];
            }
        }

        for (int i = 0; i < vertexCount; i++) {
            for (int j = index; j < vertexCount - 1; j++) {
                edges[i][j] = edges[i][j + 1];
            }
        }

        // Обнуляем последнюю строку и столбец
        for (int i = 0; i < vertexCount; i++) {
            edges[vertexCount - 1][i] = 0;
            edges[i][vertexCount - 1] = 0;
        }

        vertexCount--;
        cout << "Вершина " << value << " удалена." << endl;
        return true;
    }

    // ===== Методы для работы с рёбрами =====

    // Добавление ребра между вершинами
    bool addEdge(const T& from, const T& to) {
        int fromIndex = findVertex(from);
        int toIndex = findVertex(to);

        if (fromIndex == -1) {
            cout << "Вершина " << from << " не найдена!" << endl;
            return false;
        }
        if (toIndex == -1) {
            cout << "Вершина " << to << " не найдена!" << endl;
            return false;
        }
        if (fromIndex == toIndex) {
            cout << "Нельзя создать ребро из вершины в саму себя!" << endl;
            return false;
        }

        if (edges[fromIndex][toIndex] == 1) {
            cout << "Ребро между " << from << " и " << to << " уже существует!" << endl;
            return false;
        }

        edges[fromIndex][toIndex] = 1;
        edges[toIndex][fromIndex] = 1;
        return true;
    }

    // Удаление ребра
    bool removeEdge(const T& from, const T& to) {
        int fromIndex = findVertex(from);
        int toIndex = findVertex(to);

        if (fromIndex == -1 || toIndex == -1) {
            cout << "Одна из вершин не найдена!" << endl;
            return false;
        }

        if (edges[fromIndex][toIndex] == 0) {
            cout << "Ребро между " << from << " и " << to << " не найдено!" << endl;
            return false;
        }

        edges[fromIndex][toIndex] = 0;
        edges[toIndex][fromIndex] = 0;
        cout << "Ребро между " << from << " и " << to << " удалено." << endl;
        return true;
    }

    // ===== Методы для работы с графом =====

    // Возврат содержимого в строке
    string toString() const {
        if (vertexCount == 0) { return "(пустой граф)"; }

        stringstream ss;
        ss << "Вершины: ";
        for (int i = 0; i < vertexCount; i++) {
            ss << vertices[i];
            if (i < vertexCount - 1) {
                ss << " ";
            }
        }

        ss << "\nРёбра:\n";
        bool hasEdges = false;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = i + 1; j < vertexCount; j++) {
                if (edges[i][j] == 1) {
                    ss << "  " << vertices[i] << " -- " << vertices[j] << "\n";
                    hasEdges = true;
                }
            }
        }

        if (!hasEdges) { ss << "  (нет рёбер)\n"; }
        return ss.str();
    }

    // Вывод содержимого в поток
    friend ostream& operator<<(ostream& out, const Graph& g) {
        out << g.toString();
        return out;
    }

    // Чтение содержимого из потока
    friend istream& operator>>(istream& in, Graph& g) {
        g.clear();

        int n;
        cout << "Введите количество вершин: ";
        in >> n;

        if (n > MAX_VERTICES) {
            n = MAX_VERTICES;
            cout << "Ограничено до " << MAX_VERTICES << " вершин" << endl;
        }

        for (int i = 0; i < n; i++) {
            T value{};
            cout << "Введите значение вершины " << i + 1 << ": ";
            in >> value;
            g.addVertex(value);
        }

        // Ввод рёбер
        cout << "Хотите добавить рёбра? (1 - да, 0 - нет): ";
        int choice;
        in >> choice;

        if (choice == 1) {
            cout << "Введите количество рёбер: ";
            int edgeCount;
            in >> edgeCount;

            for (int i = 0; i < edgeCount; i++) {
                T from{}, to{};
                cout << "Ребро " << i + 1 << " из вершины: ";
                in >> from;
                cout << "Ребро " << i + 1 << " в вершину: ";
                in >> to;
                g.addEdge(from, to);
            }
        }

        return in;
    }

    // Очистка содержимого
    void clear() {
        vertexCount = 0;
        for (int i = 0; i < MAX_VERTICES; i++) {
            for (int j = 0; j < MAX_VERTICES; j++) {
                edges[i][j] = 0;
            }
        }
        cout << "Граф очищен." << endl;
    }

    int size() const { return vertexCount; }

    bool empty() const { return vertexCount == 0; }

    T getVertex(int index) const {
        if (index >= 0 && index < vertexCount) {
            return vertices[index];
        }
        throw out_of_range("Индекс вне диапазона");
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Graph<int> graph;

    // Добавление вершин
    graph.addVertex(10);
    graph.addVertex(20);
    graph.addVertex(30);
    graph.addVertex(40);

    // Добавление рёбер
    graph.addEdge(10, 20);
    graph.addEdge(20, 30);
    graph.addEdge(30, 40);

    // Вывод через оператор <<
    cout << "Граф:\n" << graph << endl;

    // Поиск вершины
    cout << "Поиск вершины 20: " << (graph.findVertex(20) != -1 ? "найден" : "не найден") << endl;
    cout << "Поиск вершины 50: " << (graph.findVertex(50) != -1 ? "найден" : "не найден") << endl;

    // Использование toString
    cout << "toString():\n" << graph.toString() << endl;

    // Удаление ребра
    graph.removeEdge(20, 30);
    cout << "После удаления ребра (20-30):\n" << graph << endl;

    // Удаление вершины
    graph.removeVertex(20);
    cout << "После удаления вершины 20:\n" << graph << endl;

    // Очистка
    graph.clear();
    cout << "После очистки:\n" << graph << endl;

    // Ввод графа с клавиатуры
    cout << "\n=== Ввод графа с клавиатуры ===" << endl;
    cin >> graph;
    cout << "\nВведённый граф:\n" << graph << endl;

    return 0;
}
