class StockPrice {
public:
	StockPrice() {
		latest_timestamp = 0;
	}

	void update(int timestamp, int price) {

		valid_price_map[timestamp] = price;
		latest_timestamp = (latest_timestamp > timestamp) ? latest_timestamp : timestamp;

		while (!max_heap.empty() && valid_price_map[max_heap.top().second] != max_heap.top().first) {
			max_heap.pop();
		}
		while (!min_heap.empty() && valid_price_map[min_heap.top().second] != min_heap.top().first) {
			min_heap.pop();
		}

		max_heap.push({ price, timestamp });
		min_heap.push({ price, timestamp });
	}

	int current() {
		return valid_price_map[latest_timestamp];
	}

	int maximum() {
		return max_heap.top().first;
	}

	int minimum() {
		return min_heap.top().first;
	}
private:

	std::priority_queue<std::pair<int, int>> max_heap;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
	std::unordered_map<int, int> valid_price_map;
	int latest_timestamp;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
