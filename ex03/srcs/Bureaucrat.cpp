/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:11:54 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/14 16:38:01 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include "color.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(75)
{
	//std::cout << C_CSTR << "Bureaucrat : Default constructor called" << RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	//std::cout << C_CSTR << "Bureaucrat : Ordinary constructor called" << RESET << std::endl;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	//std::cout << C_CSTR << "Bureaucrat : Copy constructor called" << RESET << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	//std::cout << C_ASNM << "Bureaucrat : Assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << C_DSTR << "Bureaucrat : Destructor called" << RESET << std::endl;
	return ;
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::promotion(void)
{
	if (this->_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade -= 1;
}

void	Bureaucrat::demotion(void)
{
	if (this->_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade += 1;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << this->_name << " couldn’t sign " << form.getName() << " beacause " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::execute(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat garde too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat garde too low");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return os;
}


