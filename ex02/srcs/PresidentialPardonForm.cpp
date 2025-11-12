/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:13:40 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/12 20:46:10 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "color.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidental Pardon", 5, 25), _target("Default")
{
	std::cout << C_CSTR << "PresidentialPardonForm : Default constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidental Pardon", 5, 25), _target(target)
{
	std::cout << C_CSTR << "PresidentialPardonForm : Ordinary constructor called" << RESET << std::endl;
	return ;
}
