#ifndef REWARDS_H
#define REWARDS_H
#include <iostream>
#include <vector>
using namespace std;

class Rewards {
public:
    static int globalRewardThresholds[3];
    int rewardPoints;
    vector<string> badges;
    
    Rewards();
    void addPoints(int points);
    void assignBadge();
    void showRewards(const string& userName);
};

#endif
