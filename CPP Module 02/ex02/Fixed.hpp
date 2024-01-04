/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:36:27 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/14 14:36:29 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:

		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed & operator=(Fixed const & rhs);
		static Fixed & min(Fixed & lhs, Fixed & rhs);
		static Fixed const & min(Fixed const & lhs, Fixed const & rhs);
		static Fixed & max(Fixed & lhs, Fixed & rhs);
		static Fixed const & max(Fixed const & lhs, Fixed const & rhs);

/*		Arithmetic operators		*/
		Fixed operator+(Fixed const & rhs);
		Fixed operator-(Fixed const & rhs);
		Fixed operator*(Fixed const & rhs);
		Fixed operator/(Fixed const & rhs);

/*		Comparison operators		*/
		bool	operator< (Fixed const & rhs);
		bool	operator> (Fixed const & rhs);
		bool	operator<=(Fixed const & rhs);
		bool	operator>=(Fixed const & rhs);
		bool	operator==(Fixed const & rhs);
		bool	operator!=(Fixed const & rhs);

/*		In-Decrement operators		*/
		Fixed & operator++();
		Fixed	operator++(int);
		Fixed & operator--();
		Fixed	operator--(int);


		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int	_n;
		static const int _bits;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
