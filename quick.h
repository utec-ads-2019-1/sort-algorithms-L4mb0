#ifndef QUICK_H
#define QUICK_H

#include "sort.h"
#include "includess.h"



class QuickSort : public Sort {       
    public:
        QuickSort(void *elements, size_t size) : Sort(elements, size) {}

    int partition(int a[], int low, int high)
    {
        int pivot = a[high];
        int pIndex = low;
        for (int i = low; i < high; i++)
        {
            if (a[i] <= pivot)
            {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }
        swap(a[pIndex], a[high]);
        return pIndex;
    }

    int randPartition(int a[], int low, int high)
    {
        int pivotIndex = rand() % (high - low + 1) + low;
        swap(a[pivotIndex], a[high]);
        return partition(a, low, high);
    }

    void qsort(int a[], int low, int high) {
        if(low < high){
            int pivot = randPartition(a, low , high);
            qsort(a, low,pivot - 1);
            qsort(a, pivot + 1, high);
        }
    }

        void execute(void (*compare)(void*, int, int)) {

                int *array = (int*) elements;
                qsort(array,0,size-1);
        }

        inline string name() { return "QuickSort"; }
};

#endif