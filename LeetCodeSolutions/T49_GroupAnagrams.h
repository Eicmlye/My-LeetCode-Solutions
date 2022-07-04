/*
    LeetCode 49 Group Anagrams | Medium
    Tags: Sorting;
    Status: AC;

    Solution: Hash map; 
        Runtime 32 ms, Memory 20.8 MB; Beat 95% / 37%;
        TC O(nlogn), SC O(n);
*/

#ifndef LEETCODEANSWER_49
#define LEETCODEANSWER_49

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::pair;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> root = {};
        for (size_t index = 0; index < strs.size(); ++index) {
            string copy = strs.at(index);
            sort(copy.begin(), copy.end());

            root[copy].push_back(strs.at(index));
        }

        vector<vector<string>> result = {};
        for (pair<string, vector<string>> item : root) {
            result.push_back(item.second);
        }

        return result;
    }
};

#endif