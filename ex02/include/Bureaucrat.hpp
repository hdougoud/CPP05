/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:17:20 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/14 12:03:47 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();
		
		class	GradeTooHighException;
		class	GradeTooLowException;
		const	std::string &getName(void) const;
		int		getGrade(void) const;
		void	promotion(void);
		void	demotion(void);
		void	signForm(AForm &form) const;
		void	execute(AForm  const &form) const;
	private:
		const std::string	_name;
		int					_grade;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);
