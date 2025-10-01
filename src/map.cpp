#include "map.hpp"
#include <iostream>

// 构造函数实现
Map::Map(int w, int h, const std::string& n) : width(w), height(h), name(n) {
    grid.resize(height, std::vector<int>(width, 0));
}

// 设置地图单元格的值
void Map::setCell(int x, int y, int value) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = value;  // 注意y是行索引，x是列索引
    }
}

// 获取地图单元格的值
int Map::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];
    }
    return 1;  // 超出边界视为墙壁
}

// 打印地图
void Map::print() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            // 可以用不同字符表示墙壁和空地，更直观
            std::cout << (cell == 1 ? "#" : " ");
        }
        std::cout << std::endl;
    }
}

// 获取地图宽度
int Map::getWidth() const { 
    return width; 
}

// 获取地图高度
int Map::getHeight() const { 
    return height; 
}

// 获取地图名称
const std::string& Map::getName() const { 
    return name; 
}
    