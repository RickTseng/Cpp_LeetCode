#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        priority_queue<int, vector<int>, greater<>> _seats, _students;
        for (int i = 0; i < seats.size(); i++)
        {
            _seats.push(seats[i]);
            _students.push(students[i]);
        }
        int count = 0;
        while (!_seats.empty())
        {
            count += abs(_seats.top() - _students.top());
            _seats.pop();
            _students.pop();
        }
        
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> seats = {2, 2, 6, 6};
    vector<int> students = {1, 3, 2, 6};
    int ans = sol.minMovesToSeat(seats, students);
}
/*
n == seats.length == students.length
1 <= n <= 100
1 <= seats[i], students[j] <= 100
*/