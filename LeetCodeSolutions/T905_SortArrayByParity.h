/*
	LeetCode 905 Sort Array By Parity | Easy
	Tags: Sorting;
	Status: AC;

	Solution: 2-pointer
		Runtime 3 ms, Memory 16.1 MB; Beat 99% / 95%;
		TC O(n), SC O(1);
*/

#ifndef LEETCODEANSWER_905
#define LEETCODEANSWER_905

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        size_t index = 0;
        size_t jndex = nums.size() - 1;

        while (index < jndex) {
            while (index < jndex && nums.at(index) % 2 == 0) {
                ++index;
            }
            while (index < jndex && nums.at(jndex) % 2 != 0) {
                --jndex;
            }

            if (index == jndex) {
                break;
                // when index == jndex, swaping will truncate the data; 
            }
            if (nums.at(index) % 2 != 0) {
                nums.at(index) += nums.at(jndex);
                nums.at(jndex) = nums.at(index) - nums.at(jndex);
                nums.at(index) -= nums.at(jndex);
            }
        }

        return nums;
    }
};

#endif