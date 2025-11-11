/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:46:19 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/11 15:42:16 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"

AForm::AForm() : _name("default"), _isSigned(0), _executionGrade(75), _signatureGrade(75)
{
	std::cout << C_CSTR << "AForm : Default constructor called" << RESET << std::endl;
	return ;
}

AForm::AForm(const std::string &name, int executionGrade, int signatureGrade) :
	_name(name), _isSigned(0), _executionGrade(executionGrade), _signatureGrade(signatureGrade)
{
	if (_executionGrade < 1 || _signatureGrade < 1)
		throw AForm::GradeTooHighException();
	if (_executionGrade > 150 || _signatureGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << C_CSTR << "AForm : Ordinary constructor called" << RESET << std::endl;
	return ;
}

AForm::AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned),
	_executionGrade(src._executionGrade), _signatureGrade(src._signatureGrade)
{
	std::cout << C_CSTR << "AForm : Copy constructor called" << RESET << std::endl;
	return ;
}

AForm	&AForm::operator=(const AForm &src)
{
	std::cout << C_ASNM << "AForm : Assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << C_DSTR << "AForm : Destructor called" << RESET << std::endl;
	return ;
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getExecutionGrade(void) const
{
	return (this->_executionGrade);
}

int	AForm::getSignatureGrade(void) const
{
	return (this->_signatureGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
	{
		throw AForm::alreadySignedException();
	}
	if (this->_signatureGrade < bureaucrat.getGrade())
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_isSigned = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade to High");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade to Low");
}

const char	*AForm::alreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

std::ostream	&operator<<(std::ostream &os, const AForm &src)
{
	os << src.getName() << "\n"
	<< src.getIsSigned() << "\n"
	<< src.getExecutionGrade() << "\n"
	<< src.getExecutionGrade() << std::endl;
	return (os);
}


