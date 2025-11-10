/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:46:28 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/10 13:20:57 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &name, int executionGrade, int signatureGrade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

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

class Form::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Form::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Form::alreadySignedException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

std::ostream	&operator<<(std::ostream &os, const Form &src);
