class Solution {
public:
int Solve_Max(std::vector<int>& prices, int idx, int trade_count, bool bought_flag, std::vector<std::vector<int>>& bought_cache, std::vector<std::vector<int>>& not_bouhgt_cache) {

	if (trade_count >= bought_cache.size() || idx >= prices.size()) return 0;
	
	if (bought_flag && bought_cache[trade_count][idx] != -1) return bought_cache[trade_count][idx];
	
	if (!bought_flag && not_bouhgt_cache[trade_count][idx] != -1) return not_bouhgt_cache[trade_count][idx];
	
	int skip = Solve_Max(prices, idx + 1, trade_count, bought_flag, bought_cache, not_bouhgt_cache);

	int transaction = (bought_flag) ? prices[idx] + Solve_Max(prices, idx + 1, trade_count + 1, false, bought_cache, not_bouhgt_cache) : -prices[idx] + Solve_Max(prices, idx + 1, trade_count, true, bought_cache, not_bouhgt_cache);

	if (bought_flag) bought_cache[trade_count][idx] = (skip > transaction) ? skip : transaction;
	
	else not_bouhgt_cache[trade_count][idx] = (skip > transaction) ? skip : transaction;
	
	return (skip > transaction) ? skip : transaction;
}


int maxProfit(int k, std::vector<int>& prices) {

	std::vector<std::vector<int>> bought_cache(k, std::vector<int>(prices.size(), -1));
	std::vector<std::vector<int>> not_bought_cache(k, std::vector<int>(prices.size(), -1));
	
	return Solve_Max(prices, 0, 0, false, bought_cache, not_bought_cache);
}
};
