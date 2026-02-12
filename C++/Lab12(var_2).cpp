// Вычисление НОД
#include <iostream>
#include <concepts>
using namespace std;

template<typename T>
concept NodApplicable = integral<T>;

template <NodApplicable T>
constexpr auto nod = [](T a, T b) constexpr 
    {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }

    return a;
    };

int main() {
    setlocale(LC_ALL, "RU");
    // Вычисления во время компиляции
    constexpr auto result1 = nod<int>(48, 18);     // НОД(48, 18) = 6
    constexpr auto result2 = nod<int>(17, 13);     // НОД(17, 13) = 1
    constexpr auto result3 = nod<int>(-36, 48);    // НОД(-36, 48) = 12

    int result4 = nod<int>(35, 15);
    // Вывод результатов
    cout << "НОД(48, 18) = " << result1 << endl;
    cout << "НОД(17, 13) = " << result2 << endl;
    cout << "НОД(-36, 48) = " << result3 << endl;
    cout << "НОД(35, 15) = " << result4 << endl;

    return 0;
}
