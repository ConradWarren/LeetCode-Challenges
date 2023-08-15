#include <vector>

class Solution {
public:
int Prime_Score(int num) {

	if (num == 1) {
		return 0;
	}
	int score = 0;
	int idx = 3;

	if (num % 2 == 0) {
		score++;
		while (num % 2 == 0) {
			num /= 2;
		}
	}

	while (idx * idx <= num) {
		if (num % idx == 0) {
			score++;
			while (num % idx == 0) {
				num /= idx;
			}
		}
		idx += 2;
	}

	if (num != 1) {
		score++;
	}

	return score;
}

long long Exponent(int exp, long long num) {
	int mod  = int(1e9) + 7;
	long long result = 1;

	while (exp) {
		if (exp % 2) {
			result *= num;
			result %= mod;
		}
		num *= num;
		num %= mod;
		exp /= 2;
	}
	return result;
}

int maximumScore(std::vector<int>& nums, int k) {

	std::vector<int> prime_scores(nums.size());
	std::stack<int> prime_idx_stack;
	std::vector<std::pair<int, int>> sub_array_scores(nums.size());
	long long result = 1;
	int exp = 0;
	int mod = int(1e9) + 7;

	for (int i = 0; i < nums.size(); i++) {
		prime_scores[i] = Prime_Score(nums[i]);
		sub_array_scores[i].first = nums[i];
		sub_array_scores[i].second = 0;
	}

	for (int i = 0; i < nums.size(); i++) {

		while (!prime_idx_stack.empty() && prime_scores[prime_idx_stack.top()] < prime_scores[i]) {
			prime_idx_stack.pop();
		}

		if (prime_idx_stack.empty()) {
			sub_array_scores[i].second += i + 1;
		}
		else {
			sub_array_scores[i].second += i - prime_idx_stack.top();
		}
		
		prime_idx_stack.push(i);
	}



	while (!prime_idx_stack.empty()){
		prime_idx_stack.pop();
	}

	for (int i = nums.size()-1; i >= 0; i--) {

		while (!prime_idx_stack.empty() && prime_scores[prime_idx_stack.top()] <= prime_scores[i]) {
			prime_idx_stack.pop();
		}

		if (prime_idx_stack.empty()) {
			sub_array_scores[i].second *= nums.size() - i;
		}
		else {
			sub_array_scores[i].second *= prime_idx_stack.top() - i;
		}

		prime_idx_stack.push(i);
	}

	std::sort(sub_array_scores.rbegin(), sub_array_scores.rend());

	for (int i = 0; i < sub_array_scores.size(); i++) {

		exp = (sub_array_scores[i].second < k) ? sub_array_scores[i].second : k;
		k -= sub_array_scores[i].second;

		result *= Exponent(exp, sub_array_scores[i].first);
		result %= mod;
		if (k <= 0) break;
	}

	return result;
}
};
