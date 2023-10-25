//
// Created by 刘承汿 on 2023/10/25.
//
#include <cmath>
#include <iostream>

using namespace std;
#ifndef ALGORITHM_LIGHTING_PROBLEM_H
#define ALGORITHM_LIGHTING_PROBLEM_H

#endif //ALGORITHM_LIGHTING_PROBLEM_H

#define I 50
#define L 20
#define W 15
#define H 5
#define stride 0.2

typedef struct {
    double x;
    double y;
} point;


double calculate_r(point p, double x, double y) {
    return pow(x - p.x, 2) + pow(y - p.y, 2) + pow(H, 2);
}

double calculate_E(point p, double x, double y) {
    return 50 / calculate_r(p, x, y);
}

double calculate_U(point *p, double &emin, double &emax, point &min_e, point &max_e) {
    double temp = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < W; ++j) {
            for (int k = 0; k < 12; ++k) {
                temp += calculate_E(p[k], i, j);
            }
            if (emin > temp) {
                emin = temp;
                min_e.x = i;
                min_e.y = j;
            }
            if (emax < temp) {
                emax = temp;
                max_e.x = i;
                max_e.y = j;
            }
            temp = 0;
        }

    }
    return emin / emax;
}

void adjustment_p(point *p, point min_e, point max_e) {
    double min_dis = 99999;
    double dis = 99999;
    int closest_maxe;
    for (int i = 0; i < 12; ++i) {
        dis = sqrt(calculate_r(p[i], max_e.x, max_e.y));
        if (dis < min_dis) {
            min_dis = dis;
            closest_maxe = i;
        }
    }
    if (abs(p[closest_maxe].x - min_e.x) > abs(p[closest_maxe].y - min_e.y)) {
        if (p[closest_maxe].x < min_e.x)
//            p[closest_maxe].x - ((p[closest_maxe].x - min_e.x) / sqrt(pow(p[closest_maxe].x - min_e.x, 2)));
            p[closest_maxe].x += stride;
        else
            p[closest_maxe].x -= stride;
    } else {
        if (p[closest_maxe].y < min_e.y)
            p[closest_maxe].y += stride;
        else
            p[closest_maxe].y -= stride;
//        p[closest_maxe].y + ((p[closest_maxe].y - min_e.y) / sqrt(pow(p[closest_maxe].y - min_e.y, 2)));
    }
}

void print_point(point *p) {
    for (int i = 0; i < 12; ++i) {
        cout << p[i].x << "  " << p[i].y << endl;
    }
    cout << endl;
}