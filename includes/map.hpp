#ifndef MAP_HPP
#define MAP_HPP

#include<vector>
#include<string>
#include<random>  // 用于随机生成数
#include <SFML/Graphics.hpp>

// 单元格大小（像素）
const int CELL_SIZE = 40;

class Map{
private:
    int width;         //地图宽度   
    int height;        //地图高度
    std::string name;      //地图名称   
    int trapcount;   //陷阱数量 
    sf::Font m_font;  // 创建字体对象
public:
    // 构造函数
    Map(int w, int h, const std::string& n);

    sf::Clock Timer; // 陷阱计时器
    static std::mt19937 rng; // 随机数生成器

    std::vector<std::vector<int>> mapData; // 地图数据网格   0表示空地，1表示墙壁	

    int getCell(int x, int y) const;    // 获取地图单元格的值

    int getWidth() const;	// 获取地图宽度

    int getHeight() const;	// 获取地图高度

    const std::string& getName() const;	// 获取地图名称

    int isWall(int x, int y);	// 检查指定位置是否为墙壁

    void generateTraps();    // 生成陷阱

    void updateTraps(); // 更新陷阱

    void clearTraps(); // 清除陷阱

    sf::Text startText();       //起点文字
    sf::Text endText();       //终点文字
};



#endif // MAP_HPP