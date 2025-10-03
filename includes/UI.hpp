#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <functional>


// 游戏状态枚举
enum GameState {
    MENU,       // 菜单状态
    PLAY_MAP1,  // 玩地图1
    PLAY_MAP2,  // 玩地图2
    EXIT        // 退出
};

// 按钮类
class Button {
private:
    sf::RectangleShape shape;  // 按钮形状
    sf::Text text;             // 按钮文字
    std::string label;         // 按钮标签
public:
    // 构造函数：位置、大小、字体、文字
    Button(float x, float y, float width, float height, 
           sf::Font& font, const std::string& label);

    // 检查鼠标是否在按钮上
    bool isMouseOver(const sf::RenderWindow& window);

    // 绘制按钮
    void render(sf::RenderWindow& window) const;
};

// UI管理器类
class UIManager {
private:
    sf::Font font;             // 字体
    std::vector<Button> buttons; // 按钮集合
    sf::Text title;            // 标题文字
    sf::RectangleShape background; // 背景

public:
    // 构造函数：传入窗口大小
    UIManager(const sf::Vector2u& windowSize);

    // 处理菜单输入，返回新的游戏状态
    GameState handleMenuInput(const sf::RenderWindow& window);

    // 渲染菜单
    void renderMenu(sf::RenderWindow& window);
};


#endif // MAP_HPP