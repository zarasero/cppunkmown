/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <zserobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:50:44 by zserobia          #+#    #+#             */
/*   Updated: 2025/03/09 16:29:43 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

// Базовый класс с виртуальным деструктором
class Base {
public:
    virtual ~Base() {}
};

// Пустые классы-наследники
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Функция, создающая случайный объект типа A, B или C
Base * generate(void) {
    int randValue = std::rand() % 3; // Генерируем случайное число от 0 до 2
    if (randValue == 0)
        return new A();
    else if (randValue == 1)
        return new B();
    else
        return new C();
}

// Функция, определяющая тип объекта по указателю
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) // Проверяем, можно ли привести указатель к A
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) // Проверяем, можно ли привести указатель к B
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) // Проверяем, можно ли привести указатель к C
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Функция, определяющая тип объекта по ссылке
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p); // Пробуем привести к A
        std::cout << "A ff" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p); // Пробуем привести к B
        std::cout << "B fff" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<C&>(p); // Пробуем привести к C
        std::cout << "C ff" << std::endl;
        return;
    } catch (...) {}
    
    std::cout << "Unknown type" << std::endl;
}

/*Почему нельзя просто if (dynamic_cast<C&>(p))?
Потому что dynamic_cast при приведении к ссылке либо успешно выполняется, либо выбрасывает исключение. 
Он не возвращает nullptr, как это делает приведение к указателю.*/

// Главная функция для тестирования
int main() {
    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    
    Base *ptr = generate(); // Создаем случайный объект
    identify(ptr); // Определяем тип по указателю
    identify(*ptr); // Определяем тип по ссылке
    
    delete ptr; // Освобождаем память
    return 0;
}

/*#include <iostream>
#include <typeinfo>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};

int main() {
    Base* basePtr = new B();
    
    // Приведение через указатель
    A* aPtr = dynamic_cast<A*>(basePtr);
    if (aPtr)
        std::cout << "Приведение к A* успешно\n";
    else
        std::cout << "Приведение к A* не удалось (nullptr)\n";

    // Приведение через ссылку
    try {
        A& aRef = dynamic_cast<A&>(*basePtr);
        std::cout << "Приведение к A& успешно\n";
    } catch (const std::bad_cast& e) {
        std::cout << "Приведение к A& не удалось: " << e.what() << "\n";
    }

    delete basePtr;
    return 0;
}

Приведение к A* не удалось (nullptr)
Приведение к A& не удалось: std::bad_cast
🔹 Вывод:

dynamic_cast<A*>(basePtr) вернул nullptr, так как basePtr на самом деле указывает на B.
dynamic_cast<A&>(*basePtr) выбросил std::bad_cast, так как привести B к A невозможно.
Это и есть ключевое различие между использованием dynamic_cast с указателями и ссылками. 🚀
*

Что происходит в этом примере?
Создается объект типа Derived, но указатель на него (basePtr) имеет тип Base*.
Мы пытаемся привести basePtr (указатель на Base) к типу Derived* с помощью dynamic_cast.
Если basePtr указывает на объект типа Derived или его подтип, то приведение пройдет успешно, и указатель derivedPtr будет указывать на объект типа Derived.
Если basePtr указывает на объект, который не является типом Derived, dynamic_cast вернет nullptr, и приведение не будет успешным.
В нашем примере приведение будет успешным, так как объект действительно является экземпляром класса Derived.
Зачем вообще это нужно?
Безопасность: Если бы вы использовали обычный static_cast, компилятор бы не проверял, действительно ли объект является экземпляром производного класса. Это могло бы привести к ошибкам, если бы указатель на базовый класс был на самом деле на объект другого типа.
Полиморфизм: Это важно в контексте полиморфизма, когда у вас есть код, работающий с объектами различных типов в иерархии классов. Вы не всегда знаете, какой именно производный класс будет использоваться, и вам нужно безопасно проверить и привести указатель или ссылку на базовый класс к типу производного класса, чтобы использовать его специфические методы.
Пример с ошибкой:
cpp
Copy
Edit
Base* basePtr = new Base();  // создаем объект Base
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Попытка привести Base* к Derived*

if (derivedPtr) {
    cout << "Приведение прошло успешно!" << endl;
} else {
    cout << "Приведение не удалось!" << endl;  // Это будет выведено, так как basePtr указывает на Base, а не на Derived
}
Здесь приведение не будет успешным, так как объект basePtr указывает на экземпляр Base, а не на Derived. В результате dynamic_cast вернет nullptr, и вы получите сообщение о том, что приведение не удалось.

Заключение:
dynamic_cast используется для безопасного приведения указателей или ссылок на базовый класс к производным классам, с проверкой корректности приведения во время выполнения. Это позволяет избежать ошибок, которые могут возникнуть при некорректном приведении типов, и гарантирует, что программа будет работать безопасно.
/