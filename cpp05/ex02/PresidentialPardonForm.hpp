/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:47:43 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 15:43:23 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm {
public:
    // Конструктор с параметром, принимает имя цели для помилования
    PresidentialPardonForm(std::string target);

    // Копирующий конструктор
    PresidentialPardonForm(const PresidentialPardonForm& other);

    // Перегрузка оператора присваивания
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    // Деструктор
    virtual ~PresidentialPardonForm();

    // Метод execute для выполнения действия формы
    virtual void execute(Bureaucrat const & executor) const;

    // Реализация действия формы, переопределение чисто виртуального метода (если он таковой в AForm)
    virtual void executeAction() const;

    // Геттер для получения целевой строки
    std::string getTarget() const;

private:
    // Строка для хранения цели помилования
    std::string _target;
};

// Оператор вывода информации о форме
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif


