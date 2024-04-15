class Solution {
public:
    int partition(int l, int r, vector<int>& nums, map<int,int>& mp){
        int a=l, b=l, cnt = mp[nums[r]];
        // cout<<"cnt "<<cnt<<endl;
        while(b < r){
            if(mp[nums[b]] > cnt){
                swap(nums[a], nums[b]);
                a++;
            }b++;
        }
        return a;
    }
    
    void quick_select (vector<int>& nums, map<int,int>& mp, int k){
         int l=0, r=nums.size()-1;
        while(l<=r){
            int pivot = l+ (rand()%(r-l+1));
            // cout<<pivot<<endl;
            // for(auto a:nums){
            //     cout<<a<<" ";
            // }cout<<endl;
            swap(nums[pivot], nums[r]);
            int index = partition(l,r,nums,mp);
            swap(nums[index], nums[r]);
            if(index == k){return;}
            else if(index<k){
                l=index+1;
            }else{r=index-1;}
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> vec;
        for(auto p:mp){
            vec.push_back(p.first);
        }
        quick_select(vec, mp, k);
        vector<int> ans(k);
        copy(vec.begin(), vec.begin()+k, ans.begin());
        return ans;
    }
};