#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

    // Вспомогательный метод для изменения размера массива
    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // Конструктор по умолчанию
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Конструктор с заданным размером
    Vector(int _Capacity) : size(0), capacity(_Capacity) {
        data = new T[capacity];
    }

    // Копирующий конструктор
    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Метод для получения размера вектора
    int getSize() const {
        return size;
    }

    // Метод для получения элемента по индексу
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return data[index];
    }

    // Метод для добавления элемента в конец вектора
    void pushBack(const T& value) {
        if (size == capacity) {
            resize(capacity * 2 + 1); // Удваиваем емкость, если она заполнена
        }
        data[size++] = value;
    }

    // Метод для удаления элемента по индексу
    void erase(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне диапазона");
        }

        // Меняем местами удаляемый элемент с последним
        data[index] = data[size - 1];
        size--; // Уменьшаем размер вектора
    }
};
#endif
