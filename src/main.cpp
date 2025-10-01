#include "map_generation.hpp"
#include <iostream>

int main() {
    // 生成两个地图
    Map map1 = MapGenerator::generateMap1();
    Map map2 = MapGenerator::generateMap2();
    
    // 显示第一个地图
    std::cout << "===== " << map1.getName() << " =====" << std::endl;
    map1.print();
    
    // 显示第二个地图
    std::cout << "\n===== " << map2.getName() << " =====" << std::endl;
    map2.print();
    
    return 0;
}
    