class RangeFreqQuery {
public:
    map<int,vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        int n= arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(mp.find(value) == mp.end()){
            return 0;
        }
        auto& pos = mp[value];
        int l = lower_bound(pos.begin(),pos.end() , left) - pos.begin();
        int r = upper_bound(pos.begin(),pos.end(), right) - pos.begin();
        return r-l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */