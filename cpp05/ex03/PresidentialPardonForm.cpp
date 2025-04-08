/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:18:23 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/07 15:57:55 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructor with target initialization
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);  // Call the base class assignment
        _target = other._target;
    }
    return *this;
}

// Destructor (no extra resources to free)
PresidentialPardonForm::~PresidentialPardonForm() {}

// Execute method to perform the action of the form
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())  // Проверка, подписана ли форма
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getExecGrade())  // Проверка, достаточен ли у бюрократа уровень для выполнения
        throw AForm::GradeTooLowException();

    executeAction();  // Выполнение действия формы
}


// Action performed by the form (specific to PresidentialPardonForm)
void PresidentialPardonForm::executeAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Getter for the target of the form
std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

// Output operator for printing the form details
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form) {
    os << "Presidential Pardon Form for " << form.getTarget();
    return os;
}
