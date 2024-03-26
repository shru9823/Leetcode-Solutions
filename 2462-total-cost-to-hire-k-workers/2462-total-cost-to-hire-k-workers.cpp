class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, std::vector<int>, std::greater<int>> pq1, pq2;
        int n=costs.size(),l=0,r=n-1, temp=0;
        long long ans=0;
        while(l<candidates){
            pq1.push(costs[l++]);
        }
        while(r>=l && temp<candidates){
            temp++;
            pq2.push(costs[r--]);
        }
        for(int i=0;i<k;i++){
            if(!pq1.empty() && !pq2.empty()){
                cout<<pq1.top()<<" "<<pq2.top()<<endl;
                if(pq1.top() <= pq2.top()){
                    ans += pq1.top();
                    pq1.pop();
                    if(l<=r){
                        pq1.push(costs[l++]);
                    }
                }else{
                    ans += pq2.top();
                    pq2.pop();
                    if(l<=r){
                        pq2.push(costs[r--]);
                    }
                }
                
            }else if(!pq1.empty()){
                ans += pq1.top();
                pq1.pop();
                if(l<=r){
                    pq1.push(costs[l++]);
                }
            }else{
                ans += pq2.top();
                pq2.pop();
                if(l<=r){
                    pq2.push(costs[r--]);
                }
            }
        }
        return ans;
    }
};