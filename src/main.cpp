#include "character.hpp"
#include "map.hpp"
#include "UI.hpp"
#include "mapgeneration.hpp"

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <thread>   // 包含线程相关头文件
#include <chrono>   // 包含时间相关头文件
#include<SFML/Graphics.hpp>

sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
// 生成两个地图
Map map1 = MapGenerator::generateMap1();
Map map2 = MapGenerator::generateMap2();

Character character(1, 1, 3); // 初始位置(1,1)，最大生命值3

int main()
{
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE*15, CELL_SIZE*15), "maze"); // 创建一个窗口
    window.setFramerateLimit(60);   // 设置帧率限制为60帧每秒

    // 创建UI管理器
    UIManager uiManager(window.getSize());

    // 初始状态为菜单
    GameState gameState = MENU;

    map1.generateTraps(); // map1生成初始陷阱
    map2.generateTraps(); // map2生成初始陷阱

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

        // 根据当前状态处理逻辑
        switch (gameState) {
            case MENU:
                // 处理菜单输入，更新游戏状态
                gameState = uiManager.handleMenuInput(window);
                character.move(1, 1); // 重置角色位置
                character.resetHealth(); // 重置生命值
                break;

            case PLAY_MAP1:
                // 按ESC返回菜单
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    gameState = MENU;

                }
                // 处理游戏输入
                character.handleInput(map1);
                break;
            case PLAY_MAP2:
                // 按ESC返回菜单
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    gameState = MENU;
                }
                // 处理游戏输入
                character.handleInput(map2);
                break;
            case EXIT:
                window.close();
                break;
        }

        // 渲染
        window.clear();
        
        if (gameState == MENU) {
            // 渲染菜单
            uiManager.renderMenu(window);
        } 
        if (gameState == PLAY_MAP1) {
            // 绘制迷宫
            map1.updateTraps(); // 更新陷阱
            if(map1.mapData[character.getY()][character.getX()] == 2){ // 陷阱生成在角色位置
                map1.generateTraps(); // 重新生成陷阱
            }
            for (int y = 0; y < map1.getHeight(); y++) {
                for (int x = 0; x < map1.getWidth(); x++) {
                    // 设置格子位置
                    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                    
                    // 根据地图数据设置格子颜色
                    if (map1.mapData[y][x] == 1) {
                        // 墙壁：深灰色
                        cell.setFillColor(sf::Color(50, 50, 50));
                    }
                    if( map1.mapData[y][x] == 0) {
                        // 空地：浅灰色
                        cell.setFillColor(sf::Color(240, 240, 240));
                    }
                    if(map1.mapData[y][x] == 2) {
                        // 陷阱：红色
                        cell.setFillColor(sf::Color::Red);
                    }
                    if(x == character.getX() && y == character.getY()){
                        cell.setFillColor(sf::Color::Cyan);
                    }
                    
                    // 绘制格子
                    window.draw(cell);
                }
            }
            window.draw(character.healthText());
        }
        if (gameState == PLAY_MAP2) {

            map2.updateTraps(); // 更新陷阱
            if(map1.mapData[character.getY()][character.getX()] == 2){ // 陷阱生成在角色位置
                map1.generateTraps(); // 重新生成陷阱
            }
            for (int y = 0; y < map2.getHeight(); y++) {
                for (int x = 0; x < map2.getWidth(); x++) {
                    // 设置格子位置
                    cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                    
                    // 根据地图数据设置格子颜色
                    if (map2.mapData[y][x] == 1) {
                        // 墙壁：深灰色
                        cell.setFillColor(sf::Color(50, 50, 50));
                    }  
                    if (map2.mapData[y][x] == 0) {
                        // 空地：浅灰色
                        cell.setFillColor(sf::Color(240, 240, 240));
                    }
                    if(map2.mapData[y][x] == 2) {
                        // 陷阱：红色
                        cell.setFillColor(sf::Color::Red);
                    }

                    if(x == character.getX() && y == character.getY()){
                        cell.setFillColor(sf::Color::Cyan);
                    }
                    
                    
                    // 绘制格子
                    window.draw(cell);
                    
                }
            }
            window.draw(character.healthText());
        }
        



        // 显示绘制的内容
        window.display();
        if(character.isDead()){
            sf::sleep(sf::seconds(2.0f));  // 单位：秒，2.0f 即 2 秒
            gameState = MENU;
        }
    }




    return 0;
}
