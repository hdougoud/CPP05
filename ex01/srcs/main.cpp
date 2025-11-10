/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/10 19:21:39 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"
#include "Form.hpp"

void	hireBureaucrat(const std::string &name, int grade);
void	createForm(const std::string &name, int executionGrade, int signatureGrade);

int main (void)
{
	try
	{
		Bureaucrat	fred("Fred", 100);
		Bureaucrat	john("John", 30);
		Bureaucrat	josh("Josh", 10);
		Form		form("Pearl Harbor", 50, 25);

		fred.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}
	return (0);
}

