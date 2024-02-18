class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        int n = nums.size();
        for(int i=0;i<n;i++){
            int size = ans.size();
            for(int j=0;j<size;j++){
                vector<int> vec = ans[j];
                vec.push_back(nums[i]);
                ans.push_back(vec);
            }
        }
        return ans;
    }
};