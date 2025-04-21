#include "MutantStack.hpp"
#include <iostream>

int main() {
    // Создаем объект MutantStack для хранения целых чисел
    MutantStack<int> mstack;

    // Добавляем элементы в стек
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;  // Выводим верхний элемент стека (17)

    mstack.pop();  // Убираем верхний элемент (17)

    // Проверяем размер стека
    std::cout << mstack.size() << std::endl;  // Размер стека (1)

    // Добавляем еще элементы
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Используем итераторы для вывода всех элементов
    MutantStack<int>::iterator it = mstack.begin();  // Итератор на начало
    MutantStack<int>::iterator ite = mstack.end();   // Итератор на конец

    // Итерируем через стек и выводим элементы
    ++it;  // Перемещаем итератор на следующий элемент
    --it;  // Перемещаем итератор обратно на исходную позицию

    // Итерация по стеку и вывод значений
    while (it != ite) {
        std::cout << *it << std::endl;  // Выводим значение, на которое указывает итератор
        ++it;  // Переходим к следующему элементу
    }

    // Создаем обычный std::stack, копируя содержимое MutantStack
    std::stack<int> s(mstack);

    return 0;
}
