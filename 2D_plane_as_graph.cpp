// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

//here 2D array question is solved with the help of graph.
class Solution {
public:
    void dfs(int n,int idx,vector<bool>&vis,vector<vector<int>>&s)
    {
        vis[idx]=true;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(s[idx][0]==s[i][0])
                {
                    dfs(n,i,vis,s);
                }
                if(s[idx][1]==s[i][1])
                {
                    dfs(n,i,vis,s);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& s) {
        int n=s.size();
        vector<bool>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(n,i,vis,s);
                cnt++;
            }
        }
        return n-cnt;
    }
};