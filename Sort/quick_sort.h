//
// Created by 12636 on 2023/9/15.
//

#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H

#endif //SORT_QUICK_SORT_H

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high) {
    int i = low;
    int j = high + 1;
    int mid = a[low];
    while (1) {
        while (a[++i] < mid && i < high);
        while (a[--j] > mid);
        if (i >= j)
            break;
        Swap(&a[i], &a[j]);
    }
    a[low] = a[j];
    a[j] = mid;
    return j;
}

int Partition_Reverse(int a[], int low, int high) {
    int i = low;
    int j = high + 1;
    int mid = a[low];
    while (1) {
        while (a[++i] > mid && i < high);
        while (a[--j] < mid);
        if (i >= j)
            break;
        Swap(&a[i], &a[j]);
    }
    a[low] = a[j];
    a[j] = mid;
    return j;
}


void QuickSort_Reverse(int a[], int p, int r) {
    if (p < r) {
        int q = Partition_Reverse(a, p, r);
        QuickSort_Reverse(a, p, q - 1);
        QuickSort_Reverse(a, q + 1, r);
    }
}

void QuickSort(int a[], int p, int r) {
    if (p < r) {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

int Partition2(int a[], int s, int t, int evalue) {
    int x = 0;
    for (int i = s; i <= t; i++) {
        if (a[i] == evalue) {
            x = a[i];
            break;
        }
    }
    int i = s;
    int j = t + 1;
    while (1) {
        while (a[++i] < x && i < t);
        while (a[--j] > x);
        if (i >= j)break;
        Swap(&a[i], &a[j]);
    }
    a[s] = a[j];
    a[j] = x;
    return j;
}

void QuickSort2(int a[], int p, int r, int value) {
    if (p < r) {
        int q = Partition2(a, p, r, value);
        QuickSort2(a, p, q - 1, a[q]);
        QuickSort2(a, q + 1, r, a[q]);

    }
}