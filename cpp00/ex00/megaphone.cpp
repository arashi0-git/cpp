/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:30:15 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/17 15:44:16 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

char ft_toupper(char c){
  if(c>='a'&&c<='z')
    return ((c -=32));
  return (c);
}

int main(int ac, char *av[])
{
  if (ac > 1){
    for(int i =1; i<ac;++i){
        for(int j =0; av[i][j]!= 0; ++j){
          std::cout << ft_toupper(av[i][j]);
      }
    }
    std::cout << std::endl;
  }
  else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }
  return 0;
}
