/*
    LeetCode 169 Majority Element | Easy
    Tags: Sorting;
    Status: AC; 

    Solution: Boyer¨CMoore majority vote algorithm; 
        Runtime 13 ms, Memory 19.5 MB; Beat 92% / 58%; 
        TC O(n), SC O(1);
*/

#ifndef LEETCODEANSWER_169
#define LEETCODEANSWER_169

#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int maj = nums.at(0);
        unsigned int vote = 1;
        size_t index = 1;
        size_t len = nums.size();

        while (index < len) {
            if (vote != 0) {
                if (nums.at(index) == maj) {
                    ++vote;
                }
                else {
                    --vote;
                }
            }
            else {
                maj = nums.at(index);
                ++vote; // vote = 1; 
            }

            ++index;
        }

        return maj;
    }
};

#endif