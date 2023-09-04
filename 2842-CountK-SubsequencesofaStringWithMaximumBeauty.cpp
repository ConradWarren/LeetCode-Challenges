class Solution {
public:
int Count_Subsequences(std::vector<int>& nums,int idx, int k, int max_score, std::vector<std::vector<std::unordered_map<int, int>>>& cache) {

	if (max_score == 0) {
		return 1;
	}

	if (k == 0 || idx >= nums.size()) {
		return 0;
	}

	if (cache[idx][k].find(max_score) != cache[idx][k].end()) {
		return cache[idx][k][max_score];
	}

	int skip = Count_Subsequences(nums, idx + 1, k, max_score, cache);
	
	long long take = (long long)nums[idx] * Count_Subsequences(nums, idx + 1, k - 1, max_score - nums[idx], cache);

	take %= int(1e9) + 7;

	cache[idx][k][max_score] = (skip + take)%(int(1e9) + 7);

	return (skip + take) % (int(1e9) + 7);
}

int countKSubsequencesWithMaxBeauty(std::string s, int k) {

	std::vector<int> character_occurances(26, 0);
	std::vector<std::vector<std::unordered_map<int, int>>> cache;
	int max_score = 0;
	int mod = int(1e9) + 7;


	for (int i = 0; i < s.length(); i++) {
		character_occurances[s[i] - 'a']++;
	}

	std::sort(character_occurances.rbegin(), character_occurances.rend());

	for (int i = 0; i < character_occurances.size() && i < k; i++) {
		max_score += character_occurances[i];
		if (character_occurances[i] == 0) {
			return 0;
		}
	}

	cache.resize(26, std::vector<std::unordered_map<int, int>>(k + 1));

	return Count_Subsequences(character_occurances, 0, k, max_score, cache);
}
};
