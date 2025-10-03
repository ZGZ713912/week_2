#include "map.hpp"
#include <iostream>


// 构造函数实现
Map::Map(int w, int h, const std::string& n) : width(w), height(h), name(n) {
    trapcount = 3;   // 初始化陷阱数量

}

std::mt19937 Map::rng(std::random_device{}());

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

int Map::isWall(int x, int y){
    return mapData[y][x]; // 1表示墙壁
}

void Map::clearTraps(){
    // 清除现有的陷阱
    for (int y = 0; y < mapData.size(); y++) {
        // 遍历当前行的每一列
        for (int x = 0; x < mapData[y].size(); x++) {
            // 如果当前格子是陷阱（值为2），则恢复为空地（值为0）
            if (mapData[y][x] == 2) {
                mapData[y][x] = 0;
            }
        }
    }
}

void Map::generateTraps() {
    std::uniform_int_distribution<int> distX(1, width - 1);
    std::uniform_int_distribution<int> distY(1, height - 1);

    Map::clearTraps(); // 清除现有的陷阱
    int generatedCount = 0;// 已生成的陷阱数量
    while (generatedCount < trapcount) {
        int x = distX(rng);
        int y = distY(rng);

        // 仅在空地上生成陷阱（0表示空地）
        if (mapData[y][x] == 0) {
            mapData[y][x] = 2; // 2表示陷阱
            generatedCount++;
        }
            
    }
}

void Map::updateTraps(){

    float Time = Timer.getElapsedTime().asSeconds();  // 获取经过的时间（秒）
    
    // 随机数分布器：生成地图范围内的坐标
    std::uniform_int_distribution<int> distX(1, width - 1);
    std::uniform_int_distribution<int> distY(1, height - 1);
    // 每5秒更新一次陷阱位置
    if (Time >= 5.0f) {
        Map::clearTraps();
    // 重新生成陷阱
        int generatedCount = 0;// 已生成的陷阱数量
        while (generatedCount < trapcount) {
            int x = distX(rng);
            int y = distY(rng);

            // 仅在空地上生成陷阱（0表示空地） tip：防止陷阱生成在人物位置相关代码在main.cpp中
            if (mapData[y][x] == 0) {
                mapData[y][x] = 2; // 2表示陷阱
                generatedCount++;
            }
            
        }
        Timer.restart(); // 重置计时器
    }
    


}
    