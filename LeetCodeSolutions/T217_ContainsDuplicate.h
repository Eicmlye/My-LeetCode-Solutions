/*
    LeetCode 217 Contains Duplicates | Easy
    Tags: Sorting;
    Status: AC; 

    Solution 1: Hash map; 
        Runtime 78 ms, Memory 51.4 MB; Beat 99% / 50%;
        TC O(n), SC O(n);

    Solution 2: Quick sort; 
        Runtime 210 ms, Meomry 46.6 MB; Beat 6% / 91%; 
        TC O(nlogn), SC O(logn) [function iteration stack]; 
*/

#ifndef LEETCODEANSWER_217
#define LEETCODEANSWER_217

#include <vector>
#include <unordered_map>

using std::vector; 
using std::unordered_map; 

class Solution {
public:
    // Solution 1; 
    bool containsDuplicate_1(vector<int>& nums) 
    {
        unordered_map<int, bool> mem = {};

        for (int item : nums) {
            if (mem.count(item) == 0) {
                mem[item] = true;
            }
            else {
                return true;
            }
        }

        return false;
    }

    // Solution 2; 
    bool containsDuplicate_2(vector<int>& nums) 
    {
        size_t len = nums.size();
        QuickSort(nums, 0, len - 1);

        size_t index = 1;
        int mem = nums.at(0);
        int cur = 0;

        while (index < len) {
            cur = nums.at(index);

            if (mem == cur) {
                return true;
            }

            mem = cur;
            ++index;
        }

        return false;
    }

private:
    void QuickSort(vector<int>& nums, size_t low, size_t high) 
    {
        if (low < high) {
            size_t pivotPos = Partition(nums, low, high);
            if (pivotPos > low + 1) { // size_t should not be negative; 
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
        // choose pivot randomly; 
        // rand() generates integer between 0 and INT_MAX; 
        size_t ind = low + (size_t)((high - low) * (rand() / (double)(RAND_MAX)));
        int pivot = nums.at(ind);
        // standardize pivot to the first element; 
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
};

#endif