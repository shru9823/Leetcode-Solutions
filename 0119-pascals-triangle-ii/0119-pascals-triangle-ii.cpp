class Solution {
public:
    vector<int> getRow(int a) {
        if(a == 0){return {1};}
        else if(a == 1){return {1,1};}
        vector<int> prev,cur;
        prev = {1,1};
        for(int i=2;i<=a;i++){
            cur.assign(i+1, 1);
            for(int j=1;j<i;j++){
                cur[j] = prev[j-1]+prev[j];
            }
            prev = move(cur);
        }
        return prev;
    }
};