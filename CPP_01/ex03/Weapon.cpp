/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:04:17 by hkizrak-          #+#    #+#             */
/*   Updated: 2024/09/24 18:47:42 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	this->type = type;
}


Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
