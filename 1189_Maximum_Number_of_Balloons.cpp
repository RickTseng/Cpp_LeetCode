#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution{
    public:
    int maxNumberOfBalloons(string text) {
        map<char,int> _map = {
            {'a',0},
            {'b',0},
            {'l',0},
            {'n',0},
            {'o',0},
        };
        for(auto s:text){
            if(_map.find(s)!=_map.end()){
                _map[s]+=1;
            }
        }
        _map['l']/=2;
        _map['o']/=2;
        int _min = text.size();
        for(auto i:_map){
            _min = min(i.second,_min);
        }
        return _min;
    }
};
int main(){
    Solution sol;
    string text = "loonbalxballpoon";
    int ans = sol.maxNumberOfBalloons(text);

}