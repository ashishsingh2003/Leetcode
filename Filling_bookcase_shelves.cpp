// You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

// We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

// We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

// Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

// For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
// Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.
//so here if you think that problem can be solved by includion and exclusion but not possible in practical then you can use bottom up approach
 class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfwidth) {
        int n=books.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int width=0;
            int maxi=0;
            for(int j=i;j>0;j--)
            {
                width+=books[j-1][0];
                if(width>shelfwidth)
                {
                    break;
                }
                maxi=max(maxi,books[j-1][1]);
                dp[i]=min(dp[i],dp[j-1]+maxi);

            }
        }
        return dp[n];
    }
};