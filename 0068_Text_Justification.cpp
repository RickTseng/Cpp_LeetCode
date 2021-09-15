#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
class Solution{
    public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int index = 0;
        string tmp = "";
        vector<string> line;
        map<int,int> spaceIndex;
        while (index<words.size())
        {
            if(tmp.size() + words[index].size()<=maxWidth){
                tmp+=words[index]+" ";
                spaceIndex[tmp.size()-1]=1;
                line.push_back(words[index]);
                index++;
            }
            else{
                if(spaceIndex.size()>1){
                    spaceIndex.erase(--spaceIndex.end());
                    tmp.pop_back();
                    int len = tmp.size();
                    while (len<maxWidth)
                    {
                        for(auto &i:spaceIndex){
                            i.second++;
                            len++;
                            if(len>=maxWidth){
                                break;
                            }
                        }
                    }
                    while (!spaceIndex.empty())
                    {
                        int z = spaceIndex.rbegin()->first;
                        for(int i = 1;i<spaceIndex[z];i++){
                            tmp.insert(z," ");
                        }
                        spaceIndex.erase(--spaceIndex.end());
                    }
                }
                else{
                    tmp.pop_back();
                    while (tmp.size()<maxWidth)
                    {
                        tmp+=" ";
                    }
                }
                res.push_back(tmp);
                line.clear();
                tmp = "";
                spaceIndex.clear();
            }
            
            
        }
        //fillSpace(tmp,maxWidth);
        tmp.pop_back();
        while (tmp.size()<maxWidth)
        {
            tmp+=" ";
        }
        
        res.push_back(tmp);
        return res;
    }

};
int main(){
    Solution sol;
    //vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words = {"Listen","to","many,","speak","to","a","few."};
    vector<string> ans = sol.fullJustify(words,6);
}
//"This", "is", "an", "example", "of", "text", "justification."maxWidth = 16;
//Runtime: 4 ms, faster than 48.19% of C++ online submissions for Text Justification.
//Memory Usage: 7.5 MB, less than 53.90% of C++ online submissions for Text Justification.