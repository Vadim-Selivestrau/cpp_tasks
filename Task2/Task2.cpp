#include <iostream>
#include <algorithm>

void swap(int& n1, int& n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void totalSort(int ar1[], int ar2[], int n, int m) {
    int gap = ceil((float)(n + m) / 2);
    while (gap > 0) {
        int i = 0;
        int j = gap;
        while (j < (n + m)) {
            if (j < n && ar1[i] > ar1[j]) {
                swap(ar1[i], ar1[j]);
            }
            else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
                swap(ar1[i], ar2[j - n]);
            }
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
                swap(ar2[i - n], ar2[j - n]);
            }
            j++;
            i++;
        }
        if (gap == 1) {
            gap = 0;
        }
        else {
            gap = ceil((float)gap / 2);
        }
    }
}

void totalSortWithoutNestedLoops(int ar1[], int ar2[], int n, int m) {
    int i = 0, j = 0, k = n - 1;
    
    while (i <= k && j < m) {
        if (ar1[i] < ar2[j])
            i++;
        else {
            swap(ar2[j++], ar1[k--]);
        }
    }

    std::sort(ar1, ar1 + n);
    std::sort(ar2, ar2 + m);
}

int main()
{
    int arr1[] = { 1, 1, 2, 3, 7, 9 };
    int arr2[] = { 1, 4, 6, 8, 12, 76, 115 };
    
    int sizeArr1 = sizeof(arr1) / sizeof(int);
    int sizeArr2 = sizeof(arr2) / sizeof(int);
    
    int arrMerged[sizeof(arr1) / sizeof(int) + sizeof(arr2) / sizeof(int)];
    
    //totalSort(arr1, arr2, sizeArr1, sizeArr2);
    totalSortWithoutNestedLoops(arr1, arr2, sizeArr1, sizeArr2);
    
    
    for (int i = 0; i < sizeArr1; i++) {
        arrMerged[i] = arr1[i];
    }

    for (int i = 0; i < sizeArr2; i++) {
        arrMerged[i + sizeArr1] = arr2[i];
    }

    for (int i = 0; i < sizeof(arrMerged)/sizeof(int); i++) {
        std::cout << arrMerged[i] << std::endl;
    }

}
