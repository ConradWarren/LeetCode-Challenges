#include <string>
#include <vector>

class Solution {
public:
int Find_Min_Partition(std::string& s, int idx, long k, long current_val, std::vector<int>& cache) {

	if (current_val > k) return 1000000;
	
	if (idx >= s.length()) return 0;
	
	int start_new = (cache[idx] != -1) ? cache[idx] : 1 + Find_Min_Partition(s, idx + 1, k, int(s[idx]) - int('0'), cache);
	cache[idx] = start_new;

	current_val *= 10;
	current_val += int(s[idx]) - int('0');

	int adds = Find_Min_Partition(s, idx + 1, k, current_val, cache);

	return (adds < start_new) ? adds : start_new;
}

int minimumPartition(std::string s, int k) {

	std::vector<int> cache(s.length(), -1);

	int result = Find_Min_Partition(s, 0, k, 0, cache);

	return (result > s.length()) ? -1 : result + 1;
}
};
