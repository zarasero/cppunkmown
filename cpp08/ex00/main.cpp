#include "easyfind.hpp"

int main() {
    try {
        // Пример с вектором (vector)
        std::vector<int> vec;  // Инициализируем пустой вектор
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(7);

        std::cout << "Looking for the number 3 in the vector: " << easyfind(vec, 3) << std::endl;
        std::cout << "Looking for the number 10 in the vector: " << easyfind(vec, 10) << std::endl;  // Этот вызов бросит исключение

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Ловим исключение и выводим сообщение об ошибке
    }

    try {
        // Пример с двусвязным списком (list)
        std::list<int> lst;  // Инициализируем пустой список
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::cout << "Looking for the number 20 in the list: " << easyfind(lst, 20) << std::endl;
        std::cout << "Looking for the number 100 in the list: " << easyfind(lst, 100) << std::endl;  // Этот вызов бросит исключение

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Ловим исключение и выводим сообщение об ошибке
    }

    try {
        // Пример с деком (deque)
        std::deque<int> deq;  // Инициализируем пустой дек
        deq.push_back(5);
        deq.push_back(15);
        deq.push_back(25);
        deq.push_back(35);
        deq.push_back(45);

        std::cout << "Looking for the number 25 in the deque: " << easyfind(deq, 25) << std::endl;
        std::cout << "Looking for the number 50 in the deque: " << easyfind(deq, 50) << std::endl;  // Этот вызов бросит исключение

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Ловим исключение и выводим сообщение об ошибке
    }

    try {
        // Пример с массивом (array) — не ассоциативный контейнер
        int arr[] = {100, 200, 300, 400};  // Обычный массив
        int arrSize = sizeof(arr) / sizeof(arr[0]);  // Вычисляем размер массива

        std::vector<int> vecFromArr(arr, arr + arrSize);  // Создаем вектор на основе массива

        std::cout << "Looking for the number 300 in the arr/vect: " << easyfind(vecFromArr, 300) << std::endl;
        std::cout << "Looking for the number 500 in the arr/vect: " << easyfind(vecFromArr, 500) << std::endl;  // Этот вызов бросит исключение

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Ловим исключение и выводим сообщение об ошибке
    }

    return 0;
}