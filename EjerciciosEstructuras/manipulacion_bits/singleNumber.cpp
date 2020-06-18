//https://leetcode.com/submissions/#/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum ^= nums[i];
        return sum;
    }
};

/***
Input: [2,2,1]
Output: 1
***/