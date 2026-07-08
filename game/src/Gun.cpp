#include <cmath>
#include "../include/Gun.hpp"
#include "../include/Creature.hpp"

namespace Game
{
    Gun::Gun(const std::string &name, double damage, double fire_rate)
        : name(name), damage(damage), fire_rate(fire_rate)
    {
    }

    Gun::~Gun()
    {
    }

    std::string Gun::getName() const
    {
        return name;
    }

    double Gun::getDamage() const
    {
        return damage;
    }

    double Gun::getFireRate() const
    {
        return fire_rate;
    }

    bool Gun::fire(const Creature &shooter, Creature &target) const
    {
        if (!shooter.isAlive() || !target.isAlive()) {
            return false;
        }

        if (target.getXPosition() <= shooter.getXPosition()) {
            return false;
        }

        const double y_diff = std::abs(shooter.getYPosition() - target.getYPosition());
        const double max_line_tolerance = 1.0;
        if (y_diff > max_line_tolerance) {
            return false;
        }

        target.takeDamage(damage);
        return true;
    }
}