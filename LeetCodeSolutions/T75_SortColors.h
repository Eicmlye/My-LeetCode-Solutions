/*
    LeetCode 75 Sort Colors | Medium
    Tags: Sorting;
    Status: AC;

    Solution 1: Quick sort; 
        Runtime 0 ms, Memory 8.3 MB;
        TC O(nlogn), SC O(logn) [function iteration stack];

    Solution 2: 2-pointer; 
        Runtime 0 ms, Memory 8.3 MB;
        TC O(n), SC O(1);
*/

#ifndef LEETCODEANSWER_75
#define LEETCODEANSWER_75

#include <vector>

using std::vector;

class Solution {
public:
    // Solution 1; 
    void sortColors_1(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
    }

    // Solution 2; 
    void sortColors(vector<int>& nums) {
        size_t OneHead = 0;
        int OneTail = nums.size() - 1;
        int mov = 0;

        while (mov <= OneTail) {
            if (nums.at(mov) == 0) {
                if (mov != OneHead) {
                    nums.at(mov) += nums.at(OneHead);
                    nums.at(OneHead) = nums.at(mov) - nums.at(OneHead);
                    nums.at(mov) -= nums.at(OneHead);
                }
                ++OneHead;
            }
            else if (nums.at(mov) == 2) {
                if (mov != OneTail) {
                    nums.at(mov) += nums.at(OneTail);
                    nums.at(OneTail) = nums.at(mov) - nums.at(OneTail);
                    nums.at(mov) -= nums.at(OneTail);
                }
                --OneTail;
                --mov;
            }

            ++mov;
        }

        return;
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