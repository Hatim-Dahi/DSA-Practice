#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pre[n];
        int suff[n];
        vector<int> ans;
        int i=0,j=n-1;
        int leftPro=1;
        int rightPro=1;
        while(i<n && j>=0){
            leftPro*=nums[i];
            rightPro*=nums[j];
            pre[i]=leftPro;
            suff[j]=rightPro;
            i++,j--;
        }        
        ans.push_back(suff[1]);
        for(int i=1;i<n;i++){
          if(i==n-1){
            ans.push_back(pre[i-1]);  
          }else{
          ans.push_back(pre[i-1]*suff[i+1]);
          }
        }

        return ans;
    }
};