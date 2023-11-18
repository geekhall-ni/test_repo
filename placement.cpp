#include "placement.h"
#include <algorithm>
#include <climits>
#include <cmath>

// 计算两个单元之间的欧式距离
int PlacementAlgorithm::calculateDistance(const Unit& unit1, const Unit& unit2) {
  int dx = unit1.x - unit2.x;
  int dy = unit1.y - unit2.y;
  // 计算出两点在x和y方向上的距离的平方和，然后对其求平方根，最后通过std::round函数四舍五入将结果转换为整数
  return static_cast<int>(std::round(std::sqrt(dx * dx + dy * dy)));
}


// 穷举法计算线网的长度
int PlacementAlgorithm::calculateNetLength(const Placement& placement, const Net& net) {
    int length = 0;

    // 遍历单个线网中的需要连接的单元名称
    for (const auto& unitName : net.connectedUnits) {
        // 遍历布局中的每个单元
        for (const auto& unit : placement.units) {
            // 检查当前遍历到的单元的名称是否与线网中的单元名称相匹配。
            if (unit.name == unitName) {
                // 遍历布局中的其他单元
                for (const auto& otherUnit : placement.units) {
                    // 检查当前遍历到的其他单元的名称是否与线网中的单元名称不相同
                    if (otherUnit.name != unitName) {
                        // 计算当前单元与其他单元之间的距离，并将结果累加到length中。
                        length += calculateDistance(unit, otherUnit);
                    }
                }
                break;
            }
        }
    }
    return length; // 返回线网的总长度
}



// 寻找最佳布局的算法（全排列和穷举搜索）
void PlacementAlgorithm::findBestLayout(Placement& placement) {
  int minTotalLength = INT_MAX; // 最小总长度的初始值设为最大整数
  std::vector<Unit> bestLayout;  // 最佳布局的单元列表


  // 通过do-while循环调用 std::next_permutation 函数，逐个生成所有的排列组合。
  // 每次生成一个新的排列，都会计算该排列下的总长度，并与当前的最小总长度进行比较和更新。
  do {
    int totalLength = 0;
    // 计算每条线网的长度，以及所有线网的总长度
    // 遍历placement.nets中的每个元素，并且将当前元素赋值给变量net
    for (const auto& net : placement.nets) {
      int netLength = calculateNetLength(placement, net); // 计算每条线网的长度
      totalLength += netLength; // 计算所有线网的总长度
    }

    // 更新最小总长度和最佳布局
    if (totalLength < minTotalLength) {
      minTotalLength = totalLength;
      bestLayout = placement.units; // 更新最佳布局
    }
    // 返回false时，即已经生成了所有的排列组合，循环结束
  } while (std::next_permutation(placement.units.begin(), placement.units.end()));

  placement.units = bestLayout;  // 将最佳布局应用到实际布局中
}









































































