class Solution {
public:
int Solve_Distinct_Sequences(int n,int last_num, int last_num_count, std::vector<int>& rollMax, std::vector<std::vector<std::vector<int>>>& cache) {

	if (n == 0) {
		return 1;
	}

	if (cache[n][last_num][rollMax[last_num] - last_num_count] != -1) {
		return cache[n][last_num][rollMax[last_num] - last_num_count];
	}

	int total_sequences = 0;
	for (int i = 0; i < 6; i++) {
		if (i == last_num) {
			if (last_num_count < rollMax[i]) {
				total_sequences += Solve_Distinct_Sequences(n - 1, i, last_num_count + 1, rollMax, cache);
				total_sequences %= 1000000007;
			}
		}
		else {
			total_sequences += Solve_Distinct_Sequences(n - 1, i, 1, rollMax, cache);
			total_sequences %= 1000000007;
		}
	}
	cache[n][last_num][rollMax[last_num] - last_num_count] = total_sequences;
	
	return total_sequences;
}

int dieSimulator(int n, std::vector<int>& rollMax) {

	std::vector<std::vector<std::vector<int>>> cache(n+1,std::vector<std::vector<int>>(6, std::vector<int>(16, -1)) );

	return Solve_Distinct_Sequences(n,0, 0, rollMax, cache);
}
};
