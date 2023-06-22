#include <vector>

class Solution {
public:
int Solve_Max(std::vector<int>& prices, int idx, bool bought_flag, int trade_count, std::vector<std::vector<int>>& bought_cache, std::vector<std::vector<int>>& not_bought_cache) {

	if (trade_count >= 2 || idx >= prices.size()) return 0;
	
	if (bought_flag && bought_cache[trade_count][idx] != -1) return bought_cache[trade_count][idx];
	
	if (!bought_flag && not_bought_cache[trade_count][idx] != -1) return not_bought_cache[trade_count][idx];
	
	int skip = Solve_Max(prices, idx + 1, bought_flag, trade_count, bought_cache, not_bought_cache);

	int transaction = (bought_flag) ? prices[idx] + Solve_Max(prices, idx + 1, false, trade_count + 1, bought_cache, not_bought_cache) : -prices[idx] + Solve_Max(prices, idx + 1, true, trade_count, bought_cache, not_bought_cache);

	if (bought_flag) bought_cache[trade_count][idx] = (skip > transaction) ? skip : transaction;
	
	else not_bought_cache[trade_count][idx] = (skip > transaction) ? skip : transaction;
	
	return (skip > transaction) ? skip : transaction;
}


int maxProfit(std::vector<int>& prices) {
	
	std::vector<std::vector<int>> bought_cache(2, std::vector<int>(prices.size(), -1));
	std::vector<std::vector<int>> not_bought_cache(2, std::vector<int>(prices.size(), -1));

	return Solve_Max(prices, 0, false, 0, bought_cache, not_bought_cache);
}
};
