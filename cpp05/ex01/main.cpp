/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:19:54 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 13:42:41 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 3);  // Создаем бюрократа
        Form form("Tax Form", 1, 50);  // Создаем форму с уровнями для подписания и выполнения
        
        std::cout << form << std::endl;  // Печатаем информацию о форме

        john.signForm(form);  // Пытаемся подписать форму

        std::cout << form << std::endl;  // Печатаем информацию о форме после подписания
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

