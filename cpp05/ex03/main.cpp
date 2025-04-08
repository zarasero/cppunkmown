/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:19:54 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 14:41:32 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    AForm* form;

    try {
        form = intern.makeForm("robotomy request", "Bender");
        delete form;
        
        form = intern.makeForm("shrubbery creation", "Garden");
        delete form;
        
        form = intern.makeForm("presidential pardon", "Alice");
        delete form;

        form = intern.makeForm("nonexistent form", "Nobody");  // Здесь будет исключение
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}



/*
int main() {
    // Создаем стажера
    Intern intern;

    // Создаем указатели на формы через стажера
    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    AForm* form2 = intern.makeForm("shrubbery creation", "Garden");
    AForm* form3 = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
    AForm* form4 = intern.makeForm("unknown form", "Unknown Target");  // Неправильная форма

    // Создаем бюрократа для выполнения форм
    Bureaucrat boss("The Boss", 1);  // С самым высоким рангом

    std::cout << std::endl;

    // Попытка подписать и выполнить формы
    try {
        if (form1) {
            form1->beSigned(boss);
            form1->execute(boss);
        }
        if (form2) {
            form2->beSigned(boss);
            form2->execute(boss);
        }
        if (form3) {
            form3->beSigned(boss);
            form3->execute(boss);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Освобождаем память, выделенную под формы
    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}*/