#pragma once
#include "Creature.hpp"

namespace Game
{
    class Human : public Creature
    {
    private:
        std::string gun;
        std::string helmet;
        void setGun(const std::string &g);
        void setHelmet(const std::string &h);

    public:
        Human();
        ~Human();
        std::string getGun() const;
    std::string getArmor() const;
    std::string getHelmet() const;
};
}
