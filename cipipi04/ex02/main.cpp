/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:53:54 by hbettal           #+#    #+#             */
/*   Updated: 2024/11/26 17:35:43 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const Animal* k = new Animal();

    i->makeSound();
    j->makeSound();
    // k->makeSound();
    delete j;
    delete i;
    // delete k;
    return 0;
}
