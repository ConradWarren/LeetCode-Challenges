#include <vector>
#include <string>

class Solution {
public:
int Solve_Number_Of_Arrays(std::string& s, long k,int k_length, std::string current_array, int idx, std::vector<int>& cache) {

	if (idx == s.length()) {
		if (current_array.length() < k_length || stol(current_array) <= k) return 1;
		else return 0;
	}

	if (current_array.length() > k_length || current_array.length() == k_length && stol(current_array) > k) return 0;
	
	int starts_new = 0;
	if (cache[idx] == -1) {
		starts_new = (s[idx] == '0') ? 0 : Solve_Number_Of_Arrays(s, k,k_length, s.substr(idx, 1), idx + 1, cache);
		cache[idx] = starts_new;
	}
	else starts_new = cache[idx];
	
	current_array += s[idx];
	int adds_to_current = Solve_Number_Of_Arrays(s, k,k_length, current_array, idx + 1, cache);
	 
	return (adds_to_current + starts_new)%1000000007;
}


int numberOfArrays(std::string s, int k) {

	std::vector<int> cache(s.length(), -1);

	int k_length = std::to_string(k).length();
	
	return Solve_Number_Of_Arrays(s, k,k_length, s.substr(0, 1), 1, cache);
}
};
