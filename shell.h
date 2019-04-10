#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
                int *array = (int*) elements;
                int llave, j;
                for (int gap = size/2; gap > 0; gap /= 2) {
                        for (int i = gap; i < size; ++i) {
                                for (int k = i-gap; k >=0 ; k=k-gap) {
                                        if(array[k+gap] < array[k]){
                                                swap(array[k], array[k+gap]);
                                        }
                                        else break;
                                }
                        }
                }
        }

        inline string name() { return "ShellSort"; }
};

#endif