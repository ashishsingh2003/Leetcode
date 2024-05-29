// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
// If the current number is even, you have to divide it by 2.
// If the current number is odd, you have to add 1 to it.
// It is guaranteed that you can always reach one for all test cases.
// Example 1:
// Input: s = "1101"
// Output: 6


class Solution {
public:
    int numSteps(string s) {
        int count = 0, carry = 0;
        for(int i = s.size() - 1; i >0; i--) {
            if(s[i] == '0' && carry == 1) carry = 0, s[i] = '1';
            if(s[i] == '1' && carry == 0) carry = 1, count++;
            count++ ;
        }
        return count + carry;
    }
};


//------------------------------GFG---------------------------
// Given three numbers n, x, and y, Geek and his friend are playing a coin game. In the beginning, there are n coins. In each move, a player can pick x, y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to determine whether Geek will win the game or not if both players play optimally.

// Example 1:

// Input: 
// n = 5
// x = 3
// y = 4
// Output: 
// 1
class Solution {
  public:
    bool rec(int n,int x,int y)
    {
        if(n==0)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        bool ans=false;
        if(n-1>=0)
        {
            ans|=!rec(n-1,x,y);
        }
        if(n-x>=0)
        {
            ans|=!rec(n-x,x,y);
        }
        if(n-y>=0)
        {
            ans|=!rec(n-y,x,y);
        }
        return ans;
    }
    int findWinner(int n, int x, int y) {
        // code here
        return rec(n,x,y);
    }
};