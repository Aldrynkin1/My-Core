#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include "game/include/Human.hpp"
#include "game/include/Monster.hpp"
#include "game/include/Gun.hpp"

using namespace Game;

static void clearScreen() {
    std::cout << std::string(40, '\n');
}

static void initScene(int width, int height, const Human &player, const Monster &monster,
                        bool bulletActive, int bulletX, int bulletY) {
    std::vector<std::string> grid(height, std::string(width, '.'));

    if (monster.isAlive()) {
        int mx = static_cast<int>(monster.getXPosition());
        int my = static_cast<int>(monster.getYPosition());
        if (mx >= 0 && mx < width && my >= 0 && my < height) {
            grid[my][mx] = 'M';
        }
    }

    if (bulletActive) {
        if (bulletX >= 0 && bulletX < width && bulletY >= 0 && bulletY < height) {
            grid[bulletY][bulletX] = '*';
        }
    }

    if (player.isAlive()) {
        int px = static_cast<int>(player.getXPosition());
        int py = static_cast<int>(player.getYPosition());
        if (px >= 0 && px < width && py >= 0 && py < height) {
            grid[py][px] = '@';
        }
    }

    for (const auto &row : grid) {
        std::cout << row << "\n";
    }
}

int main() {
    const int width = 20;
    const int height = 7;

    Human player;
    player.setPosition(1.0, 3.0);

    Monster monster;
    monster.setPosition(16.0, 3.0);

    Gun rifle("Rifle", 30.0, 0.5);

    bool bulletActive = false;
    int bulletX = 0;
    int bulletY = 0;

    std::string command;
    while (true) {
        clearScreen();
        std::cout << "=== Arena ===\n";
        std::cout << "Player: @  Monster: M  Bullet: *\n";
        std::cout << "Health: " << player.getHealth() << "  Monster: " << monster.getHealth() << "\n";
        initScene(width, height, player, monster, bulletActive, bulletX, bulletY);
        std::cout << "Commands: up down left right shoot status quit\n";
        std::cout << "> ";

        if (!(std::cin >> command)) {
            break;
        }

        if (command == "quit") {
            std::cout << "Game ended.\n";
            break;
        }

        if (command == "up") {
            int py = static_cast<int>(player.getYPosition());
            if (py > 0) {
                player.setPosition(player.getXPosition(), py - 1);
            }
        } else if (command == "down") {
            int py = static_cast<int>(player.getYPosition());
            if (py < height - 1) {
                player.setPosition(player.getXPosition(), py + 1);
            }
        } else if (command == "left") {
            int px = static_cast<int>(player.getXPosition());
            if (px > 0) {
                player.setPosition(px - 1, player.getYPosition());
            }
        } else if (command == "right") {
            int px = static_cast<int>(player.getXPosition());
            if (px < width - 1) {
                player.setPosition(px + 1, player.getYPosition());
            }
        } else if (command == "shoot") {
            if (!bulletActive) {
                bulletActive = true;
                bulletX = static_cast<int>(player.getXPosition()) + 1;
                bulletY = static_cast<int>(player.getYPosition());
            }
        } else if (command == "status") {
            std::cout << "Your health=" << player.getHealth() << ", Monster health=" << monster.getHealth() << "\n";
            std::cout << "Press enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        } else {
            std::cout << "Unknown command. Use up/down/left/right/shoot/status/quit.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
        }

        if (bulletActive) {
            while (bulletActive) {
                bulletX += 1;
                if (bulletX >= width) {
                    bulletActive = false;
                    break;
                }

                clearScreen();
                std::cout << "=== Arena ===\n";
                std::cout << "Player: @  Monster: M  Bullet: *\n";
                std::cout << "Health: " << player.getHealth() << "  Monster: " << monster.getHealth() << "\n";
                initScene(width, height, player, monster, bulletActive, bulletX, bulletY);
                std::this_thread::sleep_for(std::chrono::milliseconds(80));

                if (monster.isAlive() && bulletX == static_cast<int>(monster.getXPosition()) &&
                    bulletY == static_cast<int>(monster.getYPosition())) {
                    monster.takeDamage(rifle.getDamage());
                    bulletActive = false;
                    std::cout << "You hit the monster! Monster health=" << monster.getHealth() << "\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                }
            }
        }

        if (monster.isAlive()) {
            int mx = static_cast<int>(monster.getXPosition());
            int my = static_cast<int>(monster.getYPosition());
            int px = static_cast<int>(player.getXPosition());
            int py = static_cast<int>(player.getYPosition());

            if (mx > px + 1) {
                monster.setPosition(mx - 1, my);
            }
            if (my < py) {
                monster.setPosition(monster.getXPosition(), my + 1);
            } else if (my > py) {
                monster.setPosition(monster.getXPosition(), my - 1);
            }

            if (std::abs(mx - px) <= 1 && std::abs(my - py) <= 1) {
                player.takeDamage(monster.getDamage());
                std::cout << "Monster hits you! Your health=" << player.getHealth() << "\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        }

        if (!player.isAlive() || !monster.isAlive()) {
            break;
        }
    }

    if (!player.isAlive()) {
        std::cout << "You are defeated.\n";
    } else if (!monster.isAlive()) {
        std::cout << "You win!\n";
    }

    return 0;
}
