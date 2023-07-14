#include <vector>

class Solution {
public:
int longestSubsequence(std::vector<int>& arr, int difference) {

	std::unordered_map<int, int> last_idx_map;

	std::vector<int> dp(arr.size(), 1);

	int best = 0;


	for (int i = 0; i < arr.size(); i++) {
		
		if (last_idx_map.find(arr[i]) != last_idx_map.end() && last_idx_map.find(arr[i] - difference) != last_idx_map.end()) {

			dp[i] = (dp[last_idx_map[arr[i]]] > dp[last_idx_map[arr[i] - difference]] + 1) ? dp[last_idx_map[arr[i]]] : dp[last_idx_map[arr[i] - difference]] + 1;
		
		}
		else if (last_idx_map.find(arr[i]) != last_idx_map.end()) {
			dp[i] = dp[last_idx_map[arr[i]]];
		}
		else if (last_idx_map.find(arr[i]-difference) != last_idx_map.end()) {
			dp[i] = dp[last_idx_map[arr[i] - difference]] + 1;
		}

		best = (best > dp[i]) ? best : dp[i];
		last_idx_map[arr[i]] = i;
	}

	return best;
}
};
