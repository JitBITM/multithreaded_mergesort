#include "ParallelMergeSort.hpp"
#include<thread> 
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

ParallelMergeSort::ParallelMergeSort(vector<int>* nums) {
    this->nums = nums;
}

ParallelMergeSort::~ParallelMergeSort() {
    // Destructor logic if needed
}

void ParallelMergeSort::recursiveSort(int left, int right) {

    const int Threshold = 5000;
    if((right - left) < Threshold) {
        std::sort((*nums).begin() + left, (*nums).begin() + right + 1); // Use the MergeSort's recursiveSort for small segments
        return;
    }
    if(left >= right){
        return;
    }

    int mid = left + (right - left) / 2;

    thread thread_1([this, left, mid]{
        this->recursiveSort(left,mid);
    });

    thread thread_2([this, mid, right]{
        this->recursiveSort(mid+1, right);
    });

    thread_1.join();
    thread_2.join();

    vector<int> result;
    int i=left, j=mid+1;

    while(i <= mid && j <= right) {
        if((*nums)[i] <= (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }
    while(i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }
    while(j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }

    for(int k = 0; k < result.size(); k++) {
        (*nums)[left+k] = result[k];
    }

    return;
}

void ParallelMergeSort::sort(){
    if((*nums).size()==0) {exit(1);}
    recursiveSort(0, (*nums).size()-1);

    thread thread_1([this]{
        this->recursiveSort(0, (*nums).size()-1);
    });
    thread_1.join();

    // for(int i=0; i<(*nums).size(); i++){
    //     cout<<(*nums)[i]<<"\n";    }
}