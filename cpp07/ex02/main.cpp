/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:44:49 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/09 17:46:07 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

using namespace std;

int main() {
    // **Тест 1: Конструктор по умолчанию**
    Array<int> emptyArray;
    cout << "Размер пустого массива: " << emptyArray.size() << endl;

    // **Тест 2: Конструктор с параметром**
    Array<int> intArray(5);
    cout << "Размер массива intArray: " << intArray.size() << endl;

    // **Заполняем массив значениями**
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
    }

    // **Выводим элементы массива**
    cout << "Элементы массива intArray: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    // **Тест 3: Конструктор копирования**
    Array<int> copyArray(intArray);
    cout << "Копия intArray: ";
    for (unsigned int i = 0; i < copyArray.size(); ++i) {
        cout << copyArray[i] << " ";
    }
    cout << endl;

    // **Изменяем оригинальный массив и проверяем копию**
    intArray[0] = 999;
    cout << "После изменения intArray[0]: " << intArray[0] << endl;
    cout << "Копия copyArray[0]: " << copyArray[0] << " (не изменилась)" << endl;

    // **Тест 4: Оператор присваивания**
    Array<int> assignArray;
    assignArray = intArray;
    cout << "Присвоенный массив assignArray: ";
    for (unsigned int i = 0; i < assignArray.size(); ++i) {
        cout << assignArray[i] << " ";
    }
    cout << endl;

    // **Тест 5: Обращение по индексу за границами массива**
    try {
        cout << intArray[10] << endl; // Ошибка! Выход за границы массива
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    // **Тест 6: Использование шаблона с типом string**
    Array<string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "C++";
    strArray[2] = "Templates";

    cout << "Строковый массив: ";
    for (unsigned int i = 0; i < strArray.size(); ++i) {
        cout << strArray[i] << " ";
    }
    cout << endl;

    return 0;
}