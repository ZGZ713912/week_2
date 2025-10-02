#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "map.hpp"

class Player {
private:
    sf::RectangleShape shape;  // 玩家图形
    sf::Vector2i position;     // 玩家在网格中的位置
    int cellSize;              // 每个格子的大小
    int health;                // 生命值
    int maxHealth;             // 最大生命值
    
    // 移动方向向量
    const sf::Vector2i directions[4] = {
        {0, -1},  // 上 (W)
        {0, 1},   // 下 (S)
        {-1, 0},  // 左 (A)
        {1, 0}    // 右 (D)
    };

public:
    // 构造函数
    Player(int startX, int startY, int cellSize, int maxHealth = 3);
    
    // 析构函数
    ~Player() = default;
    
    // 处理输入并移动玩家
    void handleInput(const Map& map);
    
    // 更新玩家状态
    void update();
    
    // 绘制玩家
    void render(sf::RenderWindow& window) const;
    
    // 减少生命值
    void takeDamage(int amount);
    
    // 增加生命值
    void heal(int amount);
    
    // 检查是否死亡
    bool isDead() const;
    
    // 获取当前生命值
    int getHealth() const;
    
    // 获取最大生命值
    int getMaxHealth() const;
    
    // 获取玩家位置
    const sf::Vector2i& getPosition() const;
    
    // 设置玩家位置
    void setPosition(int x, int y);
};

#endif // PLAYER_HPP
    