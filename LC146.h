class LRUCache {
    int csize;
    list<pair<int, int> > dq;
    unordered_map<int, list<pair<int, int> >::iterator> ma;
    
public:
    LRUCache(int capacity) {
        csize = capacity;
    }
    
    int get(int key) {
        if(ma.find(key) == ma.end()) {
            return -1;
        } else{
            int val = ma[key] -> second;
            dq.erase(ma[key]);
            dq.push_front({key, val});
            ma[key] = dq.begin();
            return val;
        }            
    }
    
    void put(int key, int value) {
        if(ma.find(key) == ma.end() ){
            if(dq.size() == csize){
                pair<int, int> last = dq.back();
                dq.pop_back();
                ma.erase(last.first);
            }
        }
        else
            dq.erase(ma[key]);
        
        dq.push_front({key, value});
        ma[key] = dq.begin();
    }  
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */