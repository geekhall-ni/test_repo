#include "exporter.h"
#include <fstream>

bool Exporter::exportOutputFile(const std::string& filename, const Placement& placement) {
    std::ofstream fout(filename); // 打开指定文件
    if (!fout.is_open()) {
        return false; // 无法打开文件
    }

    for (const auto& unit : placement.units) {
        // 将单元的名称、位置信息写入文件
        fout << unit.name << " " << unit.x << " " << unit.y <<
             " # 单元" << unit.name << "的位置为(" << unit.x << ", " << unit.y << ")" << std::endl;
    }

    fout.close(); // 关闭文件
    return true; // 导出成功
}





































