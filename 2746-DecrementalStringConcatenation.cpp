#include <vector>
#include <string>

class Solution {
public:
int Solve_Max_Offset(std::vector<std::string>& words,int idx, int current_front, int current_back, std::vector<std::vector<int>>& cache){

	if (idx >= words.size()) {
		return 0;
	}

	if (cache[idx][(current_front << 5) | current_back] != -1) {
		return cache[idx][(current_front << 5) | current_back];
	}

	int merge_back = Solve_Max_Offset(words, idx + 1, current_front, (words[idx].back() - 'a'), cache);

	merge_back += (current_back == (words[idx].front() - 'a')) ? 1 : 0;

	int merge_front = Solve_Max_Offset(words, idx + 1, (words[idx].front() - 'a'), current_back, cache);

	merge_front += (current_front == (words[idx].back() - 'a')) ? 1 : 0;

	cache[idx][(current_front << 5) | current_back] = (merge_back > merge_front) ? merge_back : merge_front;

	return (merge_back > merge_front) ? merge_back : merge_front;
}

int minimizeConcatenatedLength(std::vector<std::string>& words) {

	int current_front = words[0].front() - 'a';
	int current_back = words[0].back() - 'a';
	std::vector<std::vector<int>> cache(words.size(), std::vector<int>(((25 << 5) | 25) + 1, -1));
	int total_sum = 0;

	int offset = Solve_Max_Offset(words, 1, current_front, current_back, cache);

	for (int i = 0; i < words.size(); i++) {
		total_sum += words[i].length();
	}

	return total_sum - offset;
}
};
