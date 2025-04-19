/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:45:01 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/19 14:26:51 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(0), totalcontacts(0){}

void PhoneBook::addcontact(const Contact &contact){
    contacts[index] = contact;
    index = (index + 1) % 8;
    if(totalcontacts < 8) totalcontacts++;
}


static std::string formatField(const std::string &field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return field;
}

void PhoneBook::displaycontacts() const {
    std::cout << std::setw(10)<< "Index" << "|"
        <<std::setw(10) << "First Name" << "|"
        <<std::setw(10) << "Last Name" << "|"
        <<std::setw(10) << "Nick Name" << std::endl;


    for (int i = 0; i < totalcontacts; ++i){
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getfirst()) << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getlast()) << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getnick()) << std::endl;
    }
}

void PhoneBook::displaydetails(int index) const {
    if (index < 0 || index >= totalcontacts){
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    const Contact &c = contacts[index];
    std::cout << "First Name: " << c.getfirst() << std::endl;
    std::cout << "Last Name: " << c.getlast() << std::endl;
    std::cout << "Nick Name: " << c.getnick() << std::endl;
    std::cout << "Phone Number: " << c.getnumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getsecret() << std::endl;
}

int PhoneBook::gettotalcontacts() const {
    return totalcontacts;
}

