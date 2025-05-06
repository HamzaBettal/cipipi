/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:40:26 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/24 15:29:28 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
template <typename T>
class Array
{
    private:
        T               *data;
        unsigned int    _size;

    public:
        Array( void ) : data(), _size(1) {}
        Array( unsigned int n ) : data(new T[n]), _size(n){}

        Array &operator=( const Array &other )
        {
            if (this != &other)
            {
                delete[] data;
                _size = other.size();
                data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    data[i] = other.data[i];
            }
            return *this;
        }
        Array( const Array &other )
        {
            *this = other;
        }
        ~Array()
        {
            delete[] data;
        }
        
        T &operator[]( unsigned int arr)
        {
            if (arr >= _size)
                throw std::out_of_range("out of range!");
            return data[arr];
        }
        
        unsigned int size( void ) const
        {
            return _size;
        }
};
