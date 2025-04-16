/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:30:15 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/16 21:02:22 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char *av[])
{
  if (ac > 1){
    for(int i =0; i<ac;++i){
      if(i == 0){
        std::cout << av[i] << std::flush;
        std::cout << " " << std::flush;
      }
      else {
        for(int j =0; av[i][j]!= 0; ++j){
          std::cout << static_cast<char>(std::toupper(av[i][j]));
        }
      }
    }
    std::cout << std::endl;
  }
  else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }
  return 0;
}
