class StockSpanner {
public:
    stack<pair<int,int>>sp;
    int ct;
    StockSpanner() {
        ct = 0;
    }
    
    int next(int price) {
        while(!sp.empty()&&sp.top().first<=price){
            sp.pop();
        }
        int ans = !sp.empty() ? ct-sp.top().second : ct+1;
        sp.push({price,ct});
        ct++;
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */