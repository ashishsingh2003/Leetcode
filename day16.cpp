// You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

// Return the minimum number of moves to make every value in nums unique.

// The test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: 1

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                if(nums[i]<nums[i-1]){
                cnt+=2;
                nums[i]+=2;
                }
                else{
                    cnt+=1;
                    nums[i]+=1;
                }
            }
        }
        return cnt;
    }
};