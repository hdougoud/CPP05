/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:13:40 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/14 16:36:46 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "color.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidental Pardon", 5, 25), _target("Default")
{
	//std::cout << C_CSTR << "PresidentialPardonForm : Default constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidental Pardon", 5, 25), _target(target)
{
	//std::cout << C_CSTR << "PresidentialPardonForm : Ordinary constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	//std::cout << C_CSTR << "PresidentialPardonForm : Ordinary constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	//std::cout << C_ASNM << "PresidentialPardonForm : Assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << C_DSTR << "PresidentialPardonForm : Destructor called" << RESET << std::endl;
	return ;
}

void	PresidentialPardonForm::execAction(void) const
{
		std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}


