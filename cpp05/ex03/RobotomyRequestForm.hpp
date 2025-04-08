/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:48:26 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 16:10:21 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class RobotomyRequestForm : public AForm {
public:
    // Конструкторы
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);

    // Копирующий конструктор
    RobotomyRequestForm(const RobotomyRequestForm& other);

    // Оператор присваивания
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    // Деструктор
    ~RobotomyRequestForm();

    // Метод execute для выполнения действия формы
    void execute(const Bureaucrat& executor) const;

    // Геттер для целевой строки
    std::string getTarget() const;

protected:
    // Функция действия формы (перегрузка)
    void executeAction() const;

private:
    // Цель роботизации
    std::string _target;
};

// Оператор вывода для RobotomyRequestForm
std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& rhs);

#endif

