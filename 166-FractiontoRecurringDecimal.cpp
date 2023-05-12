class Solution {
public:
std::string fractionToDecimal(int numerator, int denominator) {

	std::unordered_map<long, int> remainder_map;

	std::vector<int> valid_nums;
	std::string result;
	long base = ((long)(numerator) / (long)(denominator));
	long remainder = ((long)(numerator) % (long)(denominator));
	int repeating_idx = -1;

	if (!remainder) {
		return std::to_string(base);
	}

	if (base == 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))) result += '-';

	while (remainder) {
		remainder *= 10;
		valid_nums.push_back(abs(remainder / denominator));
		remainder %= denominator;

		if (remainder_map.find(remainder) == remainder_map.end()) {
			remainder_map[remainder] = valid_nums.size() - 1;
		}
		else {
			repeating_idx = remainder_map[remainder];
			break;
		}

	}

	result += std::to_string(base);
	result += '.';

	for (int i = 0; i <= repeating_idx; i++) {
		result += std::to_string(valid_nums[i]);
	}

	if (repeating_idx != -1) result += '(';
	
	for (int i = repeating_idx + 1; i < valid_nums.size(); i++) {
		result += std::to_string(valid_nums[i]);
	}

	if (repeating_idx != -1) result += ')';
	
	return result;
}
};
