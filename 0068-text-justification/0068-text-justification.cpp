class Solution {
public:
    vector<string> getWords(int cur, vector<string>& words, int maxWidth){
        vector<string> currline;
        int curlen=0;
        for(;cur<words.size() && curlen+words[cur].length() <= maxWidth;){
            currline.push_back(words[cur]);
            curlen += words[cur].length() + 1;
            cur++;
        }
        return currline;
    }
    string createLine(vector<string>& currline, int maxWidth, vector<string>
& words, int next){
        if(next==words.size() || currline.size()==1){
            string ret="";
            for(int i=0;i<currline.size();i++){
                ret += currline[i];
                if(i+1 < currline.size()){ret += " ";}
            }
            while(ret.size() < maxWidth){ret += " ";}
            return ret;
        }
        int extraspace=0,baselen=-1;
        for(string a:currline){
            baselen += a.length()+1;
        }
        extraspace = maxWidth-baselen;
        int n=currline.size(),one_space = extraspace/(n-1),l_space = extraspace%(n-1);
        string ret = "";
        for(string a :currline){
            ret += a;
            if(ret.length() == maxWidth){continue;}
            string repeated(one_space+(l_space>0?1:0),' ');
            ret += " " + repeated;
            l_space--;
        }
        return ret;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0,n=words.size();
        vector<string> ans;
        while(i<n){
            vector<string> currline = getWords(i,words,maxWidth);
            i += currline.size();
            ans.push_back(createLine(currline, maxWidth, words, i));
        }
        return ans;
    }
};