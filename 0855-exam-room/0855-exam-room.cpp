class ExamRoom {
    int n=0;
    set<int> s;
public:
    ExamRoom(int nn) {
        n=nn;
    }
    
    int seat() {
        if(s.size() == 0){
            s.insert(0);
            return 0;
        }
        auto it1 = s.begin(),it2 = s.begin();
        it2++;
        int maxi=*s.begin(),index=0;
        for(;it2!=s.end();it1++,it2++){
            if(maxi < (*it2-*it1)/2){
                index = *it1+(*it2-*it1)/2;
                maxi = (*it2-*it1)/2;
            }
        }
        if(n-1 - *it1 > maxi){
            index = n-1;
        }
        s.insert(index);
        return index;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */