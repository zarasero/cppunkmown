/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:37:36 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 12:43:45 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

// 🔹 Конструктор по умолчанию
Form::Form() 
    : _name("Unnamed"), _signed(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150) {}

// 🔹 Конструктор копирования
Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeRequiredToSign(other._gradeRequiredToSign), 
      _gradeRequiredToExecute(other._gradeRequiredToExecute) {}

// 🔹 Оператор присваивания
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _signed = other._signed;  // Единственное изменяемое поле
    }
    return *this;
}

// 🔹 Деструктор
Form::~Form() {}

// 🔹 Конструктор с параметрами
Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : _name(name), _signed(false), 
      _gradeRequiredToSign(gradeRequiredToSign), 
      _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (_gradeRequiredToSign < 1 || _gradeRequiredToExecute < 1)
        throw GradeTooHighException();
    if (_gradeRequiredToSign > 150 || _gradeRequiredToExecute > 150)
        throw GradeTooLowException();
}

// 🔹 Геттеры
std::string Form::getName() const { return _name; }
bool Form::getSigned() const { return _signed; }
int Form::getGradeRequiredToSign() const { return _gradeRequiredToSign; }
int Form::getGradeRequiredToExecute() const { return _gradeRequiredToExecute; }

// 🔹 Метод подписания
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeRequiredToSign) {
        _signed = true;
    } else {
        throw GradeTooLowException();
    }
}

// 🔹 Перегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", Form grade to sign: " << form.getGradeRequiredToSign()
       << ", grade to execute: " << form.getGradeRequiredToExecute()
       << ", Signed: " << (form.getSigned() ? "Yes" : "No");
    return os;
}
