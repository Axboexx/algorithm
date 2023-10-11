//
// Created by 刘承汿 on 2023/10/11.
//
//例2.5 MinDistance(P,X,Y)
//输入：n个点的集合P,X和Y分别给出P中点的横、纵坐标
//输出：最近的两个点及距离
#include "MinDistance.h"

int main() {
    int n = 1;
    int i;
    cout << "请输入集合点个数：";
    cin >> n;
    cout << "输入原始数据：\n";
    for (i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    qsort(point, n, sizeof(point[0]), cmp_px);
    cout << "排序后：\n";
    for (i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    cout << "最短距离为:" << MinDistance(0, n - 1);
    return 0;
}