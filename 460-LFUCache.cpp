class LFUCache {
public:

	std::unordered_map<int, std::list<std::pair<int, int>>> frequency_list_map;
	std::unordered_map<int, int> key_use_map;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> list_position_map;
	int max_size;
	int current_size;

	LFUCache(int capacity) {
		max_size = capacity;
		current_size = 0;
	}

	int get(int key) {

		if (key_use_map.find(key) == key_use_map.end()) return -1;

		int counter = key_use_map[key];
		int num = (*list_position_map[key]).second;

		key_use_map[key]++;
		frequency_list_map[counter].erase(list_position_map[key]);
		frequency_list_map[counter + 1].push_front({ key, num });
		list_position_map[key] = frequency_list_map[counter + 1].begin();
		
		return num;
	}

	void put(int key, int value) {

		if (key_use_map.find(key) != key_use_map.end()) {

			int counter = key_use_map[key];
			key_use_map[key]++;
			frequency_list_map[counter].erase(list_position_map[key]);
			frequency_list_map[counter + 1].push_front({ key, value });

			list_position_map[key] = frequency_list_map[counter + 1].begin();
			return;
		}

		if (current_size >= max_size) {

			int idx = 1;
			while (frequency_list_map[idx].empty()) {
				idx++;
			}

			int key_to_delete = frequency_list_map[idx].back().first;

			frequency_list_map[idx].pop_back();
			key_use_map.erase(key_to_delete);
			list_position_map.erase(key_to_delete);
		}

		current_size++;
		key_use_map[key] = 1;
		frequency_list_map[1].push_front({ key, value });
		list_position_map[key] = frequency_list_map[1].begin();
	}
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
