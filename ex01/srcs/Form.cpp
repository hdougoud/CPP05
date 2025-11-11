/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:46:19 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/11 15:19:09 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"

Form::Form() : _name("default"), _isSigned(0), _executionGrade(75), _signatureGrade(75)
{
	std::cout << C_CSTR << "Form : Default constructor called" << RESET << std::endl;
	return ;
}

Form::Form(const std::string &name, int executionGrade, int signatureGrade) :
	_name(name), _isSigned(0), _executionGrade(executionGrade), _signatureGrade(signatureGrade)
{
	if (_executionGrade < 1 || _signatureGrade < 1)
		throw Form::GradeTooHighException();
	if (_executionGrade > 150 || _signatureGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << C_CSTR << "Form : Ordinary constructor called" << RESET << std::endl;
	return ;
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned),
	_executionGrade(src._executionGrade), _signatureGrade(src._signatureGrade)
{
	std::cout << C_CSTR << "Form : Copy constructor called" << RESET << std::endl;
	return ;
}

Form	&Form::operator=(const Form &src)
{
	std::cout << C_ASNM << "Form : Assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << C_DSTR << "Form : Destructor called" << RESET << std::endl;
	return ;
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getExecutionGrade(void) const
{
	return (this->_executionGrade);
}

int	Form::getSignatureGrade(void) const
{
	return (this->_signatureGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
	{
		throw Form::alreadySignedException();
	}
	if (this->_signatureGrade < bureaucrat.getGrade())
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade to High");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade to Low");
}

const char	*Form::alreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

std::ostream	&operator<<(std::ostream &os, const Form &src)
{
	os << src.getName() << "\n"
	<< src.getIsSigned() << "\n"
	<< src.getExecutionGrade() << "\n"
	<< src.getExecutionGrade() << std::endl;
	return (os);
}


