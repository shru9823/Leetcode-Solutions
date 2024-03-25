class SmallestInfiniteSet {
public:
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur;
    SmallestInfiniteSet() {
        cur = 1;
    }
    
    int popSmallest() {
        int ans;
        if(!pq.empty()){
            ans = pq.top();
            st.erase(ans);
            pq.pop();
        }else{
            ans = cur;
            cur++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(cur <= num || st.find(num) != st.end()){
            return;
        }
        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */