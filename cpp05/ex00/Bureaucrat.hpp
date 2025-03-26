/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:26:17 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/13 12:15:03 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
public:
    // Конструкторы и деструктор
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    ~Bureaucrat();

    // Геттеры
    std::string getName() const;
    int getGrade() const;

    // Методы изменения ранга
    void incrementGrade();
    void decrementGrade();

    // Исключения
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { // Обещает не выбрасывать исключений
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
    const std::string _name; // Константное имя
    int _grade; // Уровень бюрократа (1 - 150)
};

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif

