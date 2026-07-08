#pragma once
#include "Creature.hpp"

namespace Game
{
    class Monster : public Creature
    {
    private:
        std::string type;
        std::string name;
        void setType(const std::string& t);
        void setName(const std::string& n);
        void setHealth(double h);
        void setDamage(double d);
        void setSpeed(double s);
        void setSpawnChance(double chance);
        void setAliveStatus(bool status);
    public:
        Monster();
        ~Monster();
        std::string getType() const;
        std::string getName() const;
        int getId() const;
        bool isAlive() const;
        double getHealth() const;
        double getDamage() const;
        double getSpeed() const;
        double getSpawnChance() const;
    };
}
