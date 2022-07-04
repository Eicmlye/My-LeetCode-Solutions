/*
	LeetCode 747 Largest Number At Least Twice of Others | Easy
	Tags: Sorting;
	Status: AC;

	Solution:
		Runtime 4 ms, Memory 10.8 MB; Beat 64% / 68%;
		TC O(), SC O();
*/

#ifndef LEETCODEANSWER_747
#define LEETCODEANSWER_747

#include <vector>

using std::vector;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int maxNum = INT_MIN;
        size_t maxInd = 0;
        int secondMax = INT_MIN;
        size_t index = 0;

        for (; index < nums.size(); ++index) {
            if (nums.at(index) > maxNum) {
                secondMax = maxNum;
                maxNum = nums.at(index);
                maxInd = index;
            }
            else if (nums.at(index) > secondMax) {
                secondMax = nums.at(index);
            }
        }

        return (maxNum >= 2 * secondMax) ? maxInd : -1;
    }
};

#endif