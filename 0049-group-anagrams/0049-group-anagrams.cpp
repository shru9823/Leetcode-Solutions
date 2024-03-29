class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<int> vec(26, 0);
        for(string a: strs){
            vec.assign(26,0);
            for(char c:a){
                vec[c-'a']++;
            }
            string s="";
            for(int i=0;i<26;i++){
                // if(vec[i] != 0){
                    s += to_string(i) + " " + to_string(vec[i]);
                // }
            }
            mp[s].push_back(a);
        }
        vector<vector<string>> ans;
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};