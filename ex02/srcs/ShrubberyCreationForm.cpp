/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:55:40 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/13 15:15:44 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include "color.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 137, 145), _target("Default")
{
	std::cout << C_CSTR << "ShrubberyCreationForm : Default constrcutor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 137, 145), _target(target)
{
	std::cout << C_CSTR << "ShrubberyCreationForm : Ordinary constrcutor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << C_CSTR << "ShrubberyCreationForm : Copy constrcutor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << C_ASNM << "ShrubberyCreationForm : Assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << C_DSTR << "ShrubberyCreationForm :  Destructor called" << RESET << std::endl;
	return ;
}

void	ShrubberyCreationForm::execAction(void)
{
	std::ofstream file;

	file.open((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cout << RED << "Failed to open thios file" << RESET << std::endl;
		return ;
	}
	file <<"\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&&%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";	//credit : https://ascii.co.uk/art/tree jgs
}
