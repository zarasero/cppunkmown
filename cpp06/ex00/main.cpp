/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:21:18 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 18:33:29 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    std::string input = argv[1]; // Получаем аргумент из командной строки
    ScalarConverter::convert(input); // Вызываем функцию конвертации
    return 0;
}


/*$ ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

$ ./convert nan
char: impossible
int: impossible
float: nanf
double: nan

$ ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

$ ./convert -inff
char: impossible
int: impossible
float: -inff
double: -inf

$ ./convert 123
char: '{'
int: 123
float: 123.0f
double: 123.0

$ ./convert A
char: 'A'
int: 65
float: 65.0f
double: 65.0
*/