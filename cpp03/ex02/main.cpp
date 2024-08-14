#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "Creating ClapTrap:" << std::endl;
    ClapTrap clap("Clappy");
    std::cout << std::endl;

    std::cout << "Creating ScavTrap:" << std::endl;
    ScavTrap scav("Scavvy");
    std::cout << std::endl;

    std::cout << "Creating FragTrap:" << std::endl;
    FragTrap frag("Fraggy");
    std::cout << std::endl;

    std::cout << "Testing ClapTrap functions:" << std::endl;
    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    std::cout << std::endl;

    std::cout << "Testing ScavTrap functions:" << std::endl;
    scav.attack("target");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "Testing FragTrap functions:" << std::endl;
    frag.attack("target");
    frag.takeDamage(50);
    frag.beRepaired(30);
    frag.highFivesGuys();
    std::cout << std::endl;

    std::cout << "Testing polymorphism:" << std::endl;
    ClapTrap* polyScav = new ScavTrap("PolyScav");
    ClapTrap* polyFrag = new FragTrap("PolyFrag");
    polyScav->attack("target");
    polyFrag->attack("target");
    delete polyScav;
    delete polyFrag;
    std::cout << std::endl;

    std::cout << "End of main" << std::endl;
    return 0;
}