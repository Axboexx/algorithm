//
// Created by 12636 on 2023/9/19.
//
#include<iostream>

#ifndef SORT_MERGE_SORT_H
#define SORT_MERGE_SORT_H
using namespace std;
#endif //SORT_MERGE_SORT_H

void Merge(int source[], int temp[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    while (i != mid + 1 && j != end + 1) {
        if (source[i] > source[j])
            temp[k++] = source[j++];
        else
            temp[k++] = source[i++];
    }
    while (i != mid + 1)
        temp[k++] = source[i++];
    while (j != end + 1)
        temp[k++] = source[j++];
    for (i = start; i <= end; i++)
        source[i] = temp[i];
}

void MergeSort(int source[], int temp[], int start, int end) {
    int mid;
    if (start < end) {
        mid = start + (end - start) / 2;//避免溢出int
        MergeSort(source, temp, start, mid);
        MergeSort(source, temp, mid + 1, end);
        Merge(source, temp, start, mid, end);
    }
}