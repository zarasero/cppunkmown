/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:21:08 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 19:28:51 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>   // Для strtol, strtof, strtod
#include <limits>    // Для std::numeric_limits
#include <iomanip>   // Для std::setprecision
#include <cmath>     // Для проверки специальных чисел

class ScalarConverter {
private:
    ScalarConverter(); // Запрещаем создание объектов
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(const std::string& literal); // Метод для преобразования
};

#endif

/*разобраться в структуре приват */