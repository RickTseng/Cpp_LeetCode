#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        rec.push_back(0);
        rec.push_back(big);
        rec.push_back(medium);
        rec.push_back(small);
    }
    
    bool addCar(int carType) {
        if(rec[carType]-1>=0){
            rec[carType]--;
            return true;
        }
        return false;
    }
private:
    vector<int> rec;
};