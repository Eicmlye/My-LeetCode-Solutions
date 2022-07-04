/*
	LeetCode 922 Sort Array By Parity II | Easy
	Tags: Sorting;
	Status: AC;

	Solution: 2-pointer
		Runtime 25 ms, Memory 21.3 MB; Beat 79% / 98%;
		TC O(n), SC O(1);
*/

#ifndef LEETCODEANSWER_922
#define LEETCODEANSWER_922

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        size_t even = 0;
        size_t odd = 1;

        while (even < nums.size() && odd < nums.size()) {
            while (even < nums.size() && nums.at(even) % 2 == 0) {
                even += 2;
            }
            if (even >= nums.size()) {
                break;
            }

            if (nums.at(even) % 2 != 0) {
                while (nums.at(odd) % 2 != 0) {
                    odd += 2;
                }

                nums.at(even) += nums.at(odd);
                nums.at(odd) = nums.at(even) - nums.at(odd);
                nums.at(even) -= nums.at(odd);

                even += 2;
                odd += 2;
            }
        }

        return nums;
    }
};

#endif