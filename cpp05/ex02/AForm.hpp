/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:16:12 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/13 12:40:51 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Methods
    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const = 0;

    // Exception classes
    class GradeTooHighException : public std::exception {
        public:
        const char* what() const throw() {
            return "AForm: Grade is too high.";
        }
    };

    class GradeTooLowException : public std::exception {
        public:
        const char* what() const throw() {
            return "AForm: Grade is too low.";
        }
    };

    class FormNotSignedException : public std::exception {
        public:
        const char* what() const throw() {
            return "AForm: Form is not signed.";
        }
    };

protected:
    virtual void executeAction() const = 0;

private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;
};

#endif


