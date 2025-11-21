#include <iostream>
#include <string>
using namespace std;

// Базовые функции преобразования значений (переименованы)
string jsonValue(int value) { return to_string(value); }
string jsonValue(double value) { return to_string(value); }
string jsonValue(bool value) { return value ? "true" : "false"; }
string jsonValue(const string& value) { return "\"" + value + "\""; }
string jsonValue(const char* value) { return "\"" + string(value) + "\""; }

// Подход 1: Рекурсия
template<typename Arg>
string toJsonRecursive(Arg&& arg) {
    return jsonValue(arg);
}

template<typename First, typename... Other>
string toJsonRecursive(First&& first, Other&&... other) {
    return jsonValue(first) + "," + toJsonRecursive(other...);
}

// Подход 2: Fold Expressions
template<typename... Args>
string toJsonFold(Args&&... args) {
    string result = "[";
    ((result += jsonValue(forward<Args>(args)) + ","), ...);
    if constexpr (sizeof...(Args) > 0) result.pop_back();
    result += "]";
    return result;
}

// Основная функция - можно выбрать любой подход
template<typename... Args>
string toJson(Args&&... args) {
    if constexpr (sizeof...(Args) == 0) {
        return "[]";
    }
    else {
        return toJsonFold(forward<Args>(args)...); // Fold expressions
        //return "[" + toJsonRecursive(forward<Args>(args)...) + "]"; // Рекурсия
    }
}

int main() {
    setlocale(LC_ALL, "C");
    // Простые типы данных
    cout << "1. Simple values:" << endl;
    cout << toJson(42) << endl;
    cout << toJson(3.14) << endl;
    cout << toJson(true) << endl;
    cout << toJson("hello") << endl;
    cout << toJson(string("world")) << endl;
    cout << endl;

    cout << "2. Number arrays:" << endl;
    cout << toJson(1, 2, 3) << endl;
    cout << toJson(1.1, 2.2, 3.3) << endl;
    cout << endl;

    cout << "3. Mixed types:" << endl;
    cout << toJson(1, "text", true, 4.5) << endl;
    cout << toJson("apple", 123, false, "banana", 7.89) << endl;
    cout << endl;

    cout << "4. Empty array:" << endl;
    cout << toJson() << endl;
    cout << endl;

    cout << "5. Strings:" << endl;
    cout << toJson("test", "123", "C++") << endl;

    return 0;
}
