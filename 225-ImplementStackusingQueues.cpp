class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        nums.push_back(x);
    }

    int pop() {
        int num = nums.back();
        nums.pop_back();
        return num;
    }

    int top() {
        return nums.back();
    }

    bool empty() {
        return nums.empty();
    }
private:
    std::vector<int> nums;
};
