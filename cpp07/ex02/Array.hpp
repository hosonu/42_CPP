#ifndef ARRAY_HPP
#define ARRAY_HPP

#pragma once

#include <exception>
#include <iostream>

template <typename T> class Array {
	private :
		T* elements;
		unsigned int length;
	public :
		Array() : elements(NULL), length(0) {}
		Array(unsigned int n) : elements(new T[n]), length(n) {}
		Array(const Array &src) : elements(new T[src.length]), length(src.length) {
			for (unsigned int i = 0; i < length; i++) {
				this->elements[i] = src.elements[i];
			}
		}
		Array& operator=(const Array &rhs) {
			if (this != &rhs) {
				delete[] elements;
				this->length = rhs.length;
				this->elements = new T[this->length]();
				for (unsigned int i = 0; i < this->length; i++) {
					this->elements[i] = rhs.elements[i];
				}
			}
			return *this;
		}
		~Array() {
			delete [] elements;
		}

		T& operator[](unsigned int index) {
			if (index >= this->length)
				throw OutofBoundException();
			return elements[index];
		}
		
		const T& operator[](unsigned int index) const {
			if (index >= this->length)
				throw OutofBoundException();
			return elements[index];
		}

		unsigned int size() const {
			return this->length;
		}

		class OutofBoundException : public std::exception {
			public :
				const char *what() const throw() {
					return "Out of Bound";
				}
		};
};

#endif