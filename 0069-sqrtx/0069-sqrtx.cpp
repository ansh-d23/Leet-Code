class Solution {
public:
    int mySqrt(int x) {
        int end = (x/ 2) + 1;
        int start = 1;
        int ans=start;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (pow(mid, 2) == x) return mid;
            if (pow(mid, 2) > x) end = mid - 1;
            else{
                ans=mid;
                start = mid + 1;
            }
        }
        return ans;
    }
};