class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k];
        size = k;
        length = front = end = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(length >= size) return false;
        ++length;
        data[end] = value;
        end = (end+1) % size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(length <= 0) return false;
        --length;
        front = (front + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return (length) ?data[front] : -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        int tmp = (end - 1 + size) % size; 
        return data[tmp];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return length == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return length == size;
    }
    
private:
    int *data;
    int size, front, end, length;    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */