#include <list>
#include <unordered_map>

class LRUCache {
public:

	std::list<std::pair<int, int>> key_num_pairs;

	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

	int max_size;

	LRUCache(int capacity) {
		max_size = capacity;
	}

	int get(int key) {

		if (map.find(key) == map.end()) {
			return -1;
		}

		int num = (*map[key]).second;

		key_num_pairs.erase(map[key]);

		key_num_pairs.push_front({ key, num });

		map[key] = key_num_pairs.begin();
		
		return num;
	}

	void put(int key, int value) {

		if (map.find(key) == map.end()) {

			key_num_pairs.push_front({ key, value });

			if (key_num_pairs.size() > max_size) {
				map.erase(key_num_pairs.back().first);
				key_num_pairs.pop_back();
			}
			map[key] = key_num_pairs.begin();
			return;
		}

		key_num_pairs.erase(map[key]);
		key_num_pairs.push_front({ key, value });
		map[key] = key_num_pairs.begin();
	}
};
