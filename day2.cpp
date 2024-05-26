// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

// Example 1:

// Input: n = 2
// Output: 8
// Explanation: There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"

class Solution {
public:
    int mod=1e9+7;
    int rec(int &n,int i,int a,int l, vector<vector<vector<int>>>&dp)
    {
        if(a>=2||l>=3)
        {
            return 0;
        }
        if(i==n)
        {
            return 1;
        }
        if(dp[i][a][l]!=-1)
        {
            return dp[i][a][l];
        }
        int result=0;
        result=(result+rec(n,i+1,a,0,dp))%mod;
        result=(result+rec(n,i+1,a+1,0,dp))%mod;
        result=(result+rec(n,i+1,a,l+1,dp))%mod;
        return dp[i][a][l]=result%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(n,-1)));
        return rec(n,0,0,0,dp);
    }
};