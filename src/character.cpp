#include "character.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


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

sf::Text Character::healthText(){
    font.loadFromFile("./font/ukai.ttc"); //加载字体文件
    if(!font.loadFromFile("./font/ukai.ttc")) {
        std::cerr << "字体加载失败！请将上述路径替换为系统中存在的字体文件路径" << std::endl;
        // 处理错误，请将上述路径替换为系统中存在的字体文件路径
    }
    sf::Text text;                  // 创建文本对象
    text.setFont(font);       // 绑定加载好的字体
    text.setString("HP" + std::to_string(health));      // 文本内容（血量）
    text.setCharacterSize(25);  // 字体大小（像素）
    text.setFillColor(sf::Color::Red);  // 文本颜色
    text.setPosition(x*CELL_SIZE, y*CELL_SIZE);  // 文本在窗口中的位置（居中）
    if(health <= 0){
        text.setString("GMAE\nOVER");      // 文本内容
        text.setCharacterSize(150);  // 字体大小（像素）
        text.setFillColor(sf::Color::Green);  // 文本颜色
        text.setPosition(7*CELL_SIZE/2, 7*CELL_SIZE/2);  // 文本在窗口中的位置（居中示例）
        
    }
    if(x==13 && y==13 && health>0){
        text.setString("YOU\nWIN");      // 文本内容
        text.setCharacterSize(150);  // 字体大小（像素）
        text.setFillColor(sf::Color::Green);  // 文本颜色
        text.setPosition(7*CELL_SIZE/2, 7*CELL_SIZE/2);  // 文本在窗口中的位置（居中）
        
    }
    return text;
    
}

// 检查玩家是否死亡
bool Character::isDead() const {
    return health <= 0;
}

bool Character::isWin() const {
        return (x == 13 && y == 13 && health > 0);
    }
void Character::resetHealth() { health = maxhealth; } // 重置生命值

void Character::handleInput(Map& map) {
// 检查按键并移动，每次按键移动一格
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(map.isWall(x, y-1) == 0 || map.isWall(x, y-1) == 2)
            y -= 1;
            if(map.mapData[y][x] == 2){ // 角色踩到陷阱
                takeDamage(1); // 角色受到1点伤害
                map.mapData[y][x] = 0; // 陷阱被触发后消失
            }
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::W)); // 等待按键释放
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if(map.isWall(x, y+1) == 0 || map.isWall(x, y+1) == 2)
            y += 1;
            if(map.mapData[y][x] == 2){ // 角色踩到陷阱
                takeDamage(1); // 角色受到1点伤害
                map.mapData[y][x] = 0; // 陷阱被触发后消失
            }
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::S)); // 等待按键释放
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(map.isWall(x-1, y) == 0 || map.isWall(x-1, y) == 2)
            x -= 1;
            if(map.mapData[y][x] == 2){ // 角色踩到陷阱
                takeDamage(1); // 角色受到1点伤害
                map.mapData[y][x] = 0; // 陷阱被触发后消失
            }
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::A)); // 等待按键释放
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(map.isWall(x+1, y) == 0 || map.isWall(x+1, y) == 2)
            x += 1;
            if(map.mapData[y][x] == 2){ // 角色踩到陷阱
                takeDamage(1); // 角色受到1点伤害
                map.mapData[y][x] = 0; // 陷阱被触发后消失
            }
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::D)); // 等待按键释放
    }

}

