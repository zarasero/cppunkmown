// Span.cpp
#include "Span.hpp"

// Конструктор по умолчанию
Span::Span() : _N(0) {}

// Конструктор с параметром, инициализирующим максимальное количество чисел
Span::Span(unsigned int N) : _N(N) {}

// Конструктор копирования
Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

// Оператор присваивания
Span &Span::operator=(const Span &other) {
    if (this != &other) {   // Проверка на самоприсваивание
        _N = other._N;      // Копируем максимальное количество чисел
        _numbers = other._numbers;  // Копируем вектор чисел
    }
    return *this;
}

// Деструктор
Span::~Span() {}

// Метод для добавления одного числа
void Span::addNumber(int num) {
    if (_numbers.size() >= _N) {
        throw std::runtime_error("Error: the container is already full. ");
    }
    _numbers.push_back(num);
}

// Метод для нахождения самой короткой разницы (shortestSpan)
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Error: There are not enough numbers to calculate the difference. ");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
        int diff = sortedNumbers[i + 1] - sortedNumbers[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

// Метод для нахождения самой длинной разницы (longestSpan)
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Error: There are not enough numbers to calculate the difference. ");
    }

    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());

    return maxElement - minElement;
}
