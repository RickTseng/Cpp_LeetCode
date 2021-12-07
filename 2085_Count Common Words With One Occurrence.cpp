#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,pair<int,int>> ww;
        for(auto w1:words1){
            if(ww.find(w1)==ww.end()){
                ww[w1].first = 1;
            }
            else{
                ww[w1].first++;
            }
        }
        for(auto w2:words2){
            if(ww.find(w2)==ww.end()){
                ww[w2].second = 1;
            }
            else{
                ww[w2].second++;
            }
        }
        int count = 0;
        for(auto w:ww){
            if(w.second.first == w.second.second && w.second.first == 1){
                count++;
            }
        }
        return count;
        
    }
};