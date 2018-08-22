class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(bank.size() == 0) return -1;
        char gens[4] = {'A', 'C', 'G', 'T'};
        unordered_set<string> s{bank.begin(), bank.end()};
        unordered_set<string> vis;
        queue<string> q{ {start} };
        int level = 0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                string t = q.front(); q.pop();
                if(t == end) return level;
                for(int i = 0; i<t.size(); ++i){
                    char old = t[i];
                    for(char c : gens){
                        t[i] = c;
                        if(s.count(t) && vis.count(t) == 0){
                            q.push(t);
                            vis.insert(t);
                        }
                    }
                    t[i] = old;
                }
            }
            ++level;
        }
        return -1;
    }
};