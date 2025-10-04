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

class Window{
public:
    void drawWindow();
};