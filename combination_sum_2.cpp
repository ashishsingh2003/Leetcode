// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
class Solution {
public:
    vector<vector<int>>v;
    void rec(vector<int>c,int t,vector<int>&ans,int ind,int sum)
    {
       
        if(sum==t)
        {
            v.push_back(ans);
            return;
        }
        if(sum>t)
        {
            return;
        }
        for(int i=ind;i<c.size();i++)
        {
            if(i==ind||c[i]!=c[i-1]){
            ans.push_back(c[i]);
            rec(c,t,ans,i+1,sum+c[i]);
            ans.pop_back();
            }
            
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<int>ans;
        sort(c.begin(),c.end());
        rec(c,t,ans,0,0);
       
        return v;
    }
};

//whenever you have to find unique combination sort the array and check that if previous element is same as current that means
//combination with this number has been computed and no need to compute it now