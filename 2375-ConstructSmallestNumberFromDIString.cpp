class Solution {
public:
void Build_Pattern(std::string& pattern, std::vector<int>& sequence, std::vector<bool> used_nums, int idx, std::vector<int>& output) {

	if (idx == -1) {

		for (int i = 1; i <= 9; i++) {
			sequence.push_back(i);
			used_nums[i] = true;
			Build_Pattern(pattern, sequence, used_nums, 0, output);
			if (!output.empty()) break;
			sequence.pop_back();
			used_nums[i] = false;
		}
		return;
	}

	if (idx >= pattern.length()) {
		output = sequence;
		return;
	}

	if (pattern[idx] == 'I') {

		for (int i = sequence.back() + 1; i <= 9; i++) {
			
			if (used_nums[i]) continue;
			
			sequence.push_back(i);
			used_nums[i] = true;
			Build_Pattern(pattern, sequence, used_nums, idx+1, output);
			if (!output.empty()) break;
			sequence.pop_back();
			used_nums[i] = false;
		}
		return;
	}

	if (pattern[idx] == 'D') {

		for (int i = 1; i < sequence.back(); i++) {
			if (used_nums[i]) continue;
			sequence.push_back(i);
			used_nums[i] = true;
			Build_Pattern(pattern, sequence, used_nums, idx + 1, output);
			if (!output.empty()) break;
			sequence.pop_back();
			used_nums[i] = false;
		}
		return;
	}
}

std::string smallestNumber(std::string pattern) {

	std::vector<int> result;
	std::vector<int> sequence;
	std::vector<bool> used_nums(10, false);
	std::string output;

	Build_Pattern(pattern, sequence, used_nums, -1, result);

	for (int i = 0; i < result.size(); i++) {
		output += std::to_string(result[i]);
	}

	return output;
}
};
