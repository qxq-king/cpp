#include <BITS/stdc++.h>
#include "base.h"
#include "array.h"

void sort::selection(int a[], int len){
    int i, j;
    for (i = 0; i < len - 1; i++) {
        int min = i;                  
        for (j = i + 1; j < len; j++) {
            if (a[j] < a[min]) { min = j; }
        }
        if (min != i) { swap(&a[min], &a[i]); }  // 交换两个变量
    }
}

void sort::insertion(int arr[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}

void sort::shell(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap = gap >> 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}

void sort::bubble(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) { swap(&arr[j], &arr[j + 1]); }
        }
    }
}