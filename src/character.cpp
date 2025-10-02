#include "character.hpp"
#include "map.hpp"
#include <SFML/Window/Keyboard.hpp>

// 构造函数
Character::Character(int startX, int startY, int maxHP) 
    : x(startX), y(startY), maxhealth(maxHP), health(maxHP) {}

// 获取玩家x坐标
int Character::getX() const {
    return x;
}

// 获取玩家y坐标
int Character::getY() const {
    return y;
}

// 获取玩家当前生命值
int Character::getHealth() const {
    return health;
}

// 移动玩家到新位置
void Character::move(int newX, int newY) {
    x = newX;
    y = newY;
}

// 玩家受到伤害
void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

// 检查玩家是否死亡
bool Character::isDead() const {
    return health <= 0;
}

void Character::handleInput(Map& map) {
    // 检查按键并移动，每次按键移动一格
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(map.isWall(x, y-1) == 0)
            y -= 1;
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::W)); // 等待按键释放
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if(map.isWall(x, y+1) == 0)
            y += 1;
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::S)); // 等待按键释放
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(map.isWall(x-1, y) == 0)
            x -= 1;
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::A)); // 等待按键释放
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(map.isWall(x+1, y) == 0)
            x += 1;
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::D)); // 等待按键释放
    }
}

