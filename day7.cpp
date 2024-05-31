// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
//Find the two elements that appear only once. You can return the answer in any order.
// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto num:nums)
        {
            x^=num;
        }
        int bit;
        for(int i=0;i<32;i++)
        {
            if(x&(1<<i)){
                bit=i;
                break;
            }
        }
        int first=0;
        for(auto num:nums)
        {
            if((num&(1<<bit)))
            {
                first^=num;
            }

        }
        int second=first^x;
        return {first,second};
    }
};

//-----------------------GFG-------------------------
// Given a number n, Your task is to swap the two nibbles and find the resulting number. 

// A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. This byte can be divided into two nibbles: 1001 and 0110.

// Example 1:

// Input: n = 100
// Output: 70

 int swapNibbles(int n) {
        // code here
        string s;
        for(int i=0;i<8;i++)
        {
            if(n&(1<<i))
            {
                s+="1";
            }
            else{
                s+="0";
            }
        
        }
        int ans=0;
       reverse(s.begin(),s.end());
       int j=0;
       for(int i=3;i>=0;i--)
       {
           if(s[i]=='1')
           {
               ans+=pow(2,j);
           }
           j++;
       }
       for(int i=s.length()-1;i>=4;i--)
       {
           if(s[i]=='1')
           {
               ans+=pow(2,j);
           }
           j++;
       }
        return ans;
    }