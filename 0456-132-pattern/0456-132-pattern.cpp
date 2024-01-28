class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> vec;
        int n=nums.size();
        if(n < 3){return false;}
        vec.push_back(nums[0]);
        for(int i=1;i<n;i++){
            vec.push_back(min(vec[vec.size()-1], nums[i]));
        }
        stack<int> st;
        for(int i=n-1;i>0;i--){
            while(nums[i] > vec[i] && !st.empty() && st.top() <= vec[i]){
                st.pop();
            }
            if(nums[i] > vec[i] && !st.empty() && st.top() > vec[i] && nums[i] > st.top()){
                return true;
            }
            if(nums[i] > vec[i]){
                st.push(nums[i]);
            }
        }
        return false;
    }
};