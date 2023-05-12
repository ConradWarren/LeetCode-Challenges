#include <vector>

class Solution {
public:
long long Find_Max_Points(std::vector<std::vector<int>>& questions, int idx, std::vector<long long>& cache) {

	if (idx >= questions.size()) {
		return 0;
	}

	if (cache[idx] != -1) {
		return cache[idx];
	}

	long long skips = Find_Max_Points(questions, idx + 1, cache);

	long long takes = questions[idx][0] + Find_Max_Points(questions, idx + 1 + questions[idx][1], cache);

	cache[idx] = (skips > takes) ? skips : takes;

	return cache[idx];
}

long long mostPoints(std::vector<std::vector<int>>& questions) {

	std::vector<long long> cache(questions.size(), -1);

	return Find_Max_Points(questions, 0, cache);
}
};
