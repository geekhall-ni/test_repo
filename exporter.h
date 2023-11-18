#ifndef TEST_EXPORTER_H
#define TEST_EXPORTER_H

#pragma once
#include "database.h"
#include <string>

// 输出文件导出类，用于将布局结果导出到文件
class Exporter {
public:
    // 导出布局结果到文件的静态方法
    static bool exportOutputFile(const std::string& filename, const Placement& placement);
};

#endif //TEST_EXPORTER_H







