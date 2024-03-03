#include <iostream>
#include <chrono>
#include <random>

int mass[100] = {}; // здесь мы вводим массив нужного размера 

//ВВЕДЕМ ВСЕ ФУНКЦИИ КОТОРЫЕ НАМ ПОНАДОБЯТСЯ

void mass(int size) {
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, size - 1);
    for (int count = 0; count < size; ++count) {
        mass[count] = dstr(rng);
    }
}


bool poisk_number(int beg, int end, int x){ // основная функция поиска простым перебором чреди первых чисел
    int size = end - beg + 1;
    for (int i = 0; i < size; ++i) {
        if (mass[i] == x) {
            return true;
        }
    }
    return false;
}


void rand_mass(int size) { // заполняет массив обратно, но уже отсортированными числами
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0,10);
    for (int count == 0; count < size; ++count) {
        if (count == 0) {
            mass[count] = dstr(rng);
        }
        else {
            mass[count] = mass [count - 1] + dstr(rng);
        }
    }
}


bool bin_poisk(int beg, int end, int x) { // бинарный поиск в некоторой части массива 
    int size = end - beg + 1;
    while (end >= beg) {
      int size = end - beg + 1;
      int mid = beg + size/2;
      if (mass[mid] == x) {
        return true;
      }  
      else if (mass[mid] > x) {
        end = mid - 1;
      }
      else {
        beg = mid + 1;
      }
    } 
    return false
}


float time(bool(*poisk)(int beg, int end, int x), int size, int x) { // считает время выполнения функции poisk и выводит полученное значение вместе с размером
    auto begin = std::chrono::steady_clock::now();
    for (int j = 0; j < repeat; ++j) {
        poisk(0, size - 1, x);
    }   
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return ((time_span.count() + 0.0)/repeat);
}


void data_max(void(*rand_mass)(int size), bool(*poisk)(int beg, int end, int x)) { //запускает функцию поиска, где ищет число, которого точно нет в массиве
    std::cout << "Максимальное количество данных для линейного поска \n";
    for (int size = 100; size <= 1000000; size += 9999) {
        rand_mass(size);
        std::cout << size << ' ' << poisk(poisk, size, -1) << '\n';
    }
    std::cout << '\n';
}


void data_mean(void(*rand_mass)(int size), bool(*poisk)(int beg, int end, int x)) { // Для длин массивов от 100 до 1000000 er раз заполняет массив случайными числами, а потом ищет в массиве случайное число и выводит время выполнения поиска и соотвествующий размер массива
    std::cout << "Средние данные для линейного поиска \n";
    int 
}