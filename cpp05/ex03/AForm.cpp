/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:16:18 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 15:33:21 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

// Parameterized constructor
AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

// Assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

// Be signed by a bureaucrat
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

// Execute the form
void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeAction();
}


