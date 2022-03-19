class FreqStack {
public:
    unordered_map<int, int>freq;
    unordered_map<int, stack<int>>grp;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        grp[freq[val]].push(val);
    }
    
    int pop() {
        int topMaxFreq = grp[maxFreq].top();
        grp[maxFreq].pop();
        freq[topMaxFreq]--;
        if(grp[maxFreq].size()==0)
            maxFreq--;
        return topMaxFreq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

