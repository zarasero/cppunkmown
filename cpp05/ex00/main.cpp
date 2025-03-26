/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:19:54 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/05 15:23:55 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        std::cout << bob << std::endl;

        bob.incrementGrade(); // Ошибка, ранг не может быть выше 1
    }
    catch (std::exception& e) {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "====================" << std::endl;

    try {
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;

        alice.decrementGrade(); // Ошибка, ранг не может быть ниже 150
    }
    catch (std::exception& e) {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "====================" << std::endl;

    try {
        Bureaucrat carl("Carl", 151); // Ошибка при создании
    }
    catch (std::exception& e) {
        std::cout << "❌ " << e.what() << std::endl;
    }

    std::cout << "====================" << std::endl;

    try {
        Bureaucrat dave("Dave", 50);
        std::cout << dave << std::endl;
        dave.incrementGrade();
        std::cout << dave << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "❌ " << e.what() << std::endl;
    }

    return 0;
}

