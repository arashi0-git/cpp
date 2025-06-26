#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        int _signGrade;
        int _execGrade;

    public:
        Form();
        Form(const std::string &name, int sign_grade, int exec_grade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        const std::string &getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif