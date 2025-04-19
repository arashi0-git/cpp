/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:27:11 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/18 19:33:05 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef phonebook_HPP
#define phonebook_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
public:
    PhoneBook();
    void addcontact(const Contact& contact);
    void displaycontacts() const;
    void displaydetails(int index) const;
    int gettotalcontacts() const;

private:
    Contact contacts[8];
    int index;
    int totalcontacts;

};

#endif