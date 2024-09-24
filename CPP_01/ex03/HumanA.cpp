/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:03:10 by hkizrak-          #+#    #+#             */
/*   Updated: 2024/09/24 18:47:19 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA(){}

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

