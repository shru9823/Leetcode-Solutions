class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(), l=0,r=n-1;
        int ans=0, h;
        while(l<r){
            if(height[l] < height[r]){h=height[l++];}
            else{h=height[r--];}
            ans= max(ans, (r-l+1) * h);
        }
        return ans;
    }
};