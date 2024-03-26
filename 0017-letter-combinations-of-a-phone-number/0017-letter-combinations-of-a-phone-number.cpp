class Solution {
public:
    map<char, vector<char>> mp;
    
    vector<string> letterCombinations(string digits) {
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        queue<string> q;
        q.push("");
        for(int i=0;i<digits.length();i++){
            char d = digits[i];
            int size = q.size();
            while(size--){
                string a = q.front();q.pop();
                for(auto c: mp[d]){
                    q.push(a+c);
                }
            }
        }
        while(!q.empty()){
            if(q.front() == ""){q.pop();}
            else {ans.push_back(q.front());q.pop();}
        }
        return ans;
    }
};