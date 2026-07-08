#include "../include/Monster.hpp"

namespace Game
{
    Monster::Monster()
    {
        type = "Monster";
        name = "Monster";
        is_alive = true;
        health = 50.0;
        damage = 10.0;
        speed = 3.0;
        spawn_chance = 5.0;
    }

    Monster::~Monster()
    {
    }

    void Monster::setType(const std::string& t)
    {
        type = t;
    }

    void Monster::setName(const std::string& n)
    {
        name = n;
    }

    std::string Monster::getType() const
    {
        return type;
    }

    std::string Monster::getName() const
    {
        return name;
    }

    void Monster::setHealth(double h)
    {
        health = h;
    }

    void Monster::setDamage(double d)
    {
        damage = d;
    }

    void Monster::setSpeed(double s)
    {
        speed = s;
    }

    void Monster::setSpawnChance(double chance)
    {
        spawn_chance = chance;
    }

    void Monster::setAliveStatus(bool status)
    {
        is_alive = status;
    }

    int Monster::getId() const
    {
        return id;
    }

    bool Monster::isAlive() const
    {
        return is_alive;
    }

    double Monster::getHealth() const
    {
        return health;
    }

    double Monster::getDamage() const
    {
        return damage;
    }

    double Monster::getSpeed() const
    {
        return speed;
    }

    double Monster::getSpawnChance() const
    {
        return spawn_chance;
    }
}