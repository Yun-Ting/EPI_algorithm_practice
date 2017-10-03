// 5.6_buy-and-sell-a-stock-once

// 9/20
// has NOTHING to do with the max price, 
// Instead, the max profit that can be made
// by selling on each specific day is the 
// difference of the current price and the 
// minimum seen so far
#include <limits>
#include <iostream>
#include <vector>
using namespace std;

double BuyAndSellStockOnce(const vector<double>& prices) {
	double min_price_so_far = numeric_limits<double>::max();
	double max_profit = 0;
	for (const double& price: prices) {
		double max_profit_sell_today = price - min_price_so_far;
		max_profit = max(max_profit_sell_today, max_profit);
		min_price_so_far = min(price, min_price_so_far);
	}
	return max_profit;
}

int main() {
	vector<double> v1 = {310,315,275,295,260,270,290,230,255,250};
	cout << BuyAndSellStockOnce(v1) << endl;
}