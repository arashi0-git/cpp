#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150), _target("default") {}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade), _target(name) {
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name),
    _isSigned(other._isSigned),
    _signGrade(other._signGrade),
    _execGrade(other._execGrade),
    _target(other._target) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other){
        this->_isSigned = other._isSigned;
        _target = other._target;
    }
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

const std::string &AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm exception: grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm exception: grade too low";
}

const char *AForm::AFormNotSignedException::what() const throw() {
    return "AForm exception: form is not signed";
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}
AForm::AFormNotSignedException::~AFormNotSignedException() throw() {}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form \"" << f.getName() << "\", signed: " << (f.isSigned() ? "yes" : "no")
        << ", sign grade: " << f.getSignGrade()
        << ", exec grade: " << f.getExecGrade();
    return os;
}

