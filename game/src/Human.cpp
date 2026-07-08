#include "../include/Creature.hpp"
#include "../include/Human.hpp"
namespace Game
{
    Human::Human()
    {
        type = "Human";
        name = "Player";
        is_alive = true;
        health = 100.0;
        damage = 5.0;
        speed = 5.0;
        spawn_chance = 10.0;
    }

    Human::~Human()
    {
    }

    void Human::setGun(const std::string& g)
    {
        gun = g;
    }

    void Human::setHelmet(const std::string& h)
    {
        helmet = h;
    }

    std::string Human::getGun() const
    {
        return gun;
    }

    std::string Human::getHelmet() const
    {
        return helmet;
    }
}