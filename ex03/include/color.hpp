/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:28:06 by hdougoud          #+#    #+#             */
/*   Updated: 2025/10/30 11:37:28 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# define GREEN			"\033[38;5;47m"
# define BLUE			"\033[38;5;117m"
# define RED			"\033[38;5;9m"
# define YELLOW			"\033[38;5;220m"

//C++ Colors
# define C_CSTR			"\033[38;5;10m"		//Constructor color
# define C_ASNM			"\033[38;5;117m"	//Assignment operator
# define C_DSTR			"\033[38;5;202m"	//Destructor color

//Format
# define F_BOLD			"\033[1m"
# define F_UNDERLINED	"\033[4m"

# define RESET			"\033[0m"

#endif
