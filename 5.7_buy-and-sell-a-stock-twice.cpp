// 5.7_buy-and-sell-a-stock-twice

// 9/20
// 		day
/* F -> 0 1 2 3 4 5 ... n <- B
*  min	- ---------------    cares about max
*       --- -------------    because you have to buy
*       ----- -----------    before you can sell
*       ------- ---------    
*       --------- -------    you can only perform one
*       .................	 transation in a day
*       -------------- --
*/

#include <limits>
#include <iostream>
#include <vector>
using namespace std;

// Time: O(n)
// Space: O(n)
double BuyAndSellStockTwice(const vector<double> &prices) {
	vector<double> first_buy_sell_profits(prices.size(), 0);
	double min_price_so_far = numeric_limits<double>::max();
	double max_total_profit = 0;

	// Forward phase: For each day, we record maxiumum profit
	// if we sell on that day
	for (int i = 0; i < prices.size(); ++i) {
		min_price_so_far = min(prices[i], min_price_so_far);
		max_total_profit = max(max_total_profit, prices[i] - min_price_so_far);
		first_buy_sell_profits[i] = max_total_profit;
	}
	// Backward phase. For each day, find the maximum profit
	// if wee make the second buy on that 
	double max_price_so_far = numeric_limits<double>::min();
	for (int i = prices.size() - 1; i > 0; --i) {
		max_price_so_far = max(prices[i], max_price_so_far);
		max_total_profit = max(max_total_profit, max_price_so_far - prices[i] + first_buy_sell_profits[i-1]);
	}
	return max_total_profit;
}

int main() {
	vector<double> v = {12, 11, 13, 9, 12, 8, 14, 13, 15};
	cout << BuyAndSellStockTwice(v) << endl;
}
