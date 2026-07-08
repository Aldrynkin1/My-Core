#include "../include/Creature.hpp"
namespace Game
{
    Creature::Creature()
        : id(0),
          name(""),
          type(""),
          is_alive(false),
          health(0.0),
          damage(0.0),
          speed(0.0),
          spawn_chance(0.0),
          armor(0.0),
          x_position(0.0),
          y_position(0.0),
          level(1),
          experience(0),
          gold(0.0)
    {
    }

    Creature::~Creature()
    {
    }

    void Creature::setPosition(double x, double y)
    {
        x_position = x;
        y_position = y;
    }
    
    void Creature::setLevel(int lvl)
    {
        level = lvl;
    }

    void Creature::setExperience(int exp)
    {
        experience = exp;
    }

    void Creature::setGold(double g)
    {
        gold = g;
    }

    void Creature::setHealth(double h)
    {
        health = h;
    }

    void Creature::setDamage(double d)
    {
        damage = d;
    }

    void Creature::setSpeed(double s)
    {
        speed = s;
    }

    void Creature::setSpawnChance(double chance)
    {
        spawn_chance = chance;
    }

    void Creature::setAliveStatus(bool status)
    {
        is_alive = status;
    }

    int Creature::getId() const
    {
        return id;
    }

    std::string Creature::getName() const
    {
        return name;
    }

    std::string Creature::getType() const
    {
        return type;
    }

    bool Creature::isAlive() const
    {
        return is_alive;
    }

    double Creature::getHealth() const
    {
        return health;
    }

    double Creature::getDamage() const
    {
        return damage;
    }

    double Creature::getSpeed() const
    {
        return speed;
    }

    double Creature::getSpawnChance() const
    {
        return spawn_chance;
    }

    double Creature::getXPosition() const
    {
        return x_position;
    }

    double Creature::getYPosition() const
    {
        return y_position;
    }

    int Creature::getLevel() const
    {
        return level;
    }

    int Creature::getExperience() const
    {
        return experience;
    }

    double Creature::getGold() const
    {
        return gold;
    }

    void Creature::takeDamage(double amount)
    {
        if (!is_alive) {
            return;
        }

        health -= amount;
        if (health <= 0.0) {
            health = 0.0;
            is_alive = false;
        }
    }

    void Creature::setArmor(double a)
    {
        armor = a;
    }

    double Creature::getArmor() const
    {
        return armor;
    }
}
