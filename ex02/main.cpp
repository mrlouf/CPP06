/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:03:22 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 16:26:03 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int	main()
{
	srand(time(0));
	Base *ptr = generate();

	std::cout << "Identify from pointer: ";
	identify(ptr);

	std::cout << "Identify from reference: ";
	identify(*ptr);

	delete ptr;
	
	return (0);
}
