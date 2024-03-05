#pragma once
#include <iostream>
#include <vector>

using namespace std; 

// Implementacija steka izvedena je na osvnou knjige profesora: Tomasevic, Milo, Algoritmi i strukture podataka, Akademska misao, 2008, str. ~  61.-90.

template <typename T>
class Stack
{
public:
    Stack(int capacity) : m_vector(capacity) {}
    Stack() {}

    void push(const T& podatak)
    {
        m_vector.push_back(podatak);
    }

    bool pop() {
        if (empty()) {
            cout << "Stek je prazan!" << endl;
            return false;
        }

        m_vector.pop_back();
        return true;
    }

    const T& top() const {
        if (empty()) {
            cout << "Stek je prazan!" << endl;
        }

        return m_vector.back();
    }

    inline bool empty() const {
        return m_vector.empty();
    }
private:
    std::vector<T> m_vector;
};


