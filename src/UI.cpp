#include "UI.hpp"

// 按钮类构造函数实现
Button::Button(float x, float y, float width, float height, 
               sf::Font& font, const std::string& label) : label(label) {
    // 设置按钮形状
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(70, 70, 70)); // 深灰色按钮
    shape.setOutlineColor(sf::Color::White);   // 白色边框
    shape.setOutlineThickness(2);              // 边框厚度

    // 设置按钮文字
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // 文字居中
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                   textBounds.top + textBounds.height / 2.0f);
    text.setPosition(
        x + width / 2.0f,
        y + height / 2.0f
    );
}

// 检查鼠标是否在按钮上
bool Button::isMouseOver(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect btnBounds = shape.getGlobalBounds();
    
    return btnBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

// 绘制按钮
void Button::render(sf::RenderWindow& window) const{
    window.draw(shape);
    window.draw(text);
}

// UI管理器构造函数实现
UIManager::UIManager(const sf::Vector2u& windowSize) {
    // 加载字体
    if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf")) {
        // 如果默认字体加载失败，尝试其他常见路径
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        }
    }

    // 设置标题
    title.setFont(font);
    title.setString("maze");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition(
        (windowSize.x - titleBounds.width) / 2.0f,
        50 // 距离顶部50像素
    );

    // 设置背景
    background.setSize(sf::Vector2f(windowSize.x, windowSize.y));
    background.setFillColor(sf::Color(30, 30, 30)); // 深灰色背景

    // 创建按钮（宽度200，高度60，居中排列）
    float btnWidth = 200;
    float btnHeight = 60;
    float btnX = (windowSize.x - btnWidth) / 2.0f; // 水平居中

    // 地图1按钮（y=200）
    buttons.emplace_back(btnX, 200, btnWidth, btnHeight, font, "map1");
    // 地图2按钮（y=300）
    buttons.emplace_back(btnX, 300, btnWidth, btnHeight, font, "map2");
    // 退出按钮（y=400）
    buttons.emplace_back(btnX, 400, btnWidth, btnHeight, font, "Exit");
}

// 处理菜单输入
GameState UIManager::handleMenuInput(const sf::RenderWindow& window) {
    // 检查鼠标左键是否按下
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // 检查第一个按钮（map1）
        if (buttons[0].isMouseOver(window)) {
            return PLAY_MAP1;
        }
        // 检查第二个按钮（map2）
        if (buttons[1].isMouseOver(window)) {
            return PLAY_MAP2;
        }
        // 检查第三个按钮（exit）
        if (buttons[2].isMouseOver(window)) {
            return EXIT;
        }
    }
    // 未点击有效按钮，保持菜单状态
    return MENU;
}

// 渲染菜单
void UIManager::renderMenu(sf::RenderWindow& window) {
    window.draw(background);  // 绘制背景
    window.draw(title);       // 绘制标题
    // 绘制所有按钮
    for (const auto& btn : buttons) {
        btn.render(window);
    }
}
    