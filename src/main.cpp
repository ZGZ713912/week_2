#include "character.hpp"
#include "map.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <thread>   // 包含线程相关头文件
#include <chrono>   // 包含时间相关头文件
#include<SFML/Graphics.hpp>


// 单元格大小（像素）
const int CELL_SIZE = 40;
// 生成两个地图
Map map1(15, 15, "迷宫地图1");

int main()
{






    sf::RenderWindow window(sf::VideoMode(CELL_SIZE*15, CELL_SIZE*15), "窗口示例"); // 创建一个窗口
    window.setFramerateLimit(60);   // 设置帧率限制为60帧每秒

    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));

    while (window.isOpen()) {
        // 处理事件
        sf::Event event;
        while (window.pollEvent(event)) {
            // 关闭窗口事件
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // 清空窗口（白色背景）
        window.clear(sf::Color::White);

        
            
            // 绘制迷宫
            for (int y = 0; y < map1.getHeight(); y++) {
                for (int x = 0; x < map1.getWidth(); x++) {
                    // 设置格子位置
                    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                    
                    // 根据地图数据设置格子颜色
                    if (map1.mapData[y][x] == 1) {
                        // 墙壁：深灰色
                        cell.setFillColor(sf::Color(50, 50, 50));
                    } else {
                        // 空地：浅灰色
                        cell.setFillColor(sf::Color(240, 240, 240));
                    }
                    
                    // 绘制格子
                    window.draw(cell);
                }
            }

        // 显示绘制的内容
        window.display();
    }



    std::this_thread::sleep_for(std::chrono::seconds(5));


    return 0;
}
