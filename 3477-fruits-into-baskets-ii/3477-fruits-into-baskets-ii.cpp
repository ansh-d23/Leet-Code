class Solution {
    void segTree(int idx, int low, int high, vector<int>& branch){
        if(low==high){
            seg[idx]=branch[low];
            return;
        }
        int mid = (low+high)/2;
        segTree(2*idx+1, low, mid, branch);
        segTree(2*idx+2, mid+1, high, branch);
        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    }

    int query(int idx, int low, int high, int st){

        if(seg[idx] < st) return -1;
        if(low==high){
            seg[idx]=-1;
            return low;
        }


        int mid = (low+high)/2;
        int pos;
        if(seg[2*idx+1] >= st){
           pos = query(2*idx+1,low,mid,st);
        }else{
           pos = query(2*idx+2,mid+1,high,st);
        }

        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);

        return pos;
    }



public:
    vector<int> seg;
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = fruits.size();
        seg.assign(4*n,0);

        segTree(0,0,n-1,baskets);

        int ans=0;
        for(int it : fruits){
            if(query(0,0,n-1,it) == -1){
                ans++;
            }
        }

        return ans;  
    }
};