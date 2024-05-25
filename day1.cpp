// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word.
// Return all such possible sentences in any order.
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


// -------------------GFG Question---------------------

// You have n stacks of books. Each stack of books has some nonzero height arr[i] equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books arr[i] <= k. Once such a sequence of stacks is chosen, You can collect any number of books from the chosen sequence of stacks.
// What is the maximum number of books that you can collect this way?

// Example 1

// Input
// 8 1
// 3 2 2 3 1 1 1 3
// Output
// 3
class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long maxi=0;
        long long sum=0;
        for(long long i=0;i<n;i++)
        {
            if(arr[i]<=k)
            {
                sum+=arr[i];
                maxi=max(maxi,sum);
            }
            else{
                sum=0;
            }
        }
        return maxi;
    }
};