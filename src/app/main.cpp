#include<bits/stdc++.h>
#include "sorting/mergeSort.hpp"
#include "sorting/ParallelMergeSort.hpp"
using namespace std;

int main(int argc, char* argv[]) {

    const int SIZE=10000000; 
    vector<int> nums(SIZE),nums1(SIZE);

    for(int i = 0; i < SIZE; i++) {
        nums[i] = rand() % 10000000;
        nums1[i] = rand() % 10000000; // Random numbers between 0 and 999
    }

    MergeSort* mergesort=new MergeSort(&nums); 
    auto start= chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end= chrono::high_resolution_clock::now();
    chrono::duration<double> mergesortduration = end - start;

    cout<< "Merge Sort Duration: " << mergesortduration.count() << " seconds" << '\n';

    ParallelMergeSort* parallelmergesort=new ParallelMergeSort(&nums1); 
    start= chrono::high_resolution_clock::now();
    parallelmergesort->sort();
    end= chrono::high_resolution_clock::now();
    chrono::duration<double> parallelmergesortduration = end - start;

    cout<< "Parallel Merge Sort Duration: " << parallelmergesortduration.count() << " seconds" << '\n';

    delete parallelmergesort;
}