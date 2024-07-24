/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hoyuki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:11:08 by hosonu            #+#    #+#             */
/*   Updated: 2024/06/12 01:11:12 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
	std::string arg;
	for (int i = 1; i < argc; i++)
	{
		arg = argv[i];
		std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
		std::cout << arg;
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
