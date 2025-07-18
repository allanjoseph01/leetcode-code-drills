class FreqStack {
public:
    unordered_map<long long,int> freq;
    unordered_map<int,stack<long long>> freqst;
    FreqStack() {

    }
    int maxfreq=0;
    void push(int val) {
        freq[val]++;
        freqst[freq[val]].push(val);
        maxfreq=max(maxfreq,freq[val]);
    }
    
    int pop() {
        int ans=freqst[maxfreq].top();
        freqst[maxfreq].pop();
        if(freqst[maxfreq].size()==0){
            maxfreq--;
        }
        freq[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */