/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:03:18 by hkizrak-          #+#    #+#             */
/*   Updated: 2024/09/24 18:49:20 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB(){}

HumanB::HumanB(const std::string& name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon* weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon! " << std::endl;
}
