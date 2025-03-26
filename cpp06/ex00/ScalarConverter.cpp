/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:21:01 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 19:02:41 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

// Проверяем, является ли строка символом (1 печатный символ, который не цифра)
bool isChar(const std::string& str) {
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}
/*std::isprint(str[0]) — это функция из заголовочного файла 
<cctype>, которая проверяет, является ли символ печатным 
(то есть отображаемым на экране). \n, \t, \0*/

// Проверяем, является ли строка целым числом
bool isInt(const std::string& str) {
    char* end;
    long value = std::strtol(str.c_str(), &end, 10);
    return *end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}
/* Если str начинается не с числа → strtol вернёт 0, а end 
будет указывать на str.*/

// Проверяем, является ли строка float (содержит 'f' в конце)
bool isFloat(const std::string& str) {
    return str.find('f') != std::string::npos;
}

// Проверяем, является ли строка double (содержит точку, но без 'f' в конце)
bool isDouble(const std::string& str) {
    return !isFloat(str) && str.find('.') != std::string::npos;
}

// Метод для преобразования строки в другие типы
void ScalarConverter::convert(const std::string& literal) {
    char c;
    int i;
    float f;
    double d;

    // Обрабатываем специальные значения: -inff, +inff, nanf
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        f = std::strtof(literal.c_str(), NULL);
        d = static_cast<double>(f);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;
        return;
    }

    // Обрабатываем специальные значения: -inf, +inf, nan
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        d = std::strtod(literal.c_str(), NULL);
        f = static_cast<float>(d);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;
        return;
    }

    try {
        // Проверяем, является ли строка символом
        if (isChar(literal)) {
            c = literal[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
        }
        // Проверяем, является ли строка целым числом
        else if (isInt(literal)) {
            i = std::strtol(literal.c_str(), NULL, 10);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        }
        // Проверяем, является ли строка float
        else if (isFloat(literal)) {
            f = std::strtof(literal.c_str(), NULL);
            i = static_cast<int>(f);
            c = static_cast<char>(i);
            d = static_cast<double>(f);
        }
        // Проверяем, является ли строка double
        else if (isDouble(literal)) {
            d = std::strtod(literal.c_str(), NULL);
            i = static_cast<int>(d);
            c = static_cast<char>(i);
            f = static_cast<float>(d);
        }
        // Если не удалось определить тип, выбрасываем исключение
        else {
            throw std::invalid_argument("Invalid literal");
        }

        // Вывод результатов
        if (std::isprint(c))
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable\n";

        std::cout << "int: " << i << "\n";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

/*std::fixed:
Этот манипулятор изменяет формат вывода чисел с плавающей запятой, заставляя их выводиться в фиксированном формате. Это означает, что число будет выводиться с запятой, а не в экспоненциальной форме (например, 1.23e+2 будет выведено как 123.0).

std::setprecision(n):
Этот манипулятор задаёт точность вывода: сколько знаков после запятой будет отображаться для чисел с плавающей запятой.
В твоём примере std::setprecision(1) указывает, что после запятой будет отображаться 1 знак.*/


