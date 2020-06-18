//https://leetcode.com/problems/subsets/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isIthBitSet(int n, int i){
        return n & (1 << i);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int nSubsets = 1 << nums.size();
        vector<vector<int>> answ;
        for(int i = 0; i < nSubsets; i++){
            vector<int> aux;
            for(int j = 0; j < nums.size(); j++)
                if(isIthBitSet(i,j)) aux.push_back(nums[j]);
            answ.push_back(aux);
        }
        return answ;
    }
};

/***
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
***/