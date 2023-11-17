#include "parser.h"
#include <fstream>
#include <sstream>

bool Parser::parseInputFile(const std::string& filename, Placement& placement) {
    std::ifstream fin(filename); // 打开指定文件
    if (!fin.is_open()) {
        return false; // 无法打开文件
    }
    std::string line;
    // 逐行读取文件内容
    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::string token;
        ss >> token;

        if (token == "DieSize") {
            ss >> placement.gridSizeX >> placement.gridSizeY; // 读取 DieSize 对应的值并存入 gridSizeX 和 gridSizeY 中
        } else if (token == "NumInstances") {
            ss >> placement.numInstances; // 读取 NumInstances 对应的值并存入 numInstances 中
        } else if (token == "Inst") {
            Unit unit;
            ss >> unit.name;
            placement.units.push_back(unit); // 将单元添加到 units 容器中
        } else if (token == "NumNets") {
            ss >> placement.numNets; // 读取 NumNets 对应的值并存入 numNets 中
        } else if (token == "Net") {
            Net net;
            ss >> net.name; // 读取 Net 对应的值并存入 net 的 name 中
            int numPins;
            ss >> numPins; // 读取与 net 线网连接单元的数量

            for (int i = 0; i < numPins; i++) { // 循环读取每个线网连接的单元
                std::string connectedUnit;
                ss >> connectedUnit;
                net.connectedUnits.push_back(connectedUnit); // 将连接的单元添加到 net 的 connectedUnits 中
            }

            placement.nets.push_back(net); // 将 net 添加到 nets 容器中
        }
    }

    fin.close(); // 关闭文件
    return true; // 解析成功
}
































