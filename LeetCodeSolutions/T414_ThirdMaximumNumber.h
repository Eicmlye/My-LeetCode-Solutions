/*
	LeetCode 414 Third Maximum Number | Easy
	Tags: Sorting; 
	Status: AC; 

	Solution 1: Quick sort; 
		Runtime 8 ms, Memory 9.1 MB; Beat 67% / 51%; 
		TC O(nlogn), SC O(logn) [function iteration stack]; 

    Solution 2: Heap sort; 
        Runtime 7 ms, Memory 10.5 MB; Beat 77% / 35%; 
        TC O(nlogn), SC O(n); 
*/

#ifndef LEETCODEANSWER_414
#define LEETCODEANSWER_414

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    // Solution 1; 
    int thirdMax_1(vector<int>& nums) {
        size_t len = nums.size();
        QuickSort(nums, 0, len - 1);

        bool flag = false;
        size_t index = 1;
        int mem = nums.at(len - 1);
        int cur = mem;

        while (index < len) {
            cur = nums.at(len - index - 1);

            if (cur != mem) {
                if (flag) {
                    return cur;
                }

                flag = true;
                mem = cur;
            }

            ++index;
        }

        return nums.at(len - 1);
    }

    // Solution 2;
    int thirdMax_2(vector<int>& nums)
    {
        vector<int> heap(3);
        int max = nums.at(0);
        unordered_map<int, unsigned int> existsInHeap = {};
        unsigned int count = 0;
        size_t index = 0;

        // initialize heap; 
        while (count < 3 && index < nums.size()) {
            if (existsInHeap.count(nums.at(index)) == 0) {
                heap.at(count) = nums.at(index);
                ++count;
                existsInHeap[nums.at(index)] = 1;

                if (nums.at(index) > max) {
                    max = nums.at(index);
                }
            }

            ++index;
        }
        heapSort(heap);

        // if 3rd max doesn't exist; 
        if (count < 3) {
            return max;
        }

        while (index < nums.size()) {
            if (existsInHeap[nums.at(index)] == 0) { // if nums.at(index) isn't in the heap; 
                if (nums.at(index) > heap.at(0)) { // if nums.at(index) is a new over-3rd maximum; 
                    existsInHeap[heap.at(0)] = 0;
                    existsInHeap[nums.at(index)] = 1;

                    heap.at(0) = nums.at(index);

                    heapSort(heap);
                }
            }

            ++index;
        }

        return heap.at(0);
    }

private:
    void QuickSort(vector<int>& nums, size_t low, size_t high)
    {
        if (low < high) {
            size_t pivotPos = Partition(nums, low, high);
            if (low + 1 < pivotPos) {
                QuickSort(nums, low, pivotPos - 1);
            }
            if (pivotPos + 1 < high) {
                QuickSort(nums, pivotPos + 1, high);
            }
        }

        return;
    }

    size_t Partition(vector<int>& nums, size_t low, size_t high)
    {
        size_t ind = low + (size_t)((high - low) * (rand() / (double)(RAND_MAX)));
        int pivot = nums.at(ind);
        nums.at(ind) = nums.at(low);
        nums.at(low) = pivot;

        while (low < high) {
            while (low < high && nums.at(high) >= pivot) {
                --high;
            }
            nums.at(low) = nums.at(high);

            while (low < high && nums.at(low) <= pivot) {
                ++low;
            }
            nums.at(high) = nums.at(low);
        }
        nums.at(low) = pivot;

        return low;
    }

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