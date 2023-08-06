#include <vector>

class Solution {
public:
const int mod = int(1e9) + 7;

int Solve(int unique_song_count, std::vector<int>& song_counter, int n, int k, int goal, std::vector<std::vector<int>>& cache) {
	
	if (goal == 0) {
		return (unique_song_count == n) ? 1 : 0;
	}

	if (cache[unique_song_count][goal] != -1) {
		return cache[unique_song_count][goal];
	}

	int sum = 0;

	for (int i = 0; i < n; i++) {

		if (song_counter[i] == -1) {
			song_counter[i] = goal;
			sum += Solve(unique_song_count + 1, song_counter, n, k, goal - 1, cache);
			sum %= mod;
			song_counter[i] = -1;
			continue;
		}

		if (song_counter[i] - k <= goal) {
			continue;
		}
		int placeholder = song_counter[i];

		song_counter[i] = goal;

		sum += Solve(unique_song_count, song_counter, n, k, goal - 1, cache);
		sum %= mod;

		song_counter[i] = placeholder;
	}

	cache[unique_song_count][goal] = sum;

	return sum;
}

int numMusicPlaylists(int n, int goal, int k) {

	std::vector<int> song_counter(n, -1);
	std::vector<std::vector<int>> cache(n + 1, std::vector<int>(goal + 1, -1));

	return Solve(0, song_counter, n, k, goal, cache);
}
};
