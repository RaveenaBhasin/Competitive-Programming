class StockSpanner {
    stack<pair<int, int>>st;  //price, span
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().second <= price) {
            span += st.top().first;
            st.pop();
        }
        st.push({span, price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */