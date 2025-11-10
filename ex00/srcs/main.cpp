/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/08 21:49:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"

void	hireBureaucrat(const std::string &name, int grade);

int main (void)
{
	hireBureaucrat("John", 10);
	hireBureaucrat("Fred", 0);
	hireBureaucrat("Anne", 151);
	hireBureaucrat("Jeff", 1);
	hireBureaucrat("Sara", 150);
	return (0);
}

void	hireBureaucrat(const std::string &name, int grade)
{
	std::cout << F_BOLD << F_UNDERLINED << "job interview with " << name << RESET << std::endl;;
	try
	{
		Bureaucrat	bureaucrat(name, grade);
		try 
		{
			bureaucrat.promotion();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << bureaucrat << std::endl;
		try
		{
			bureaucrat.demotion();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::endl(std::cout);
}
