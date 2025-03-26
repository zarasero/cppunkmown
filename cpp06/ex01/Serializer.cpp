/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:39:01 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/09 12:26:32 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Конструктор
Serializer::Serializer() {
    return;
}

// Деструктор
Serializer::~Serializer() {
    return;
}

// Конструктор копирования
Serializer::Serializer(const Serializer& src) {
    *this = src;
    return;
}

// Оператор присваивания
Serializer& Serializer::operator=(const Serializer& rhs) {
    if (this != &rhs)
        *this = rhs;
    return *this;
}

// Функция сериализации: преобразует указатель в uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Функция десериализации: преобразует uintptr_t обратно в указатель
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}


