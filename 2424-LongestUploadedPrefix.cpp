class LUPrefix {
public:
	LUPrefix(int n) {
		cache.resize(n + 1, false);
		cache[0] = true;
		last_longest = 0;
	}

	void upload(int video) {
		cache[video] = true;
	}

	int longest() {

		for (int i = last_longest; i < cache.size(); i++) {
			
			if (cache[i]) last_longest = i;
			
			else break;
		}

		return last_longest;
	}
private:
	std::vector<bool> cache;
	int last_longest;
};
