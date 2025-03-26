/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:45:32 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/09 17:45:44 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>  // Для обработки исключений std::out_of_range

template <typename T>
class Array {
private:
    T* data;          // Указатель на массив
    unsigned int len; // Количество элементов в массиве

public:
    // **Конструктор по умолчанию**: создаёт пустой массив
    Array() : data(nullptr), len(0) {}

    // **Конструктор с параметром**: создаёт массив из `n` элементов, инициализированных значениями по умолчанию
    Array(unsigned int n) : len(n) {
        data = new T[n](); // Выделяем память и инициализируем значения по умолчанию
    }

    // **Конструктор копирования**: создаёт новый массив с копией данных
    Array(const Array& other) : len(other.len) {
        data = new T[len]; // Выделяем новую память
        for (unsigned int i = 0; i < len; ++i) {
            data[i] = other.data[i]; // Копируем элементы
        }
    }

    // **Оператор присваивания**: корректное присваивание без утечек памяти
    Array& operator=(const Array& other) {
        if (this != &other) { // Проверяем самоприсваивание
            delete[] data; // Освобождаем старую память

            len = other.len;
            data = new T[len]; // Выделяем новую память
            for (unsigned int i = 0; i < len; ++i) {
                data[i] = other.data[i]; // Копируем элементы
            }
        }
        return *this;
    }

    // **Оператор доступа по индексу**: возвращает ссылку на элемент массива
    T& operator[](unsigned int index) {
        if (index >= len) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        return data[index];
    }

    // **Оператор доступа по индексу (константный вариант)**: для работы с `const Array`
    const T& operator[](unsigned int index) const {
        if (index >= len) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        return data[index];
    }

    // **Метод size()**: возвращает размер массива
    unsigned int size() const {
        return len;
    }

    // **Деструктор**: освобождает выделенную память
    ~Array() {
        delete[] data;
    }
};

#endif // ARRAY_HPP

