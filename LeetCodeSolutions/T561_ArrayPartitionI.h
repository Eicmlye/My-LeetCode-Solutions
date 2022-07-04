/*
	LeetCode 561 Array Partition I | Easy
	Tags: Sorting; 
	Status: AC;

	Solution 1: Quick sort; 
		Runtime 128 ms, Memory 28.2 MB; Beat 5% / 47%; 
		TC O(nlogn), SC O(logn) [function iteration stack]; 
    
    Solution 2: Bucket sort; 
        https://leetcode.com/problems/array-partition-i/discuss/1379603/C%2B%2B-O(N)-In-depth-Explanation; 
        Runtime 60 ms, Memory 36.2 MB; Beat 84% / 5%; 
        TC O(n + bucketSize), SC O(bucketSize); 
*/

#ifndef LEETCODEANSWER_561
#define LEETCODEANSWER_561

#include <vector>

using std::vector; 

class Solution {
public:
    // Solution 1; 
    int arrayPairSum_1(vector<int>& nums)
    {
        QuickSort(nums, 0, nums.size() - 1);
        int sum = 0;

        for (size_t index = 0; 2 * index + 1 < nums.size(); ++index) {
            sum += nums.at(2 * index + 1);
        }

        return sum;
    }

    // Solution 2; 
    int arrayPairSum_2(vector<int>& nums)
    {
        int max = 10000;
        int min = -10000;
        int capacity = max - min + 1;
        int inc = (max - min) / 2;

        vector<int> bucket(capacity); // contain the unreachable limit will be convenient for later summation process; 
        int result = 0;
        for (size_t index = 0; index < nums.size(); ++index) {
            ++bucket.at(nums.at(index) + inc);
        }

        for (size_t index = 0; index < capacity; ++index) {
            while (bucket.at(index) > 0) {
                result += index - inc;
                bucket.at(index) -= 2;
            }

            if (bucket.at(index) < 0) {
                --bucket.at(index + 1);
            }
        }

        return result;
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

    // large to small; 
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