#ifndef WHATEVER_HPP
#define WHATEER_HPP

template <typename T>
void	swap(T& a, T& b) {
	T t;
	t = a;
	a = b;
	b = t;
}

template <typename T>
T max(T& a, T& b) {
	if (a == b)
		return b;
	return a > b ? a : b;
}

template <typename T>
T min(T& a, T& b) {
	if (a == b)
		return b;
	return a < b ? a : b;
}

#endif