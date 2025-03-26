/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:17:42 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 16:10:34 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Конструктор по умолчанию
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("default") {}

// Конструктор с параметром
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target) {}

// Копирующий конструктор
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

// Оператор присваивания
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        _target = other._target;
    }
    return *this;
}

// Деструктор
RobotomyRequestForm::~RobotomyRequestForm() {}

// Метод executeAction
void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    // Генерация случайного числа для имитации успешности роботизации
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed!" << std::endl;
}

// Метод execute
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    // Проверяем, подписана ли форма и достаточно ли высокий уровень бюрократа для выполнения
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }

    if (executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    // Вызываем executeAction после проверки
    executeAction();
}

// Реализация getTarget
std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form) {
    os << "Robotomy Request Form for " << form.getTarget();
    return os;
}
