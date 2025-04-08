#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;  // У Intern нет уникальных атрибутов
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    AForm* form = NULL;

    // Массив строк с именами форм
    const char* formNames[] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    int i;
    // Ищем индекс нужной формы
    for (i = 0; i < 3; i++) {
        if (formName == formNames[i])
            break;
    }

    // Используем switch для выбора формы
    switch (i)
    {
        case 0:
            form = new PresidentialPardonForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            // Если форма не найдена, генерируем исключение
            throw Intern::FormNotExist();
    }

    // Выводим сообщение о том, что форма была создана
    std::cout <<  "Intern  creates "  << formNames[i] <<  " form." << std::endl;
    
    return form;
}