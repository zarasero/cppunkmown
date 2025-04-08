#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();  // Конструктор
    Intern(const Intern& other);  // Копирующий конструктор
    Intern& operator=(const Intern& other);  // Оператор присваивания
    ~Intern();  // Деструктор

    // Метод для создания формы
    AForm* makeForm(std::string formName, std::string target);

    class FormNotExist : public std::exception {
        const char* what() const throw() {
            return "Form doesn't exist!";
        }
    };
};

#endif
