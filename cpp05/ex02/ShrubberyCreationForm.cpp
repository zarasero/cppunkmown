/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:17:03 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 16:17:26 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    file << "     ^     \n"
         << "    ^^^    \n"
         << "   ^^^^^   \n"
         << "  ^^^^^^^  \n"
         << " ^^^^^^^^^ \n"
         << "^^^^^^^^^^^ \n"
         << "     |||   \n";
    file.close();
}

// Перегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
    os << "Shrubbery Creation Form for " << form._target;
    return os;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }

    if (executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    executeAction();
}
