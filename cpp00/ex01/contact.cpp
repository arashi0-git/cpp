/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:23:31 by aryamamo          #+#    #+#             */
/*   Updated: 2025/05/27 19:57:24 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setfirst(std::string fn)
{
    this->firstname = fn;
}

void Contact::setlast(std::string ln)
{
    this->lastname = ln;
}

void Contact::setnick(std::string nn){
    this->nickname = nn;
}

void Contact::setnumber(std::string pn){
    this->phonenumber = pn;
}

void Contact::setsecret(std::string ds){
    this->darkestSecret = ds;
}

std::string Contact::getfirst() const{
    return (this->firstname);
}

std::string Contact::getlast() const{
    return (this->lastname);
}

std::string Contact::getnick() const{
    return (this->nickname);
}

std::string Contact::getnumber() const{
    return (this->phonenumber);
}

std::string Contact::getsecret() const{
    return (this->darkestSecret);
}

bool Contact::isvalid() const {
    return (!firstname.empty()&&!lastname.empty()&&!nickname.empty()&&!phonenumber.empty()&&!darkestSecret.empty());
}

