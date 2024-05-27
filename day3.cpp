// You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
// Notice that x does not have to be an element in nums.
// Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
// Example 1:
// Input: nums = [3,5]
// Output: 2

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int x=nums.size();
        int ans=-1;
        for(int i=1;i<=x;i++)
        {
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                if(i<=nums[j])
                {
                    count++;
                }
            }
            if(count==i)
            {
                ans=count;
            }
        }
        return ans;
    }
};


//------------------------------GFG----------------------------
// Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

// Example 1:

// Input:
// n = 7
// a[] = {10, 9, 4, 5, 4, 8, 6}

class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code 
        int maxi=1;
        vector<int>v(n,1);
        for(int i=0;i<n;i++)
        {
            int cmp=a[i];
            int cnt=1;
            int maxi2=v[i];
            for(int j=i-1;j>=0;j--)
            {
                if(abs(cmp-a[j])==1)
                {
                   maxi2=max(maxi2,v[j]+1);
                }
               
            }
            v[i]=max(v[i],maxi2);
            maxi=max(maxi,v[i]);
        }
        return maxi;}
};