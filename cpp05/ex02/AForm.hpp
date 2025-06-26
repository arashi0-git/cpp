#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        int _signGrade;
        int _execGrade;

    public:
        AForm();
        AForm(const std::string &name, int sign_grade, int exec_grade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();

        const std::string &getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
                virtual ~GradeTooHighException() throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
                virtual ~GradeTooLowException() throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif