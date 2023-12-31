#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include "select_kth_smallest.h"
#include "merge_sort.h"

using namespace std;

#define Maxnum 150000

int main() {
    int *b = new int[Maxnum];
    int *c = new int[Maxnum];
    int *d = new int[Maxnum];
//    int b[Maxnum];
//    int c[Maxnum];
//    int d[Maxnum];
    int randon_num, randon_number;
    for (int i = 0; i < Maxnum; i++) {
        randon_num = rand() % 1000 + 1;
        randon_number = rand() % 200000 * randon_num;
        b[i] = randon_number;
        c[i] = randon_number;
        d[i] = randon_number;
    }
    //time of quick sort
    clock_t start, finish;
    double duration_quick;
    start = clock();
    QuickSort(b, 0, Maxnum - 1);
    finish = clock();
    duration_quick = ((double) finish - (double) start) / 1000.0;
    cout << duration_quick << endl;

    //time of merge sort
    double duration_mearge;
    int *temp = new int[Maxnum];
    start = clock();
    MergeSort(c, temp, 0, Maxnum - 1);
    finish = clock();
    duration_mearge = ((double) finish - (double) start) / 1000.0;
    cout << duration_mearge << endl;

    //time of worst case quick sort
    QuickSort_Reverse(d, 0, Maxnum - 1);
    double duration_worst_quicksort = 0;
    start = clock();
    QuickSort(d, 0, Maxnum - 1);
    finish = clock();
    duration_worst_quicksort = ((double) finish - (double) start) / 1000.0;
    cout << duration_worst_quicksort << endl;


/*
    int arrp[10] = { 8,6,5,7,2,3,1,9,14,3 };
    SelectSort(a, 0, Maxnum-1, 1000);


    QuickSort(b, 0, Maxnum - 1);
    QuickSort(b,0,Maxnum-1);

    int temp = 0;

    for (int i = 0; i < Maxnum - 3000; i += 2000) {
        temp = b[i];
        b[i] = b[i + 1000];
        b[i + 1000] = temp;
    }

    clock_t start, finish;
    double duration;
    start = clock();
    int result = FindkthSmallest(b, 0, Maxnum - 1, 9000);
    finish = clock();
    duration = ((double) finish - (double) start) / 1000.0;
    cout << "FindkthSmallest:" << setprecision(3) << duration << endl;


    for (int i = 0; i < Maxnum; i++) {
        randon_num = rand() % 1000 + 1;
        randon_number = rand() % 200000 * randon_num;
        b[i] = randon_number;
    }
    QuickSort(b, 0, Maxnum - 1);
    for (int i = 0; i < Maxnum - 3000; i += 2000) {
        temp = b[i];
        b[i] = b[i + 1000];
        b[i + 1000] = temp;
    }

    clock_t start2, finish2;
    double duration2;
    start2 = clock();
    int result1 = SelectKthSmallest(b, 0, Maxnum - 1, 9000);
    finish2 = clock();
    duration2 = ((double) finish2 - (double) start2) / 1000.0;
    cout << "SeleKthSmallest:" << setprecision(8) << duration2 << endl;

    clock_t start3, finish3;
    double duration3;
    start3 = clock();
    QuickSort(a, 0, Maxnum - 1);
    finish3 = clock();
    duration3 = ((double) finish3 - (double) start3) / 1000.0;
    cout << "Find" << setprecision(8) << duration3 << endl;


    clock_t start4, finish4;
    double duration4;
    start4 = clock();
    QuickSort2(b, 0, Maxnum - 1, result1);
    finish4 = clock();
    duration4 = ((double) finish4 - (double) start4) / 1000.0;
    cout << "Sele" << setprecision(8) << duration4 << endl;

	for (int i = 0; i < Maxnum; i++) {
		if (a[i] != b[i])
			cout << i << endl;
	}
	for (int i = 0; i < Maxnum-1; i++) {
		if (b[i] < b[i + 1])
			cout << i << endl;
	}*/
}