#include "player.hpp"
#include <SFML/Window/Keyboard.hpp>

Player::Player(int startX, int startY, int cellSize, int maxHealth) 
    : position(startX, startY), cellSize(cellSize), maxHealth(maxHealth), health(maxHealth) {
    // 初始化玩家图形
    shape.setSize(sf::Vector2f(cellSize - 4, cellSize - 4));  // 比格子小一点，留出边框
    shape.setFillColor(sf::Color::Cyan);                      // 玩家颜色为青色
    shape.setPosition(
        position.x * cellSize + 2,  // +2是为了居中显示
        position.y * cellSize + 2
    );
}

void Player::handleInput(const Map& map) {
    // 检查按键并移动，每次按键移动一格
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // 计算新位置
        sf::Vector2i newPos = position + directions[0];
        // 检查新位置是否可以移动（不是墙壁）
        if (map.isValidPosition(newPos.x, newPos.y) && !map.isWall(newPos.x, newPos.y)) {
            position = newPos;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sf::Vector2i newPos = position + directions[1];
        if (map.isValidPosition(newPos.x, newPos.y) && !map.isWall(newPos.x, newPos.y)) {
            position = newPos;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::Vector2i newPos = position + directions[2];
        if (map.isValidPosition(newPos.x, newPos.y) && !map.isWall(newPos.x, newPos.y)) {
            position = newPos;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::Vector2i newPos = position + directions[3];
        if (map.isValidPosition(newPos.x, newPos.y) && !map.isWall(newPos.x, newPos.y)) {
            position = newPos;
        }
    }
}

void Player::update() {
    // 更新玩家图形位置
    shape.setPosition(
        position.x * cellSize + 2,
        position.y * cellSize + 2
    );
}

void Player::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

void Player::heal(int amount) {
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

bool Player::isDead() const {
    return health <= 0;
}

int Player::getHealth() const {
    return health;
}

int Player::getMaxHealth() const {
    return maxHealth;
}

const sf::Vector2i& Player::getPosition() const {
    return position;
}

void Player::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}
    