/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:26:17 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/13 12:17:57 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    Bureaucrat();
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm& form);
    void executeForm(AForm const& form);

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Error: Bureaucrat's grade is too high.";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Error: Bureaucrat's grade is too low.";
        }
    };

private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
