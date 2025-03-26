/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:26:10 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/13 12:18:16 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade) {}
Bureaucrat::Bureaucrat(){}
// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Increment grade
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

// Decrement grade
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

// Sign a form
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// Execute a form
void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// Overloaded operator<<
std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
