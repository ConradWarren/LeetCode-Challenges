class Solution {
public:

int GCF(int a, int b) {
	if (b == 0) return a;
	else return GCF(b, a % b);
}

int Solve_Distinct_Sequences(int n, int idx, int last_num, int second_last_num, std::vector<std::vector<bool>>& possible_adjacent_numbers, 
							std::vector<std::vector<std::vector<int>>>& cache) {

	if (idx == n) return 1;
	
	if (cache[second_last_num][last_num][idx] != -1) return cache[second_last_num][last_num][idx];
	
	int total_sequences = 0;
	for (int i = 1; i <= 6; i++) {

		if (second_last_num == i) continue;
		
		if (possible_adjacent_numbers[last_num][i]) {
			total_sequences += Solve_Distinct_Sequences(n, idx + 1, i, last_num, possible_adjacent_numbers, cache);
			total_sequences %= 1000000007;
		}
	}

	cache[second_last_num][last_num][idx] = total_sequences;

	return total_sequences;
}


int distinctSequences(int n) {

	std::vector<std::vector<bool>> possible_adjacent_numbers(7, std::vector<bool>(7, false));
	std::vector<std::vector<std::vector<int>>> cache(7, std::vector<std::vector<int>>(7, std::vector<int>(n, -1)));

	for (int i = 1; i <= 6; i++) {
		for (int j = i+1; j <= 6; j++) {
			if (GCF(i, j) == 1) {
				possible_adjacent_numbers[i][j] = true;
				possible_adjacent_numbers[j][i] = true;
			}
		}
	}

	for (int i = 0; i <= 6; i++) {
		possible_adjacent_numbers[0][i] = true;
		possible_adjacent_numbers[i][0] = true;
	}

	return Solve_Distinct_Sequences(n, 0, 0, 0, possible_adjacent_numbers, cache);
}
};
