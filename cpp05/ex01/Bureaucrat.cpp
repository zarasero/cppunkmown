/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:26:10 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/13 12:09:30 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {

}
// Конструктор с параметрами
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

// Конструктор копирования
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade) {}

// Оператор присваивания
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs) {
        this->_grade = rhs._grade; // Имя менять нельзя, так как оно `const`
    }
    return *this;
}

// Деструктор
Bureaucrat::~Bureaucrat() {}

// Геттеры
std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Повышение ранга
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

// Понижение ранга
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}



