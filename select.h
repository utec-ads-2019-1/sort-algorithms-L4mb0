#ifndef SELECT_H
#define SELECT_H

#include "sort.h"
#include "includess.h"

class SelectSort : public Sort {       
    public:
        SelectSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            int *array = (int*) elements;

                for (int i = 0; i < size-1; ++i) {
                        int minI=i;
                        for (int j = i+1; j < size; ++j) {
                                if(array[j] < array[minI]){
                                    minI=j;
                                }
                        }
                        swap(array[minI], array[i]);
                }
        }

        inline string name() { return "SelectSort"; }
};

#endif