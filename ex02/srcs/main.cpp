/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/11 15:30:17 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"
#include "Form.hpp"

void	signForm(int bureaucratGrade, int executionGrade, int signatureGrade);
void	doubleSignature(int bureaucratGrade, int executionGarde, int signatureGrade);

int main (void)
{
	signForm(-1, 50, 50);
	signForm(10, -1, 50);
	signForm(10, 50, -1);
	signForm(10, 151, 50);
	signForm(10, 50, 151);
	signForm(10, 50, 50);
	signForm(140, 50, 50);
	doubleSignature(45, 46, 46);
	return (0);
}

void	signForm(int bureaucratGrade, int executionGrade, int signatureGrade)
{
	try
	{
		Bureaucrat	bureaucrat("John", bureaucratGrade);
		Form		form("Pearl Harbor", executionGrade, signatureGrade);
		
		bureaucrat.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}
	std::endl(std::cout);
}

void	doubleSignature(int bureaucratGrade, int executionGarde, int signatureGrade)
{
	try
	{
		Bureaucrat	john("John", bureaucratGrade);
		Bureaucrat	fred("Fred", bureaucratGrade);
		Form		form("Apollo", executionGarde, signatureGrade);

		fred.signForm(form);
		john.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}
}
