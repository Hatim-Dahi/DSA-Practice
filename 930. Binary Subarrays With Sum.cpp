#include<bits/stdc++.h>
using namespace std;
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result = 0;

        // sliding window
        for (int l = 0, r = 0, sum = 0, tail = 0; r < nums.size(); r++) {
            sum += nums[r];

            if (nums[r] == 1) tail = 0;

            while ((l <= r) && (sum >= goal)) {
                // record the length of the tail zero(s)
                if (sum == goal) tail++;
                sum -= nums[l++];
            }
            
            result += tail;
        }
        return result;
    }