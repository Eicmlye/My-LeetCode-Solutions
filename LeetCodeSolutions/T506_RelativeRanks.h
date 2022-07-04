/*
	LeetCode 506 Relative Ranks | Easy
	Tags: Sorting; 
	Status: AC;

	Solution: Quick sort; 
		Runtime 15 ms, Memory 10 MB; Beat 82% / 93%; 
		TC O(nlogn), SC O(n); 
*/

#ifndef LEETCODEANSWER_506
#define LEETCODEANSWER_506

#include <vector>
#include <string>

using std::vector; 
using std::string;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size(), "");
        vector<size_t> index(score.size());

        for (size_t ind = 0; ind < score.size(); ++ind) {
            index.at(ind) = ind;
        }
        QuickSort(index, score, 0, score.size() - 1);

        for (size_t ind = 0; ind < score.size(); ++ind) {
            switch (ind) {
            case 0:
                result.at(index.at(ind)) = "Gold Medal";
                break;
            case 1:
                result.at(index.at(ind)) = "Silver Medal";
                break;
            case 2:
                result.at(index.at(ind)) = "Bronze Medal";
                break;
            default:
                result.at(index.at(ind)) = std::to_string(ind + 1);
            }
        }

        return result;
    }

private:
    void QuickSort(vector<size_t>& index, vector<int>& nums, size_t low, size_t high)
    {
        if (low < high) {
            size_t pivotPos = Partition(index, nums, low, high);
            if (pivotPos > low + 1) { // size_t should not be negative; 
                QuickSort(index, nums, low, pivotPos - 1);
            }
            if (pivotPos + 1 < high) {
                QuickSort(index, nums, pivotPos + 1, high);
            }
        }

        return;
    }

    // large to small; 
    size_t Partition(vector<size_t>& index, vector<int>& nums, size_t low, size_t high)
    {
        // choose pivot randomly; 
        // rand() generates integer between 0 and INT_MAX; 
        size_t ind = low + (size_t)((high - low) * (rand() / (double)(RAND_MAX)));
        int pivot = nums.at(ind);
        size_t pivotInd = index.at(ind);
        // standardize pivot to the first element; 
        nums.at(ind) = nums.at(low);
        index.at(ind) = index.at(low);
        nums.at(low) = pivot;
        index.at(low) = pivotInd;


        while (low < high) {
            while (low < high && nums.at(high) <= pivot) {
                --high;
            }
            nums.at(low) = nums.at(high);
            index.at(low) = index.at(high);

            while (low < high && nums.at(low) >= pivot) {
                ++low;
            }
            nums.at(high) = nums.at(low);
            index.at(high) = index.at(low);
        }

        nums.at(low) = pivot;
        index.at(low) = pivotInd;

        return low;
    }
};

#endif