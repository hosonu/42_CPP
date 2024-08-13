#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &src);
		~Fixed();

		Fixed&	operator=(const Fixed &rhs);
		Fixed			operator+(Fixed const &rhs) const;
		Fixed			operator-(Fixed const &rhs) const;
		Fixed			operator*(Fixed const &rhs) const;
		Fixed			operator/(Fixed const &rhs) const;
		bool			operator<(Fixed const &rhs) const;
		bool			operator>(Fixed const &rhs) const;
		bool			operator<=(Fixed const &rhs) const;
		bool			operator>=(Fixed const &rhs) const;
		bool			operator==(Fixed const &rhs) const;
		bool			operator!=(Fixed const &rhs) const;
		Fixed&			operator++();
		Fixed			operator++(int);
		Fixed&			operator--();
		Fixed			operator--(int);


		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int	toInt( void ) const;

		static Fixed&			min(Fixed &a, Fixed &b);
		static Fixed const&	min(Fixed const &a, Fixed const &b);
		static Fixed&			max(Fixed &a, Fixed &b);
		static Fixed const&	max(Fixed const &a, Fixed const &b);		
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
