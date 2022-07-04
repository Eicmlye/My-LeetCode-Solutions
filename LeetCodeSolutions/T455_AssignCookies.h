/*
	LeetCode 455 Assign Cookies | Easy
	Tags: Sorting; 
	Status: AC;

	Solution: Quick sort and Greedy; 
		Runtime 45 ms, Memory 17.4 MB; Beat 35% / 77%; 
		TC O(maxLen logmaxLen), SC O(logmaxLen) [function iteration stack]; 
*/

#ifndef LEETCODEANSWER_455
#define LEETCODEANSWER_455

#include <vector>

using std::vector; 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        if (g.size() * s.size() == 0) {
            return 0;
        }

        QuickSort(g, 0, g.size() - 1);
        QuickSort(s, 0, s.size() - 1);

        size_t index = 0;
        size_t jndex = 0;

        while (index < g.size() && jndex < s.size()) {
            if (s.at(jndex) >= g.at(index)) {
                ++jndex;
            }

            ++index;
        }

        return jndex;
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

    // large to small; 
    size_t Partition(vector<int>& nums, size_t low, size_t high)
    {
        size_t ind = low + (size_t)((high - low) * (rand() / (double)(RAND_MAX)));
        int pivot = nums.at(ind);
        nums.at(ind) = nums.at(low);
        nums.at(low) = pivot;

        while (low < high) {
            while (low < high && nums.at(high) <= pivot) {
                --high;
            }
            nums.at(low) = nums.at(high);

            while (low < high && nums.at(low) >= pivot) {
                ++low;
            }
            nums.at(high) = nums.at(low);
        }
        nums.at(low) = pivot;

        return low;
    }
};

#endif