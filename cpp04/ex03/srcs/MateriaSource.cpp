#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    std::cout << "[MateriaSource] default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; ++i) {
        templates[i] = other.templates[i] ? other.templates[i]->clone() : NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; ++i) {
            delete templates[i];
            templates[i] = rhs.templates[i] ? rhs.templates[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "[MateriaSource] destructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; ++i) {
        if (templates[i] == NULL) {
            templates[i] = m;
            return;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return NULL;
}
