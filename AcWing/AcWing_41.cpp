class MinStack {
public:
    vector<int> items;
    int size = 0;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        items.push_back(x);
        size ++;
    }
    
    void pop() {
        items.pop_back();
        size --;
    }
    
    int top() {
        return items.back();
    }
    
    int getMin() {
        int min = 2147483647;
        for (int i = 0; i < size; i ++ ){
            if (items[i] < min) min = items[i];
        }
        return min;
    }
};
