#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H
#include<bits/stdc++.h>
// #include <vector>
using namespace std;

class ParallelMergeSort {
    private:
        vector<int>* nums;

        public:
         ParallelMergeSort(vector<int>* nums);
         ~ParallelMergeSort();
         void sort();
         void recursiveSort(int left, int right);

};

#endif

           

 
