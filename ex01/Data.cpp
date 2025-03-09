/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:50:02 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/09 15:05:42 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : value(0) {}
Data::Data(const Data &other) : value(other.value) {}
Data::~Data() {}
Data &Data::operator=(const Data &other) {
	(void)other;
	return *this;
}

// constructor taking int
Data::Data(const int &i) : value(i) {}
