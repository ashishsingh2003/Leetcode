// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int,int>m;
        sort(hand.begin(),hand.end());
        if(hand.size()%k!=0)
        {
            return false;
        }
        if(k==1)
        {
            return true;
        }
        for(int i=0;i<hand.size();i++)
        {
            int x=hand[i];
            if(m[i])
            {
                continue;
            }
            int cnt=0;
            for(int j=i+1;j<hand.size();j++)
            {
                if(abs(x-hand[j])==1&&m[j]==0)
                {
                    cout<<abs(x-hand[j]);
                   m[j]=1;
                   cnt++;
                   x=hand[j];
                }
                if(cnt==k-1)
                {
                    break;
                }
            }
            if(cnt==k-1)
            {
                m[i]=1;
            }
            else{
                return false;
            }
        }
        for(auto x:m)
        {
            if(m[x.first]==0)
            {
                return false;
            }
        }
        return true;
    }
};