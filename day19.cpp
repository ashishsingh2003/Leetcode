// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

//important 
class Solution {
public:
    int helper(vector<int> &b,int k){
        //this function helps to find number of subarrays 1s <=k
        if(k<0)return 0;
        int total=0;int count=0;

        int r=0,l=0;
        while(r<b.size()){
            if(b[r]==1)count++;
            if(count>k){
                while(b[l]!=1)l++;
                count--;l++;
            }
            total+=r-l+1;
            r++;
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        vector<int> bin;
        for(int i=0;i<nums.size();++i){
            if(nums[i]%2==0) bin.push_back(0);
            else bin.push_back(1);
        }
        return helper(bin,k)-helper(bin,k-1);
        
    }
};