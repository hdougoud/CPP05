/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/15 22:48:56 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "color.hpp"
#include "Intern.hpp"

void	signForm(Bureaucrat bureaucrat, AForm *form);
void	executeForm(Bureaucrat bureaucrat, AForm *form);

int main (void)
{
	Intern	someRandomIntern;

	AForm	*shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
	AForm	*robotomy = someRandomIntern.makeForm("robotomy request", "John");
	AForm	*presidential = someRandomIntern.makeForm("presidential pardon", "Fred");
	AForm	*dontExist = someRandomIntern.makeForm("dontExist", "unknow");

	try
	{
		Bureaucrat	john("John", 5);
		signForm(john, shrubbery);
		signForm(john, robotomy);
		signForm(john, presidential);
		signForm(john, dontExist);
		executeForm(john, shrubbery);
		executeForm(john, robotomy);
		executeForm(john, presidential);
		executeForm(john, dontExist);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	delete shrubbery;
	delete robotomy;
	delete presidential;
	delete dontExist;
	return (0);
}

void	signForm(Bureaucrat bureaucrat, AForm *form)
{
	if (!form)
	{
		std::cout << RED << "This form is not in the correct format" << RESET << std::endl;
		return ;
	}
	bureaucrat.signForm(*form);
}

void	executeForm(Bureaucrat bureaucrat, AForm *form)
{
	if (!form)
	{
		std::cout << RED << "This form is not in the correct format" << RESET << std::endl;
		return ;
	}
	bureaucrat.execute(*form);
}
