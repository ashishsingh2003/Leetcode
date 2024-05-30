// Given an array of integers arr.
// We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
// Let's define a and b as follows:
// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// Note that ^ denotes the bitwise-xor operation.
// Return the number of triplets (i, j and k) Where a == b.
// Example 1:

// Input: arr = [2,3,1,6,7]
// Output: 4

class Solution {
public:
    int countTriplets(vector<int>& arr) {
       vector<int>s(arr.size(),0);
        int x=0;
        for(int i=0;i<arr.size();i++)
        {
            x^=arr[i];
            s[i]=x;
        }
        int ans=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            
            for(int j=i+1;j<arr.size();j++)
            {
                for(int k=j;k<arr.size();k++)
                {
                    int a=(s[k]^s[j-1]);
                    int b;
                    if(i>0){
                    b=s[j-1]^s[i-1];
                    }
                    else{
                        b=s[j-1];
                    }
                    
                    if(a==b)
                    {
                        ans++;
                    }
                    

                }
            }
        }
        return ans;
    }
};

//---------------------GFG-----------------------------
// Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.
// Return the total count modulo 1e9+7.
// Example 1:

// Input: 
// s1 = geeksforgeeks
// s2 = gks
// Output:
// 4
class Solution {
  public:
    int count=0;
    int mod=1e9+7;
    int rec(string s,string s2,int i,int j,vector<vector<int>>&dp)
    {
        if(j>=s2.length())
        {
            
            return 1;
        }
        if(i>=s.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int inc=0,exc=0;
        if(s[i]==s2[j])
        {
            inc+=rec(s,s2,i+1,j+1,dp);
        }
        exc+=rec(s,s2,i+1,j,dp);
        return dp[i][j]=(inc+exc)%mod;
    }
    int countWays(string s1, string s2) {
        // code here
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
     return rec(s1,s2,0,0,dp)%mod;
     return count%mod;
    }
};