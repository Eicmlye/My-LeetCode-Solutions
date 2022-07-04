/*
    LeetCode 215 Kth Largest Element in an Array | Medium
    Tags: Sorting;
    Status: AC;

    Solution 1:
        Runtime 849 ms, Memory 10 MB; Beat 5% / 61%;
        TC O(n^2), SC O(k);

    Solution 2: 
        Runtime 7 ms, Memory 10 MB; Beat 90% / 61%; 
        TC O(nlogn), SC O(logn) [function iteration stack]; 

    Solution 3: Heap sort; 
        Runtime 90 ms, Memory 10.2 MB; Beat 9% / 37%;
        TC O(nlogn), SC O(k);
*/

#ifndef LEETCODEANSWER_215
#define LEETCODEANSWER_215

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    // Solution 1; 
    int findKthLargest_1(vector<int>& nums, int k) {
        vector<int> maxNum(k, INT_MIN);

        for (size_t index = 0; index < nums.size(); ++index) {
            for (size_t jndex = 0; jndex < k; ++jndex) {
                if (nums.at(index) > maxNum.at(jndex)) {
                    for (size_t kndex = 0; kndex < k - jndex - 1; ++kndex) {
                        maxNum.at(k - kndex - 1) = maxNum.at(k - kndex - 2);
                    }
                    maxNum.at(jndex) = nums.at(index);

                    break;
                }
            }
        }

        return maxNum.at(k - 1);
    }

    // Solution 2; 
    int findKthLargest_2(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums.at(k - 1);
    }

    // Solution 3; 
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(k);
        unsigned int count = 0;
        size_t index = 0;

        // initialize heap; 
        while (count < k && index < nums.size()) {
            heap.at(count) = nums.at(index);
            ++count;
            ++index;
        }
        heapSort(heap);

        while (index < nums.size()) {
            if (nums.at(index) > heap.at(0)) { // if nums.at(index) is a new over-kth maximum; 
                heap.at(0) = nums.at(index);

                heapSort(heap);
            }

            ++index;
        }

        return heap.at(0);
    }

private:

    void heapSort(vector<int>& heap)
    {
        size_t max = heap.size() / 2;
        size_t index = 0;

        while (index < max) {
            buildHeap(heap, max - index - 1);
            ++index;
        }

        return;
    }

    void buildHeap(vector<int>& heap, size_t ind)
    {
        bool flagL = false, flagR = false;

        if (ind <= heap.size() / 2 - 1) {
            if (heap.at(2 * ind + 1) < heap.at(ind)) {
                swap(heap, ind, 2 * ind + 1);
                flagL = true;
            }
            if (2 * ind + 2 < heap.size() && heap.at(2 * ind + 2) < heap.at(ind)) {
                swap(heap, ind, 2 * ind + 2);
                flagR = true;
            }

            if (flagL) {
                buildHeap(heap, 2 * ind + 1);
            }
            if (flagR) {
                buildHeap(heap, 2 * ind + 2);
            }
        }

        return;
    }

    void swap(vector<int>& heap, size_t ind, size_t jnd)
    {
        heap.at(ind) += heap.at(jnd);
        heap.at(jnd) = heap.at(ind) - heap.at(jnd);
        heap.at(ind) -= heap.at(jnd);

        return;
    }
};

#endif