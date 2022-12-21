#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

void totalSort(int ar1[], int ar2[], int n, int m) {
    int gap = ceil((float)(n + m) / 2);
    while (gap > 0) {
        int i = 0;
        int j = gap;
        while (j < (n + m)) {
            if (j < n && ar1[i] > ar1[j]) {
                std::swap(ar1[i], ar1[j]);
            }
            else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
                std::swap(ar1[i], ar2[j - n]);
            }
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
                std::swap(ar2[i - n], ar2[j - n]);
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
    unsigned int start = clock();

    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m) {
        if (ar1[i] < ar2[j])
            i++;
        else {
            std::swap(ar2[j++], ar1[k--]);
        }
    }

    std::sort(ar1, ar1 + n);
    std::sort(ar2, ar2 + m);

    unsigned int end = clock();
    std::cout <<"with sorts " << end - start << "ms" << std::endl;
    //~32-37ms
}

void totalSortWithoutSorts(int ar1[], int ar2[], int n, int m) {
    unsigned int start = clock();

    int i = 0, j = 0, k = 0;
    int* merged = new int[m + n];

    while (i <= n && j < m) {
        if (ar1[i] < ar2[j])
            merged[k++] = ar1[i++];
        else {
            merged[k++] = ar2[j++];
        }
    }
    while (i < n)
        merged[k++] = ar1[i++];

    while (j < m)
        merged[k++] = ar2[j++];

    
    

    unsigned int end = clock();
    std::cout <<"without sort " << end - start << "ms" << std::endl;
    //~0-1ms
}





int main()
{
    int arr1[50000];
    int arr2[50000];
    
    int sizeArr1 = sizeof(arr1) / sizeof(int);
    int sizeArr2 = sizeof(arr2) / sizeof(int);
    
    for (int i = 0; i < sizeArr1; i++) {
        arr1[i] = 1 + rand() % 4000;
        
    }
    for (int i = 0; i < sizeArr2; i++) {
        arr2[i] = 1 + rand() % 4000;
        
    }
    std::sort(arr1, arr1 + sizeArr1);
    std::sort(arr2, arr2 + sizeArr2);

    int arrMerged[sizeof(arr1) / sizeof(int) + sizeof(arr2) / sizeof(int)];
    
    totalSortWithoutSorts(arr1, arr2, sizeArr1, sizeArr2);    
    
    totalSortWithoutNestedLoops(arr1, arr2, sizeArr1, sizeArr2);
    
    

   /* for (int i = 0; i < sizeArr1; i++) {
        arrMerged[i] = arr1[i];
    }

    for (int i = 0; i < sizeArr2; i++) {
        arrMerged[i + sizeArr1] = arr2[i];
    }

    for (int i = 0; i < sizeof(arrMerged)/sizeof(int); i++) {
        std::cout << arrMerged[i] << std::endl;
    }*/

}
