#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
		vector<int> db(directions.size()+1, 0);
		vector<bool>dn(directions.size() + 1, false);
		for (int i = 0; i < directions.size(); i++) {
			if (directions[i] == 'S') {
				db[i] = 1;
				dn[i] = true;
				if (i > 0 && directions[i - 1] == 'R') {
					db[i - 1] = 1;
					dn[i - 1] = true;
					count++;
				}
				if (i + 1 < directions.size() && directions[i +1] == 'L') {
					db[i + 1] = 1;
					dn[i + 1] = true;
					count++;
				}
			}
		}
		for (int i = 1; i < directions.size(); i++) 
		{
			if (directions[i - 1] == 'R' && directions[i] == 'L') {
				db[i - 1] = 1;
				db[i] = 1;
				dn[i - 1] = true;
				dn[i] = true;
				count += 2;
				
			}
		}
		for (int i = 0; i < directions.size(); i++)
		{
			if (!dn[i]) {
				if (directions[i] == 'L') {
					if (i > 0 && db[i - 1] != 0) {
						db[i] = 1;
						dn[i] = true;
						count++;
					}
				}
			}
		}
        for (int i = directions.size()-1; i>=0;i--)
		{
			if (!dn[i]) {
				if (directions[i] == 'R') {
					if (i + 1 < directions.size() && db[i + 1] != 0) {
						db[i] = 1;
						dn[i] = true;
						count++;
					}
				}
			}
		}
		return count;
    }
};
int main(){
    Solution sol;
    int ans = sol.countCollisions("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR");
}