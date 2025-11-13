/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:07:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/13 14:55:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void	signForm(int bureaucratGrade, int executionGrade, int signatureGrade);
void	doubleSignature(int bureaucratGrade, int executionGarde, int signatureGrade);

int main (void)
{
	RobotomyRequestForm robot;

	robot.execAction();
	return (0);
}

