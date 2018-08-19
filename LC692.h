class Solution {
public:
    struct cmp{
        bool operator() (pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second || a.second == b.second && a.first < b.first; 
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> freq;
        priority_queue < pair<string, int>, vector< pair<string, int>>, cmp > q;
        for(auto i : words) ++freq[i];
        for(auto i : freq){
            q.push(i);
            if(q.size() > k) q.pop();
        }
        vector<string> res(q.size());
        for(int i = q.size()-1; i>= 0 ;--i){
            string s = q.top().first; q.pop();
            res[i] = s;
        }
        return res;
    }
};