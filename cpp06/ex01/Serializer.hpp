/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:38:55 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 20:57:39 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

// Структура данных для сериализации
typedef struct Data {
    int num; // Пример переменной
} s_Data;

// Класс Serializer
#include <iostream>
#include <cstdint>  // Для uintptr_t

class Serializer {
public:
    // Статический метод сериализации (преобразование указателя в число)
    static uintptr_t serialize(Data* ptr);

    // Статический метод десериализации (преобразование числа обратно в указатель)
    static Data* deserialize(uintptr_t raw);

private:
    // Запрещаем создание экземпляров этого класса
    Serializer() {}  // Конструктор по умолчанию
    ~Serializer() {} // Деструктор
    Serializer(const Serializer&); // Запрещаем копирование
    Serializer& operator=(const Serializer&); // Запрещаем присваивание
};

// Реализация сериализации
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Реализация десериализации
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}


#endif // SERIALIZER_HPP
