/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:20:59 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/07 14:43:45 by nponchon         ###   ########.fr       */
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

	if (literal == "-inff" || literal == "+inff" || literal == "nanf" )
		return true;

	if (literal[literal.size() - 1] != 'f' && literal[literal.size() - 1] != 'F')
		return false;

    std::string tmp = literal;
    tmp = literal.substr(0, literal.size() - 1);

	errno = 0;
	char *end;
	strtof(tmp.c_str(), &end);
	if (errno == ERANGE || *end != '\0')
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &literal) {
	
	if (literal == "-inf" || literal == "+inf" || literal == "nan" )
		return true;

	errno = 0;
	char *end;
	strtod(literal.c_str(), &end);
	if (errno == ERANGE || *end != '\0')
		return false;
	return true;
}

char ScalarConverter::toChar(const std::string &literal)
{
	if (literal.length() != 1)
		throw ImpossibleConversionException();

	char res = literal[0];
	if (!isprint(res))
		throw NonDisplayableException();

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

	// std::cout << isChar(literal) << std::endl;
	// std::cout << isInt(literal) << std::endl;
	// std::cout << isFloat(literal) << std::endl;
	// std::cout << isDouble(literal) << std::endl;

	// char
	try {
		if (isChar(literal))
			std::cout << "char: " << literal << std::endl;
		else {
			char c = toChar(literal);
			std::cout << "char: " << static_cast<char>(c) << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	// int
	try {
		if (isInt(literal))
			std::cout << "int: " << literal << std::endl;
		else {
			int i = toInt(literal);
			std::cout << "int: " << i << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	// float
	try {
		if (isFloat(literal))
			std::cout << "float: " << literal << std::endl;
		else {
			float f = toFloat(literal);
			std::cout << std::setprecision(1) << "float: " << f << "f" << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}

	// double
	try {
		if (isDouble(literal))
			std::cout << "double: " << literal << std::endl;
		else {
			double d = toDouble(literal);
			std::cout << std::setprecision(1) << "double: " << d << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

const char* ScalarConverter::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* ScalarConverter::ImpossibleConversionException::what() const throw() {
	return "impossible";
}
