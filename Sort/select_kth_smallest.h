//
// Created by 12636 on 2023/9/16.
//
#include "quick_sort.h"

#ifndef SORT_SELECT_KTH_SMALLEST_H
#define SORT_SELECT_KTH_SMALLEST_H

#endif //SORT_SELECT_KTH_SMALLEST_H

void SelectSort(int a[], int s, int t, int k) {
    int index = 0;
    int small;

    for (int j = s; j < s + k; j++) {
        small = a[j];
        for (int i = j; i <= t; i++) {
            if (a[i] < small) {
                small = a[i];
                index = i;
                Swap(&(a[index]), &a[j]);
            }
        }

    }
}

int SelectKthSmallest(int a[], int s, int t, int Kth) {
    if (s >= t)
        return a[s];
    int m = Partition(a, s, t);
    int number = m - s + 1;
    if (Kth == number)
        return a[m];
    if (Kth < number)
        return SelectKthSmallest(a, s, m - 1, Kth);
    else
        return SelectKthSmallest(a, m + 1, t, Kth - number);
}

int FindkthSmallest(int a[], int s, int t, int kth) {
    if (t - s < 75) {
        SelectSort(a, s, t, kth);
        return a[s + kth - 1];
    }
    int ngroup = 0;
    ngroup = (t - s + 1) / 5;
    int start = 0;
    int end = 0;
    for (int i = 0; i < ngroup; i++) {
        start = s + 5 * i;
        end = start + 4;
        SelectSort(a, start, end, 3);
        Swap(&(a[s + i]), &(a[start + 2]));
    }
    int median = 0;
    median = FindkthSmallest(a, s, s + ngroup - 1, (ngroup + 1) / 2);
    int index = 0;
    index = Partition2(a, s, t, median);
    int num;
    num = index - s + 1;
    if (kth == num)
        return median;
    if (kth < num)
        return FindkthSmallest(a, s, index - 1, kth);
    else
        return FindkthSmallest(a, index + 1, t, kth - num);
}
