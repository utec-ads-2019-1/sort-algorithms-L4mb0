#ifndef MERGE_H
#define MERGE_H

#include "sort.h"
#include "includess.h"


class MergeSort : public Sort {       
    public:
        MergeSort(void *elements, size_t size) : Sort(elements, size) {}

    int merge(int a[], int low, int pivot, int high)
    {
        int t1,t2;

        t1 = pivot-low+1;
        t2 = high - pivot;

        int temp1[t1+1], temp2[t2+1];

        for (int i = 0; i < t1; ++i) {
            temp1[i]= a[low+i];
        }
        for (int j = 0; j < t2; ++j) {
            temp2[j] = a[pivot+j+1];
        }

        int i, j, n;
        i=j=n=0;

        while(i!=t1 && j!=t2) {
            if(temp1[i]>temp2[j]) {
                a[low+n]=temp2[j];
                j++;
            } else {
                a[low+n]=temp1[i];
                i++;
            }
            n++;
        }
        while(j!=t2) {
            a[low+n]=temp2[j];
            j++;
            n++;
        }
        while(i!=t1) {
            a[low+n]=temp1[i];
            i++;
            n++;
        }





    }



    void msort(int a[], int low, int high) {
        if(low < high){
            int pivot = (low+high)/2;
            msort(a, low,pivot );
            msort(a, pivot + 1, high);
            merge(a, low, pivot, high);
        }
    }

        void execute(void (*compare)(void*, int, int)) {
            int *array = (int*) elements;
            msort(array,0,size-1);
        }

        inline string name() { return "MergeSort"; }
};

#endif