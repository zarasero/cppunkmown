#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        // Создаем Span с максимальным размером 5
        Span sp = Span(5);

        // Добавляем числа вручную
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // Выводим минимальную и максимальную разницу
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Должно вывести 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Должно вывести 14

        // Пример добавления чисел через диапазон итераторов
        std::vector<int> largeNumbers(10000);
        for (int i = 0; i < 10000; ++i) {
            largeNumbers[i] = i * 2;
        }

        Span largeSpan(10000);
        largeSpan.addNumber(largeNumbers.begin(), largeNumbers.end());

        std::cout << "Shortest span (largeSpan): " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span (largeSpan): " << largeSpan.longestSpan() << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Ловим и выводим исключение
    }

    return 0;
}
