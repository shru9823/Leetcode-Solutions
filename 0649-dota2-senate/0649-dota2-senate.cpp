class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int r=0,d=0, rcnt=0,dcnt=0;
        int ans = 0;
        for(int i=0;i<senate.length();i++){
            q.push(senate[i]);
            if(senate[i] == 'R'){rcnt++;}
            else{dcnt++;}
        }
        while(!q.empty()){
            if(rcnt==0 || dcnt==0){
                break;
            }
            cout<<q.size()<<endl;
            char a = q.front();
            q.pop();
            if(a=='R'){
                rcnt--;
                if(r > 0){
                    r--;
                }else{
                    d++;
                    q.push(a);
                    rcnt++;
                }
            }else{
                dcnt--;
                if(d > 0){
                    d--;
                }else{
                    r++;
                    q.push(a);
                    dcnt++;
                }
            }
        }
        
        return dcnt==0?"Radiant":"Dire";
    }
};