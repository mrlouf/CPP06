/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:41:41 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/09 15:04:30 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data {
	private:
	public:
		Data();
		Data(const Data &other);
		~Data();
		Data &operator=(const Data &other);

		Data(const int &i);

		const int value;
};

#endif
