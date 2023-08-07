class Solution {
public:
int minimumSeconds(std::vector<int>& nums) {

	std::unordered_map<int, std::vector<int>> num_indexs;
	int num_score = 0;
	int gap = 0;
	int min_score = INT_MAX;

	for (int i = 0; i < nums.size(); i++) {
		num_indexs[nums[i]].push_back(i);
	}

	for (auto& num : num_indexs) {

		gap = num.second.front() + (nums.size() - 1 - num.second.back());
		num_score = (gap + 1) / 2;

		for (int i = 0; i < num.second.size() - 1; i++) {

			gap = num.second[i + 1] - num.second[i];
			num_score = (num_score > gap / 2) ? num_score : gap / 2;
		}

		min_score = (min_score < num_score) ? min_score : num_score;
	}

	return min_score;
}
};
