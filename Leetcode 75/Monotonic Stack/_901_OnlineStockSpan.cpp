// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day. The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.





#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
public:
    StockSpanner() { }
    
    stack<pair<int, int>> s;
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    
    for (int price : prices) {
        int span = obj->next(price);
        cout << "Price: " << price << ", Span: " << span << endl;
    }
    
    delete obj;
    return 0;
}