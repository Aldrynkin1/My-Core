#pragma once
#include <string>

namespace Game
{
    class Creature;

    class Gun
    {
    protected:
        std::string name;
        double damage;
        double fire_rate;

    public:
        Gun(const std::string &name, double damage, double fire_rate);
        ~Gun();

        std::string getName() const;
        double getDamage() const;
        double getFireRate() const;
        bool fire(const Creature &shooter, Creature &target) const;
    };
}
