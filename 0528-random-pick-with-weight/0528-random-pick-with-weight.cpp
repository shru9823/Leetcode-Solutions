class Solution {
public:
    vector<int> vec;
    Solution(vector<int>& w) {
        vec.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            vec.push_back(vec[vec.size()-1]+w[i]);
        }
    }
    
    int pickIndex() {
        float r = (float)rand()/INT_MAX;
        float num = r*vec.back();
        for(int i=0;i<vec.size();i++){
            if(num < vec[i]){return i;}
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */