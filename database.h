#ifndef TEST_DATABASE_H
#define TEST_DATABASE_H

#pragma once
#include <vector>
#include <string>

// 单元结构体，表示布局中的单元
struct Unit {
    std::string name; // 单元名称
    int x, y; // 单元在布局中的位置坐标
    // 重载小于运算符，用于排序
    bool operator<(const Unit& other) const {
        return name < other.name; // 通过名称进行比较，用于排序
    }
};

// 线网结构体，表示布局中线网的连接关系
struct Net {
    std::string name; // 线网名称
    std::vector<std::string> connectedUnits; // 线网连接的单元名称列表
};

// 布局结构体，存储了布局的相关信息
struct Placement {
    int gridSizeX, gridSizeY;  // 布局的 X、Y 尺寸
    int numInstances, numNets; // 单元数量和线网数量
    std::vector<Unit> units;   // 单元列表
    std::vector<Net> nets;     // 线网列表
};

#endif // TEST_DATABASE_H





























