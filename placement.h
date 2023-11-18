#ifndef TEST_PLACEMENT_H
#define TEST_PLACEMENT_H

#pragma once
#include "database.h"

// 布局算法类，用于寻找最佳的布局方案
class PlacementAlgorithm {
public:
    // 寻找最佳布局的静态方法
    static void findBestLayout(Placement& placement);

private:
    // 计算两个单元之间的距离
    static int calculateDistance(const Unit& unit1, const Unit& unit2);
    // 计算线网的长度
    static int calculateNetLength(const Placement& placement, const Net& net);
};

#endif // TEST_PLACEMENT_H












