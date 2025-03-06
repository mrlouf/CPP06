/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:20:59 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/06 15:59:06 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

bool ScalarConverter::isChar(const std::string &literal) {
	if (literal.length() != 1)
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string &literal) {
	for (size_t i = 0; i < literal.length(); i++) {
		if (!i && (literal[i] == '+' || literal[i] == '-'))
			continue;
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal) {
	
	// pseudo literals
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" )
		return true;

	bool flag = false;	// flag to check decimal point

	for (size_t i = 0; i < literal.length() - 1; i++) {
		if (!i && (literal[i] == '+' || literal[i] == '-'))
			continue;
		if (!isdigit(literal[i])) {
			if (!flag && literal[i] == '.')
				flag = true;
			else
				return false;
		}
	}
	// check for suffix 'f'
	if (literal[literal.length() - 1] != 'f')
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &literal) {
	
	// pseudo literals
	if (literal == "-inf" || literal == "+inf" || literal == "nan" )
		return true;

	bool flag = false;

	for (size_t i = 0; i < literal.length(); i++) {
		if (!i && (literal[i] == '+' || literal[i] == '-'))
			continue;
		if (!isdigit(literal[i])) {
			if (!flag && literal[i] == '.')
				flag = true;
			else
				return false;
		}
	}
	return true;
}

char ScalarConverter::toChar(const std::string &literal) {
	std::istringstream ss(literal);
	char res;
	ss >> res;
	if (ss.fail())
		throw ImpossibleConversionException();
	return res;
}

int ScalarConverter::toInt(const std::string &literal) {
	std::istringstream ss(literal);
	int res;
	ss >> res;
	if (ss.fail())
		throw ImpossibleConversionException();
	return res;
}

float ScalarConverter::toFloat(const std::string &literal) {
	std::istringstream ss(literal);
	float res;
	ss >> res;
	if (ss.fail())
		throw ImpossibleConversionException();
	return res;
}

double ScalarConverter::toDouble(const std::string &literal) {
	std::istringstream ss(literal);
	double res;
	ss >> res;
	if (ss.fail())
		throw ImpossibleConversionException();
	return res;
}

void ScalarConverter::convert(const std::string &literal) {

	try {
// !Implement the conversion/printing
	}
	catch (const std::exception &e) {

	}
}

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* ScalarConverter::ImpossibleConversionException::what() const throw() {
	return "impossible";
}
