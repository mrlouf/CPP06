/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:10:01 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/09 15:45:25 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Usage: ./serializer <any_value>" << std::endl;
		return (1);
	}

	// instanciate Data with av[1] converted to int;
	Data *ptr = new Data(atoi(av[1]));

	uintptr_t raw = Serializer::serialize(ptr);
	
	std::cout << "Serialised value: " << raw << std::endl;

	Data *tmp = Serializer::deserialize(raw);
	std::cout << "Deserialised value: " << tmp->value << std::endl;

	delete ptr;
	return (0);
}
