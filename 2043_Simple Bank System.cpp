#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Bank
{
public:
    Bank(vector<long long> &balance)
    {
        db = balance;
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1> db.size() || account2 > db.size() ||db[account1 - 1] < money)
        {
            return false;
        }
        db[account1 - 1] -= money;
        db[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account> db.size() || db[account - 1] + money > LLONG_MAX)
        {
            return false;
        }
        db[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account> db.size() || db[account - 1] < money)
        {
            return false;
        }
        db[account - 1] -= money;
        return true;
    }

private:
    vector<long long> db;
};
int main(){
    vector<long long> bb = {92,62,12,81,77,38,71,8,42,38};
    Bank *b = new Bank(bb);
    b->transfer(3,2,18);
    b->transfer(29,3,99);
    b->deposit(8,97);

}
/*
["Bank","transfer","transfer","deposit"]
[[[92,62,12,81,77,38,71,8,42,38]],[3,2,18],[29,3,99],[8,97]]

*/