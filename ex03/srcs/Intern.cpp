/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:07:17 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/14 18:57:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

static std::string functList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

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

	AForm	form;
	for(int i = 0; i < 3; i++)
	{
		if (name == functList[i])
	}
	return (form);
}

