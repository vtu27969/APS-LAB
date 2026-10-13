class MyCircularQueue {
private:
    vector<int> q;
    int head;
    int tail;
    int capacity;
    int count;

public:
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        head = 0;
        tail = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        q[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        head = (head + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        // tail points to the next insertion spot, so the last element is at (tail - 1 + capacity) % capacity
        return q[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */