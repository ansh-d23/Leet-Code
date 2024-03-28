class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=1;
        int ans=0,diff=0;
        while(i<height.size()){
        if(j<height.size()){
            if(height[j]>=height[i]){
                ans+=diff;
                i=j; j=i+1;
                diff=0;
            }else{
                diff += (height[i]-height[j]);
                j++;
            }
        }else{
            i++;
            if(i<height.size()){
                j=i+1;
                diff=0;
            }
        }
    }
        return ans;
    }
};