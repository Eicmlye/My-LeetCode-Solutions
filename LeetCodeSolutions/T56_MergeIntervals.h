/*
	LeetCode 56 Merge Intervals | Medium
	Tags: Sorting;
	Status: AC;

	Solution:
		Runtime 49 ms, Memory 19.9 MB; Beat 65% / 37%;
		TC O(nlogn), SC O(n);
*/

#ifndef LEETCODEANSWER_56
#define LEETCODEANSWER_56

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        QuickSort(intervals, 0, intervals.size() - 1);

        vector<vector<int>> result = {};
        vector<int> cache(2);
        cache = intervals.at(0);

        for (size_t index = 1; index < intervals.size(); ++index) {
            if (cache.at(1) >= intervals.at(index).at(0)) {
                if (intervals.at(index).at(1) > cache.at(1)) {
                    cache.at(1) = intervals.at(index).at(1);
                }
            }
            else {
                result.push_back(cache);
                cache = intervals.at(index);
            }
        }
        result.push_back(cache);

        return result;
    }

private:
    void QuickSort(vector<vector<int>>& nums, size_t low, size_t high)
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

    size_t Partition(vector<vector<int>>& nums, size_t low, size_t high)
    {
        // choose pivot randomly; 
        // rand() generates integer between 0 and INT_MAX; 
        size_t ind = low + (size_t)((high - low) * (rand() / (double)(RAND_MAX)));
        vector<int> pivot = nums.at(ind);
        // standardize pivot to the first element; 
        nums.at(ind) = nums.at(low);
        nums.at(low) = pivot;


        while (low < high) {
            while (low < high && nums.at(high).at(0) >= pivot.at(0)) {
                --high;
            }
            nums.at(low) = nums.at(high);

            while (low < high && nums.at(low).at(0) <= pivot.at(0)) {
                ++low;
            }
            nums.at(high) = nums.at(low);
        }

        nums.at(low) = pivot;

        return low;
    }
};

#endif