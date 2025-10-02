#ifndef MAP_HPP
#define MAP_HPP

#include<vector>
#include<string>

class Map{
private:
    int width;         //地图宽度   
    int height;        //地图高度
    std::string name;      //地图名称   

public:
    // 构造函数
    Map(int w, int h, const std::string& n);

    std::vector<std::vector<int>> mapData; // 地图数据网格   0表示空地，1表示墙壁	

    int getCell(int x, int y) const;    // 获取地图单元格的值

    int getWidth() const;	// 获取地图宽度

    int getHeight() const;	// 获取地图高度

    const std::string& getName() const;	// 获取地图名称
};



#endif // MAP_HPP