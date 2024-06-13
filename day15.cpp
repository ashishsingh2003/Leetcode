// There are n seats and n students in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. You are also given the array students of length n, where students[j] is the position of the jth student.

// You may perform the following move any number of times:

// Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)
// Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

// Note that there may be multiple seats or students in the same position at the beginning.

 

// Example 1:

// Input: seats = [3,1,5], students = [2,7,4]
// Output: 4
class Solution {
public:
    int minMovesToSeat(vector<int>& st, vector<int>& s) {
        int ans=0;
        map<int,int>m;
        sort(st.begin(),st.end());
        
        sort(s.begin(),s.end());
        
        for(int i=0;i<st.size();i++)
        {
            int h=abs(s[i]-st[i]);
            ans+=h;
        

        }
        return ans;
    }
};


// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

// While there is a '*', do the following operation:

// Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
// Return the 
// lexicographically smallest
//  resulting string after removing all '*' characters.

 

// Example 1:

// Input: s = "aaba*"

// Output: "aab"


class Solution {
public:
    struct node{
        char ch;
        int idx;
    };
    struct compare{
        bool operator()(const node &a,const node &b)
        {
            if(a.ch==b.ch)return a.idx<b.idx;
            return a.ch>b.ch;
        }
    };
    string clearStars(string s) {
        priority_queue<node,vector<node>,compare>p;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                p.pop();
            }
            if(s[i]!='*')
            {
                p.push({s[i],i});
            }
        }
        string ans;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>q;
        while(!p.empty())
        {
            
            q.push({p.top().idx,p.top().ch});
            p.pop();
            
        }
        while(!q.empty())
        {
            ans+=q.top().second;
            q.pop();
        }
        return ans;
    }
};