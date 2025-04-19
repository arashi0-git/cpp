/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:38:01 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/19 09:46:24 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestSecret;

    public:
        std::string getfirst() const;
        std::string getlast() const;
        std::string getnick() const;
        std::string getnumber() const;
        std::string getsecret() const;

        void setfirst(std::string firstname);
        void setlast(std::string lastname);
        void setnick(std::string nickname);
        void setnumber(std::string phonenumber);
        void setsecret(std::string darkestSecret);
        bool isvalid() const;
};

#endif
