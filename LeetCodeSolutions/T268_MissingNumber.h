/*
	LeetCode 268 Missing Number | Easy
	Tags: Sorting; 
	Status: AC; 

	Solution 1: Summation; 
		Runtime 17 ms, Memory 18 MB; Beat 92% / 19%; 
        TC O(n), SC O(1); 

    Solution 2: Bounded number list, solve with flag list; 
		Runtime 18 ms, Memory 18 MB; Beat 90% / 19%; 
        TC O(n), SC O(n); 

    Solution 3: Quick sort; 
        Runtime 38 ms, Memory 18.1 MB; Beat 22% / 19%; 
        TC O(nlogn), SC O(logn) [function iteration stack]; 
*/

#ifndef LEETCODEANSWER_268
#define LEETCODEANSWER_268

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    // Solution 1; 
    int missingNumber_1(vector<int>& nums) {
        // sum up 0 to nums.size(); 
        long sum = nums.size();
        sum = sum * (sum + 1) / 2;

        for (int item : nums) {
            sum -= item;
        }

        return sum;
    }

    // Solution 2; 
    int missingNumber_2(vector<int>& nums) {
        size_t len = nums.size();
        vector<bool> flags(len + 1);

        for (int item : nums) {
            flags.at(item) = true;
        }
        for (size_t index = 0; index < len + 1; ++index) {
            if (!flags.at(index)) {
                return index;
            }
        }
    }

    // Solution 3; 
    int missingNumbe_3(vector<int>& nums) {
        size_t len = nums.size();
        QuickSort(nums, 0, len - 1);

        for (size_t index = 0; index < len; ++index) {
            if (index != nums.at(index)) {
                return index;
            }
        }

        return len;
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