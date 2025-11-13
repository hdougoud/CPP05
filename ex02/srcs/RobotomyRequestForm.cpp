/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:36:50 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/13 15:14:33 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "color.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 5, 25), _target("Default")
{
	std::cout << C_CSTR << "RobotomyRequestForm : Default constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 5, 25), _target(target)
{
	std::cout << C_CSTR << "RobotomyRequestForm : Ordinary constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target)
{
	std::cout << C_CSTR << "RobotomyRequestForm : Ordinary constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << C_ASNM << "RobotomyRequestForm : Assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << C_DSTR << "RobotomyRequestForm : Destructor called" << RESET << std::endl;
	return ;
}

void	RobotomyRequestForm::execAction(void)
{
	std::cout << "Bzzzz Zzzz Bzzz Zzzzzz\n";
	std::srand(std::time(NULL));
	if (rand() % 2)
	{
		std::cout << GREEN << this->_target << " has been robotomized successfully" << RESET << std::endl;
		return ;
	}
	std::cout << RED << this->_target << " has not been robotised, the operation has failed" << RESET << std::endl;
}
