//
// Created by 刘承汿 on 2023/10/11.
//
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <iostream>

#ifndef ALGORITHM_MINDISTANCE_H
#define ALGORITHM_MINDISTANCE_H

#endif //ALGORITHM_MINDISTANCE_H
using namespace std;

#define INF 2147483647
#define N 10000
struct node {
    double x;
    double y;
} point[N];

//调用结构体的快排
int cmp_px(const void *a, const void *b) {
    struct node aa = *(struct node *) a;
    struct node bb = *(struct node *) b;
    if (aa.x != bb.x)
        return aa.x - bb.x;//按照x从小到大的顺序排序
    else
        return aa.y - bb.y;//当x相等的时候，按照y的从大到小的顺序排序
}

//计算两点的距离的函数
double distance(int start, int end) {
    return sqrt((point[start].x - point[end].x) * (point[start].x - point[end].x) +
                ((point[start].y - point[end].y) * (point[start].y - point[end].y)));
}

double MinDistance(int start, int end) {
    //若范围内只有一个点，则返回无穷大
    if (start == end) {
        return INF;
    }
        //若范围中有两个点，这两个点的距离即为最小距离
    else if (start == end - 1) {
        return distance(start, end);
    }
        //若范围内有三个点，则遍历求出两两点之间的距离比较大小
    else if (start == end - 2) {
        double a, b, c;
        int mid = (start + end) / 2;
        a = distance(start, mid);
        b = distance(start, end);
        c = distance(mid, end);
        int min = a;
        if (b < min)
            min = b;
        else if (c < min)
            min = c;
        return min;
    }
        //大于三个点的时候
    else {
        double mdistance;
        int i = 0, j = 0, k = 0;

        int mid = (start + end) / 2;
        double left = MinDistance(start, mid);//左边递归
        double right = MinDistance(mid + 1, end);//右边递归

        mdistance = left < right ? left : right;//比较左右两边的最短距离，找出最小值

        int temp[N] = {0};

        for (i = start; i <= end; i++) {
            if (fabs(point[mid].x - point[i].x) <= mdistance) {
                temp[k++] = i;
            }
        }
        for (i = 0; i <= k - 1; i++)//纵坐标寻找最短距离
        {
            for (j = i + 1; j <= k - 1 && j < i + 7; j++) {
                if (fabs(point[temp[j]].y - point[temp[i]].y) < mdistance) {
                    mdistance = mdistance < distance(temp[i], temp[j]) ? mdistance : distance(temp[i], temp[j]);
                }
            }
        }
        return mdistance;
    }
}