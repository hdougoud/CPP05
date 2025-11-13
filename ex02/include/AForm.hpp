/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:46:28 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/13 14:52:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, int executionGrade, int signatureGrade);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		~AForm();

		class GradeTooHighException;
		class GradeTooLowException;
		class alreadySignedException;
		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getExecutionGrade(void) const;
		int					getSignatureGrade(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_executionGrade;
		const int			_signatureGrade;
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class AForm::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class AForm::alreadySignedException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

std::ostream	&operator<<(std::ostream &os, const AForm &src);
