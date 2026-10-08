class StockSpanner {
public:
    stack<pair<int,int>>s;
    int count=-1;
    StockSpanner() { }
    
    int next(int price) {
        count++;
        while(s.size()>0 && s.top().first<=price){
            s.pop();
        }
        if(s.size()==0){
            s.push({price,count});
            return count+1;
        }
        else{
            int ans= count - s.top().second;
            s.push({price , count});
            return ans ;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */