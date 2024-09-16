#pragma once
#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutanStack : public std::stack<T, Container> {
	
};

#endif
