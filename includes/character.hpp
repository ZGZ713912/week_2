#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character {
private:
    int x;          // 角色的x坐标
    int y;          // 角色的y坐标
    int health;     // 角色的生命值
    int maxhealth;  // 角色的最大生命值
public:
    // 构造函数
    Character(int startX, int startY, int maxHP);
    
    // 获取玩家x坐标
    int getX() const;
    
    // 获取玩家y坐标
    int getY() const;
    
    // 获取玩家当前生命值
    int getHealth() const;
    
    // 移动玩家到新位置
    void move(int newX, int newY);
    
    // 玩家受到伤害
    void takeDamage(int amount);
    
    // 检查玩家是否死亡
    bool isDead() const;

};
#endif