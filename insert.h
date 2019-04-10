#ifndef INSERT_H
#define INSERT_H

#include "includess.h"
#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            int *array = (int *) elements;
            int llave, j;
            for (int i = 1; i < size; ++i) {
                llave = array[i];
                j=i-1;

                while(j>=0 && array[j] > llave){
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1] = llave;
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif