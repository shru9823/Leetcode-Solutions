class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n=sentence.size(),ans=0;
        vector<int> next_line_word(n),time(n,0); 
        for(int i=0;i<n;i++){
            int cur=i,curlen=0,t=0;
            for(;curlen+sentence[cur].length() <= cols;){
                curlen += sentence[cur].length()+1;
                cur++;
                if(cur == n){t++;cur=0;}
            }
            next_line_word[i]=cur;
            time[i] = t;
        }
        int start=0;
        for(int i=0;i<rows;i++){
            ans += time[start];
            start = next_line_word[start];
        }
        return ans;
    }
};