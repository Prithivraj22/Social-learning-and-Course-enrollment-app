#include "Rewards.h"
#include <iostream>
using namespace std;

int Rewards::globalRewardThresholds[3] = {30, 60, 100};

void Rewards::addPoints(int points) {
    rewardPoints += points;
    assignBadge();
}

void Rewards::assignBadge() {
    if (rewardPoints >= globalRewardThresholds[0] && badges.empty()) {
        badges.push_back("Bronze Learner");
    } else if (rewardPoints >= globalRewardThresholds[1] && badges.size() == 1) {
        badges.push_back("Silver Scholar");
    } else if (rewardPoints >= globalRewardThresholds[2] && badges.size() == 2) {
        badges.push_back("Gold Master");
    }
}

void Rewards::showRewards(const string& userName) {
    cout << "\nRewards for " << userName << ": " << rewardPoints << " points\n";
    if (!badges.empty()) {
        cout << "Badges Earned: ";
        for (const auto& badge : badges) {
            cout << badge << " ";
        }
        cout << "\n";
    }
}
