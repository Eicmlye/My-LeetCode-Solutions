/*
	LeetCode 628 Maximum Product of Three Numbers | Easy
	Tags: Sorting;
	Status: AC;

	Solution:
		Runtime 48 ms, Memory 27.8 MB; Beat 89% / 35%;
		TC O(nlogn), SC O(1);
*/

#ifndef LEETCODEANSWER_628
#define LEETCODEANSWER_628

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) {
            return nums.at(0) * nums.at(1) * nums.at(2);
        }

        sort(nums.begin(), nums.end());
        vector<int> endNums(6);
        size_t index = 0; // probe from head; 
        size_t kndex = nums.size() - 1; // probe from tail; 
        unsigned int countValidNeg = 0; // non-positive
        unsigned int countValidPos = 0; // non-negative

        // record 3 maxima positives; 
        for (; kndex >= 1 && countValidPos < 3; --kndex) {
            if (nums.at(kndex) >= 0) {
                endNums.at(6 - countValidPos - 1) = nums.at(kndex);
                ++countValidPos;
            }
            else {
                break;
            }
        }

        if (countValidPos == 0) { // return 3 maxima negatives; 
            return nums.at(kndex) * nums.at(kndex - 1) * nums.at(kndex - 2);
        }
        else { // record 3 minima negatives; 
            for (; index < nums.size() && countValidNeg < 3; ++index) {
                if (nums.at(index) <= 0) {
                    endNums.at(countValidNeg) = nums.at(index);
                    ++countValidNeg;
                }
                else {
                    break;
                }
            }
        }

        // The result would be in one of the following 4 cases, ordered in priority: 
        // (1. and 2. are of equal priority)
        // 1. MaxPositive * ProductOfTwoMinNegatives, which is positive;
        // 2. ProductOfThreeMaxPositives, which is positive; 
        // 3. 0; 
        // 4. ProductOfThreeMaxNegatives, which is negative; 
        // The 4th case has already returned; 
        if (countValidPos == 3) {
            return std::max({ endNums.at(3) * endNums.at(4) * endNums.at(5), endNums.at(0) * endNums.at(1) * endNums.at(5) });
        }
        else if (countValidPos > 0) {
            return endNums.at(0) * endNums.at(1) * endNums.at(5);
        }
        else { // countValidNeg < 3; 
            return 0;
        }
    }
};

#endif