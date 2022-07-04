/*
    LeetCode 88 Merge Sorted Array | Easy
    Tags: Sorting; 
    Status: AC; 

    Solution: 2-pointer; 
        Runtime 0 s, Memory 9.2 MB; 
        TC O(destLen + srcLen), SC O(destLen + srcLen); 
*/

#ifndef LEETCODEANSWER_88
#define LEETCODEANSWER_88

#include <vector>

using std::vector; 

class Solution_88 {
public:
    void merge(vector<int>& dest, int destLen, vector<int>& src, int srcLen) 
    {
        size_t index = 0;
        size_t jndex = 0;
        vector<int> result = {};

        while (index < destLen && jndex < srcLen) {
            if (dest.at(index) <= src.at(jndex)) {
                result.push_back(dest.at(index));
                ++index;
            }
            else {
                result.push_back(src.at(jndex));
                ++jndex;
            }
        }

        while (index < destLen) {
            result.push_back(dest.at(index));
            ++index;
        }
        while (jndex < srcLen) {
            result.push_back(src.at(jndex));
            ++jndex;
        }

        dest = result;

        return;
    }
};

#endif