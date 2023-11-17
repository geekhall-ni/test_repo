#ifndef TEST_PARSER_H
#define TEST_PARSER_H

#pragma once
#include "placement.h"
#include <string>

// Parser 类，用于解析输入文件并将解析结果存入 placement 对象中
class Parser {
public:
    /**
     * @brief 解析输入文件并将解析结果存入 placement 对象中
     * @param filename 输入文件名
     * @param placement 存储解析结果的 Placement 对象的引用
     * @return 解析成功返回 true，否则返回 false
     */
    static bool parseInputFile(const std::string& filename, Placement& placement);
};

#endif // TEST_PARSER_H









