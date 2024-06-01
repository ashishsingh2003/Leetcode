// You are given a string s. 
// The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
// Return the score of s.

 

// Example 1:

// Input: s = "hello"

// Output: 13

class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=1;i<s.size();i++)
        {
            int x=s[i]-'a';
            int y=s[i-1]-'a';
            sum+=abs(x-y);
        }
        return sum;
    }
};
//----------------GFG Questions---------------------
// Given a string s of lowercase English characters, find out whether the summation of x and y is even or odd, where x is the count of distinct characters that occupy even positions in English alphabets and have even frequency, y is the count of distinct characters which occupy odd positions in English alphabets and have odd frequency.
// Note: Positive means greater than zero.

// Example 1:

// Input: 
// s = "abbbcc"
// Output: 
// ODD
string oddEven(string s) {
        // code here
        set<char>st;
        map<char,int>m;
        map<char,int>p;
        map<char,int>h;
        for(int i=0;i<s.length();i++)
        {
           if(((s[i]-'a')+1)%2==0)
           {
               
               m[s[i]]++;
           }
           else{
               p[s[i]]++;
           }
           h[s[i]]++;
           
        }
    
        int ans=0;
        for(auto x:m)
        {
            if(h[x.first]%2==0)
            {
                
                ans++;
            }
        }
        
        for(auto x:p){
            if(h[x.first]%2!=0)
            {
               
                ans++;
            }
        }
        
        if(ans%2==0)
        {
            return "EVEN";
        }
        else{
            return "ODD";
        }
    }
};
