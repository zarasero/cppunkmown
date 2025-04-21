#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>       // Подключаем vector
#include <list>         // Подключаем list
#include <deque>        // Подключаем deque
#include <algorithm>    // Подключаем find для поиска
#include <exception>    // Подключаем для работы с исключениями

// Шаблонная функция easyfind, которая ищет первое вхождение числа в контейнере T
template <typename T>
int easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value); // Ищем элемент

    if (it == container.end()) {  // Если элемент не найден, выбрасываем исключение
        throw std::runtime_error("Element not found!");
    }

    return *it;  // Возвращаем найденное значение (разыменовываем итератор)
}

#endif


/*std::exception	Базовый класс для всех стандартных исключений.
std::runtime_error	Ошибки времени выполнения (runtime), часто непредсказуемые.
std::logic_error	Ошибки логики (например, неверные аргументы функции).
std::out_of_range	Дочерний класс std::logic_error, ошибка выхода за границы.
std::invalid_argument	Ошибка, возникающая из-за недопустимого аргумента.*/