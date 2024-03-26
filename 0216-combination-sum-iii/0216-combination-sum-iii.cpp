class Solution {
public:
    void bk(vector<vector<int>>& ans, vector<int>& vec, int num, int k, int remain){
        if(remain == 0 && vec.size() == k){
            ans.push_back(vec);return;
        }else if(remain < 0 || vec.size()==k){return;}
        for(int i=num;i<=9;i++){
            vec.push_back(i);
            bk(ans, vec, i+1, k, remain-i);
            vec.erase(vec.end()-1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        bk(ans, vec, 1, k, n);
        return ans;
    }
};