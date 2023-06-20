#include <vector>

class Solution {
public:
int sumDistance(std::vector<int>& nums, std::string s, int d) {

	std::vector<long long> distance(nums.size());
	long long sum = 0;
	long long mod = int(1e9) + 7;
	long long result = 0;

	for (int i = 0; i < nums.size(); i++) {
		nums[i] += (s[i] == 'R') ? d : -d;
	}

	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		distance[i] = (long long)(nums[i]) - (long long)(nums[0]);
		sum += distance[i];
	}

	for (int i = 0; i < distance.size(); i++) {

		sum -= distance[i];
		
		result += sum;

		result -= ((long long)(distance[i]) * (long long)(nums.size() - 1 - i))%mod;

		result %= mod;
	}

	return result;
}
};
