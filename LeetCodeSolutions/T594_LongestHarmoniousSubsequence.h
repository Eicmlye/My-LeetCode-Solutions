/*
	LeetCode 594 Longest Harmonious Subsequence | Easy
	Tags: Sorting; 
	Status: AC;

	Solution: Quick sort and Bucket sort; 
		Runtime 232 ms, Memory 35.5 MB; Beat 10% / 81%; 
		TC O(nlogn), SC O(n) [max bucket number is n]; 
*/

#ifndef LEETCODEANSWER_594
#define LEETCODEANSWER_594

#include <vector>

using std::vector; 

class Solution
{
public:
    int findLHS(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        size_t index = 0;
        while (index < nums.size()) {
            if (nums.at(index) < min) {
                min = nums.at(index);
            }
            if (nums.at(index) > max) {
                max = nums.at(index);
            }

            ++index;
        }

        if (max == min) {
            return 0;
        }

        vector<unsigned int> bucket;
        QuickSort(nums, 0, nums.size() - 1);

        unsigned int count = 0;
        index = 0;
        int mem = nums.at(0);
        while (index < nums.size()) {
            if (nums.at(index) == mem) {
                ++count;
                ++index;
            }
            else {
                bucket.push_back(count);

                if (mem - nums.at(index) != -1) { // to exclude incontinuous subsequences; 
                    bucket.push_back(0);
                }
                mem = nums.at(index);
                count = 0;
            }
        }
        bucket.push_back(count);

        index = 0;
        max = 0;
        while (index < bucket.size() - 1) {
            if (bucket.at(index) == 0 || bucket.at(index + 1) == 0) {
                bucket.at(index) = 0;
            }
            else {
                bucket.at(index) += bucket.at(index + 1);
            }
            if (bucket.at(index) > max) {
                max = bucket.at(index);
            }

            ++index;
        }

        return max;
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