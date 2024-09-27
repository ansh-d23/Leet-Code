class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<k;i++) leftsum+=cardPoints[i];

        int n = cardPoints.size();

        int maxsum = leftsum;

        for(int i=0;i<k;i++){

            leftsum -=cardPoints[k-i-1];
            rightsum += cardPoints[n-i-1];

            maxsum = max(maxsum , (leftsum+rightsum));
        }

        return maxsum;
        
    }
};