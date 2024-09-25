#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public :
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(const MutantStack<T, Container> &src) : std::stack<T, Container>(src){}
		MutantStack& operator=(const MutantStack<T, Container> &rhs) {
			std::stack<T, Container>::operator=(rhs);
			return *this;
		}
		~MutantStack(){}

		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator riterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		riterator rbegin() {return this->c.rbegin();}
		riterator rend() {return this->c.rend();}
};

#endif
