#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating ClapTrap:" << std::endl;
    ClapTrap clap("Clappy");
    std::cout << std::endl;

    std::cout << "Creating ScavTrap:" << std::endl;
    ScavTrap scav("Scavvy");
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

    std::cout << "Testing polymorphism:" << std::endl;
    ClapTrap* polyScav = new ScavTrap("PolyScav");
    polyScav->attack("target");
    delete polyScav;
    std::cout << std::endl;

    std::cout << "End of main" << std::endl;
    return 0;
}