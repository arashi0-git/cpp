/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:51:49 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/19 10:05:34 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

int main(){
    PhoneBook phonebook;
    std::string command;

    while(true){
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if(command == "ADD") {
            Contact c;
            std::string fn, ln, nn, pn, ds;
            std::cout << "First Name: "; std::getline(std::cin, fn);c.setfirst(fn);
            std::cout << "Last Name: "; std::getline(std::cin, ln); c.setlast(ln);
            std::cout << "Nick Name: "; std::getline(std::cin, nn); c.setnick(nn);
            std::cout << "Phone Number: "; std::getline(std::cin, pn); c.setnumber(pn);
            std::cout << "Darkest Secret: "; std::getline(std::cin, ds); c.setsecret(ds);
            if(c.isvalid())
                phonebook.addcontact(c);
            else
                std::cout << "All fields must be filled." << std::endl;
        }
        else if (command == "SEARCH") {
            phonebook.displaycontacts();
            std::cout << "Enter index to display details: ";
            std::string indexstr;
            std::getline(std::cin, indexstr);
            int index = std::atoi(indexstr.c_str());
            phonebook.displaydetails(index);
        }
        else if (command == "EXIT"){
            break;
        }
        else {
            std::cout << "Unknown command." << std::endl;
        }
    }
    return 0;
}
