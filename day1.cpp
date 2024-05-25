// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]


class Solution {
public:
    void rec(unordered_set<string>&v,string s,unordered_map<string,int>&w,int i,string ans,bool flag)
    {
        if(s.length()==0)
        {
            if(flag)
            {
                
                ans=ans.substr(0,ans.length()-1);
                
                v.insert(ans);
            }
            return;
        }
        for(int j=1;j<=s.length();j++){
        string r=s.substr(0,j);
        if(w[r]>0){
         
        
        rec(v,s.substr(j),w,1,ans+r+" ",true);
        }
        
        }

        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wo) {
        
        unordered_map<string,int>w;
        for(int i=0;i<wo.size();i++)
        {
            w[wo[i]]++;
        }
        unordered_set<string>v;
        
        rec(v,s,w,1,"",false);
 
        vector<string> ans;
        for(auto x:v)
        {
          ans.push_back(x);
        }
        
        return ans;
    }
};