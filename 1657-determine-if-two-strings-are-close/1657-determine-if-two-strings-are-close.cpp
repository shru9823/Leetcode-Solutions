class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> vec1(26, 0), vec2(26, 0);
        int l1=word1.length(), l2=word2.length();
        if(l1!=l2){return false;}
        int a=0;
        for(int i=0;i<l1;i++){
            a = a|(1<<(word1[i]-'a'));
            vec1[word1[i]-'a']++;
        }
        int b=0;
        for(int i=0;i<l2;i++){
            b = b|(1<<(word2[i]-'a'));
            vec2[word2[i]-'a']++;
        }
        if(a!=b){return false;}
        sort(vec1.begin(), vec1.end(), [](int a, int b){
            return a > b;
        });
        sort(vec2.begin(), vec2.end(), [](int a, int b){
            return a > b;
        });
        for (int i = 0; i < 26; i++) {
            if (vec1[i] != vec2[i]) return false;
        }
        return true;
    }
};