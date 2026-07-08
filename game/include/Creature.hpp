#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace Game
{
    class Creature
    {
    protected:
        int id;
        std::string name;
        std::string type;
        bool is_alive;
        double health;
        double damage;
        double speed;
        double spawn_chance;
        double armor;

    private:
        double x_position;
        double y_position;
        int level;
        int experience;
        double gold;
        void setLevel(int lvl);
        void setExperience(int exp);
        void setGold(double g);
        void setHealth(double h);
        void setDamage(double d);
        void setSpeed(double s);
        void setSpawnChance(double chance);
        void setAliveStatus(bool status);
        void setArmor(double a);

    public:
        Creature();
        virtual ~Creature();
        void setPosition(double x, double y);
        int getId() const;
        std::string getName() const;
        std::string getType() const;
        bool isAlive() const;
        double getHealth() const;
        double getDamage() const;
        double getSpeed() const;
        double getSpawnChance() const;
        double getXPosition() const;
        double getYPosition() const;
        int getLevel() const;
        int getExperience() const;
        double getGold() const;
        double getArmor() const;
        void takeDamage(double amount);
    };
}
