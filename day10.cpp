// Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

// Example 1:

// Input: s = "10"
// Output: 11


string binaryNextNumber(string s) {
        // code here.
        int carry=1;
        string ans;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='1'&&carry==1)
            {
                ans+="0";
                carry=1;
            }
            else if(s[i]=='0'&&carry==0)
            {
                ans+="0";
            }
            else{
                carry=0;
                ans+="1";
            }
            
        }
        
        if(carry==1)
        ans+=to_string(carry);
        
        
        reverse(ans.begin(),ans.end());
        
        string a;
        int flag=0;
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]=='1')
            {
                flag=1;
                a+="1";
            }
            else if(flag)
            {
                a+=ans[i];
            }
        }
        
        return a;
    }

    //------------------Leetcode-------------------------
//  Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
// palindrome
//  that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7


class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>m;
        int ans=0;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            if(m[s[i]]%2==0)
            {
                ans+=2;
            }
        }
        for(auto x:m)
        {
            if(m[x.first]%2!=0)
            {
                return ans+1;
            }
        }
        return ans;
    }
};