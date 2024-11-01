#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

    // �ᯮ����⥫�� ��⮤ ��� ��������� ࠧ��� ���ᨢ�
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
    // ��������� �� 㬮�砭��
    Vector() : data(nullptr), size(0), capacity(0) {}

    // ��������� � ������� ࠧ��஬
    Vector(int _Capacity) : size(0), capacity(_Capacity) {
        data = new T[capacity];
    }

    // �������騩 ���������
    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // ������ ��ᢠ������
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

    // ��������
    ~Vector() {
        delete[] data;
    }

    // ��⮤ ��� ����祭�� ࠧ��� �����
    int getSize() const {
        return size;
    }

    // ��⮤ ��� ����祭�� ����� �� �������
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("������ ��� ���������");
        }
        return data[index];
    }

    // ��⮤ ��� ���������� ����� � ����� �����
    void pushBack(const T& value) {
        if (size == capacity) {
            resize(capacity * 2 + 1); // ��������� �������, �᫨ ��� ���������
        }
        data[size++] = value;
    }

    // ��⮤ ��� 㤠����� ����� �� �������
    void erase(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("������ ��� ���������");
        }

        // ���塞 ���⠬� 㤠�塞� ����� � ��᫥����
        data[index] = data[size - 1];
        size--; // �����蠥� ࠧ��� �����
    }
};
#endif