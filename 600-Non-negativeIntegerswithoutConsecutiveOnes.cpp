class Solution {
public:
int findIntegers(int n) {

	std::vector<int> cache(32, 0);
	cache[0] = 1;
	cache[1] = 2;
	
	for (int i = 2; i < 32; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
	}

	int result = 0;
	bool previous_flag = 0;
	for (int i = 30; i >= 0; i--) {
		if (n & (1 << i)) {
			result += cache[i];

			if (previous_flag) return result;
			previous_flag = true;
		}
		else previous_flag = false;
		
	}
	return result+1;
}
};
