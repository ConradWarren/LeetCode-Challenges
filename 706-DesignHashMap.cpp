#include <vector>

class MyHashMap {
public:

	std::vector<bool> has_element;
	std::vector<int> arr;

	MyHashMap() {

		arr.resize(1000001);
		has_element.resize(1000001);
	}

	void put(int key, int value) {

		has_element[key] = true;
		arr[key] = value;

	}

	int get(int key) {

		if (!has_element[key]) {
			return -1;
		}

		return arr[key];
	}

	void remove(int key) {
		has_element[key] = false;
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
