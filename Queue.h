#pragma once

#include <iostream>
#include <vector>

using namespace std;

// Implementacija reda izvedena je na osvnou knjige profesora: Tomasevic, Milo, Algoritmi i strukture podataka, Akademska misao, 2008, str. ~  91.-108.

template <typename T>
class Queue
{
public:
	Queue(int capacity) : m_vector(capacity) {}
	Queue() {}
	
	void push(const T& podatak)
	{
		m_vector.push_back(podatak);
	}

	void pop() {
		m_vector.erase(m_vector.begin());
	}

	const T& front() const {
		return m_vector.front();
	}

	const T& back() const {
		return m_vector.back();
	}

private:
	std::vector<T> m_vector;
};

