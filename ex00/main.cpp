/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:54:19 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/06 15:35:31 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Usage: ./scalarConverter <C++ literal>" << std::endl;
		return 1;
	}

	try {
		ScalarConverter::convert(av[1]);
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
