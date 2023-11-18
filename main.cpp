#include "parser.h"
#include "database.h"
#include "placement.h"
#include "exporter.h"
#include <iostream>

int main() {
    Placement placement; // 创建布局对象，用于存储布局信息

    // 解析输入文件
    if (Parser::parseInputFile("/home/ni/input.txt", placement)) {
        // 如果解析输入文件成功，根据索引值计算出每个单元在网格中的初始坐标位置
        int index = 0;
        for (auto& unit : placement.units) {
            unit.x = index % placement.gridSizeX; // 计算单元的 x 坐标
            unit.y = index / placement.gridSizeX; // 计算单元的 y 坐标
            index++; // 自增索引值
        } // 在3*3网格中，4 个单元的初始坐标分别为 (0, 0)、(0, 1)、(1, 0) 和 (1, 1)

        // 寻找并得出最佳的布局
        PlacementAlgorithm::findBestLayout(placement);

        // 导出布局到输出文件
        if (Exporter::exportOutputFile("/home/ni/output.txt", placement)) {
            std::cout << "布局文件已成功导出。" << std::endl; // 导出成功提示
        } else {
            std::cout << "无法导出布局文件。" << std::endl; // 导出失败提示
        }
    } else {
        std::cout << "无法读取输入文件。" << std::endl; // 读取文件失败提示
        return 1; // 如果解析输入文件失败，导出失败提示
    }

    return 0;
}






































