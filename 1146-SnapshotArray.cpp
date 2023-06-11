class SnapshotArray {
public:

	SnapshotArray(int length) {
		cache.resize(length);
		current_snap_id = 0;
	}

	void set(int index, int val) {

		cache[index].push_back({ val, current_snap_id });

	}

	int snap() {
		current_snap_id++;

		return current_snap_id - 1;
	}

	int get(int index, int snap_id) {

		if (cache[index].empty()) {
			return 0;
		}

		for (int i = cache[index].size() - 1; i >= 0; i--) {
			if (cache[index][i].second <= snap_id) {
				return cache[index][i].first;
			}
		}

		return 0;
	}
private:
	std::vector<std::vector<std::pair<int, int>>> cache;
	int current_snap_id;
};
