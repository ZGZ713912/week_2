#ifndef MAP_GENERATION_HPP
#define MAP_GENERATION_HPP

#include "map.hpp"

// 地图生成器类，负责创建具体地图
class MapGenerator {
public:
    // 生成第一个地图
    static Map generateMap1();

    // 生成第二个地图
    static Map generateMap2();
};

#endif
    