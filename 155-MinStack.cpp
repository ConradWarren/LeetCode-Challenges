class MinStack {
public:

	int min_value;
	std::vector<int> stack;

	MinStack() {
		min_value = INT_MAX;
	}

	void push(int val) {
		if (val < min_value) {
			min_value = val;
		}
		stack.push_back(val);
	}

	void pop() {

		if (stack.back() == min_value) {
			min_value = INT_MAX;
			for (int i = 0; i < int(stack.size()) - 1; i++) {
				min_value = (min_value > stack[i]) ? stack[i] : min_value;
			}
		}
		stack.pop_back();
	}

	int top() {
		
		return stack.back();
	}

	int getMin() {

		return min_value;
	}
};
