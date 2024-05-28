// You are given two strings s and t of the same length and an integer maxCost.
// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
// Example 1:
// Input: s = "abcd", t = "bcdf", maxCost = 3
// Output: 3
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int maxi=0;
        int cnt=0;
        while(j<s.length())
        {
            if(s[j]==t[j])
            {
                
                maxi=max(j-i+1,maxi);
                j++;
                continue;
            }
            if(s[j]!=t[j]&&cnt+abs(s[j]-t[j])<=maxCost)
            {
                   cnt+=abs(s[j]-t[j]);
                
                   maxi=max(j-i+1,maxi);

            }
            else{
                while(cnt+abs(s[j]-t[j])>maxCost){
                cnt-=abs(s[i]-t[i]);
                i++;
                }
                cnt+=abs(s[j]-t[j]);
            }
            j++;
        }
     return maxi;
    }
};
//Learning->always read question properly and do not make your solution by just seeing testcases.Think about what question want 
//to say

//--------------------------GFG----------------------------------
// Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents the cost of an i kg packet of oranges, the task is to find the minimum cost to buy exactly w kg of oranges. The cost array has a 1-based indexing. If buying exactly w kg of oranges is impossible, then return -1.
// Note:
// 1. cost[i] = -1 means that i kg packet of orange is unavailable.
// 2. It may be assumed that there is an infinite supply of all available packet types.

// Example 1:

// Input: 
// n = 5
// cost[] = {20, 10, 4, 50, 100} 

class Solution {
  public: 
    int rec(int n,int w,vector<int>&c,int i, vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            if(w==0)
            {
                return 0;
            }
            return 1e9;
        }
        if(w==0)
        {
            
            return 0;
        }
        if(w<0)
        {
            return 1e9;
        }
         if(dp[w][i]!=-1)
         {
             return dp[w][i];
         }
        int ans=INT_MAX;
        
        if(c[i]!=-1)
        {
            ans=min(ans,c[i]+rec(n,w-i-1,c,i,dp));}
            ans=min(ans,rec(n,w,c,i+1,dp));
        
       
      
        return dp[w][i]=ans;
    }
    int minimumCost(int n, int w, vector<int> &c) {
        // code here
        vector<vector<int>>dp(w+1,vector<int>(n,-1));
        return rec(n,w,c,0,dp);
    }
};


