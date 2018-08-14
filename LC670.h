class Solution {
public:
    int maximumSwap(int num) {
        vector<int> data;
        int tmp = num;
        
        while(tmp){
            data.push_back(tmp % 10);
            tmp /= 10;
        }
        int n = data.size();
        int *back = new int[n];
        back[0] = data[0];
        
        for(int i = 1; i<n; ++i){
            back[i] =  (data[i] > back[i-1]) ? data[i] : back[i-1] ;
        }
        
        
        int swap1 = n;
        for(int i = n-1; i>=0; --i){
            if(data[i] < back[i]) {
                swap1 = i;
                break;
            }
        }
        if(swap1 == n) return num;
        int swap2 = 0, max = data[0];
        for(int i = 0; i<=swap1; ++i){
            if(data[i] == back[swap1]) {
                swap2 = i;
                break;
            }
        }
        swap(data[swap1], data[swap2]);
        num = 0;
        for(int i = n-1; i>=0; --i){
            num = num * 10 + data[i];
        }
        return num;
        
    }
};