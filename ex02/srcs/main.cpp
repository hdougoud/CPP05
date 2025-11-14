/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/14 17:02:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void)
{
	ShrubberyCreationForm	home("Home");
	PresidentialPardonForm	pardon("Jeff");
	RobotomyRequestForm		robot("Fred");
	ShrubberyCreationForm	noSigned("No Signed");

	try
	{
		Bureaucrat	john("John", 10);
		john.signForm(home);
		john.signForm(pardon);
		john.signForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat	jeff("Jeff", 5);
		jeff.execute(home);
		jeff.execute(pardon);
		jeff.execute(robot);
		jeff.execute(noSigned);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat fred("Fred", 100);
		fred.execute(home);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}

