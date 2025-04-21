#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>       // Для использования std::stack
#include <iterator>    // Для работы с итераторами

// Шаблонный класс MutantStack, расширяющий std::stack
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Конструктор по умолчанию
    MutantStack() : std::stack<T>() {}

    // Конструктор копирования
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}

    // Деструктор
    ~MutantStack() {}

    // Оператор присваивания копированием
    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            this->c = other.c; // Прямое копирование контейнера
        }
        return *this;
    }
    

    // Тип итератора для MutantStack
    typedef typename std::stack<T>::container_type::iterator iterator;

    // Функция для получения итератора на начало
    iterator begin() {
        return this->c.begin();  // Возвращаем итератор на начало контейнера
    }

    // Функция для получения итератора на конец
    iterator end() {
        return this->c.end();    // Возвращаем итератор на конец контейнера
    }
};

#endif

