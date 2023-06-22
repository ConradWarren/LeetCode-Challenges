#include <vector>

class Solution {
public:
int Solve(std::vector<int>& prices, int fee,int idx, bool bought_flag, std::vector<int>& bought_cache, std::vector<int>& not_bought_cache) {

	if (idx >= prices.size()) return 0;
	
	if (bought_flag && bought_cache[idx] != -1) return bought_cache[idx];
	
	if (!bought_flag && not_bought_cache[idx] != -1) return not_bought_cache[idx];
	
	int skip = Solve(prices, fee, idx+1, bought_flag, bought_cache, not_bought_cache);

	int transaction = (!bought_flag) ? -prices[idx] + Solve(prices, fee, idx + 1, true, bought_cache, not_bought_cache) : prices[idx] - fee + Solve(prices, fee, idx + 1, false, bought_cache, not_bought_cache);

	if (bought_flag) bought_cache[idx] = (skip > transaction) ? skip : transaction;
	
	else not_bought_cache[idx] = (skip > transaction) ? skip : transaction;
	
	return (skip > transaction) ? skip : transaction;
}

int maxProfit(std::vector<int>& prices, int fee) {

	std::vector<int> bought_cache(prices.size(), -1);
	std::vector<int> not_bought_cache(prices.size(), -1);

	return Solve(prices, fee, 0, false, bought_cache, not_bought_cache);
}
};
