#include <iostream>

void swap(int& n1, int& n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void totalSort(int ar1[], int ar2[], int n) {
    int gap = n;
    while (gap > 0) {
        int i = 0;
        int j = gap;
        while (j < (2*n)) {
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



int main()
{
    int arr1[] = { 1, 1, 3, 7, 9 };
    int arr2[] = { 1, 4, 12, 12, 76 };
    int arrMerged[2 * sizeof(arr1)/sizeof(int)];
    
    totalSort(arr1, arr2, sizeof(arr1)/sizeof(int));
    
    
    for (int i = 0; i < sizeof(arr1)/ sizeof(int); i++) {
        arrMerged[i] = arr1[i];
    }

    for (int i = 0; i < sizeof(arr1)/sizeof(int); i++) {
        arrMerged[i+5] = arr2[i];
    }

    for (int i = 0; i < sizeof(arrMerged)/sizeof(int); i++) {
        std::cout << arrMerged[i] << std::endl;
    }

}
