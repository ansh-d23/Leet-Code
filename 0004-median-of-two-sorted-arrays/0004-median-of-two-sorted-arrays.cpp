class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);

        int l=0,r=n;
        while(l<=r)
        {
            int Px=(l+r)/2;
            int Py=(m+n+1)/2-Px;

            int x1=(Px==0) ? INT_MIN : nums1[Px-1];
            int x2=(Py==0) ? INT_MIN : nums2[Py-1];
            int x3=(Px==n) ? INT_MAX : nums1[Px];
            int x4=(Py==m) ? INT_MAX : nums2[Py];

            if(x1<=x4 and x2<=x3)
            {
                if((n+m)%2==1) return max(x1,x2);
                else return (max(x1,x2) + min(x3,x4))/2.0;
            }
            if(x1>x4) r=Px-1;
            else l=Px+1;
        }
        return -1;
    }
};