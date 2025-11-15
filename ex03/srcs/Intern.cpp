/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:07:17 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/15 21:44:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <exception>
#include <iostream>
#include "AForm.hpp"
#include "color.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

static std::string	formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern()
{
	return ;
}

Intern::Intern(const Intern &src)
{
	(void) src;
	return ;
}

Intern	&Intern::operator=(const Intern &src)
{
	if (this != &src)
	{

	}
	return (*this);
}

Intern::~Intern()
{
	return ;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	int i = 0;

	while (i < 3)
	{
		if (name == formName[i])
			break ;
		i++;
	}
	try
	{
		switch (i)
		{
			case 0:
				return (new ShrubberyCreationForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new PresidentialPardonForm(target));
			default:
				std::cout << YELLOW << "No form with this name" << RESET << std::endl;
				return (0);
				
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return (0);
	}
}

