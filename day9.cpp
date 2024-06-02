// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

class Solution {
public:
    void reverseString(vector<char>& s) {
         int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};


//------------------GFG-----------------------
// Given a list s that initially contains only a single value 0. There will be q queries of the following types:

// 0 x: Insert x in the list
// 1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
// Return the sorted list after performing the given q queries.

// Example 1:

// Input:
// q = 5
// queries[] = {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}}
// Output:
// 1 2 3 7

  vector<int> constructList(int q, vector<vector<int>> &qa) {
        // code here
        vector<int>v(1,0);
        int l=-1;
       
        int xori=0;
        for(int i=q-1;i>=0;i--)
        {
            if(qa[i][0]==0)
            {
                v.push_back(qa[i][1]^xori);
            }
            else{
                xori=xori^qa[i][1];
            }
        }
        v[0]=v[0]^(xori);
        sort(v.begin(),v.end());
        return v;
    }