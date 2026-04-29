/*
Title: Minimum Jumps To Reach Home
Difficulty: Medium
Author: Cavan Ray Theiss

Description:
A certain bug's home is on the x-axis at position x. Help them get there from position 0.

The bug jumps according to the following rules:

It can jump exactly a positions forward (to the right).
It can jump exactly b positions backward (to the left).
It cannot jump backward twice in a row.
It cannot jump to any forbidden positions.
The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], 
and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no 
possible sequence of jumps that lands the bug on position x, return -1.
*/

/**********************************************************************
The basic stucture for information I need to track for every spot
we visit
**********************************************************************/

class Solution {
public:

    struct spotData{
    int currentSpot;
    bool justJumpedBack;
    int numberOfJumps;

    spotData operator+(const spotData& newSpot){
        
    }

    };


    /**********************************************************************
    Using the isValidLandingSpot() function as a way to combine the many 
    factors that I need to look out for in a single place

    Let it be messy out here while the main code is kept clean
    ***********************************************************************/
    bool isValidLandingSpot(vector<int>& visitedSpots, vector<int>& forbidden,int currentSpot, int potentialSpot, int homeSpot, int backwardJump, bool justJumpedBack){
        if(potentialSpot < 0){
            return false;
        }else if(potentialSpot - homeSpot > backwardJump){
            return false;
        }else if(find(forbidden.begin(), forbidden.end(), potentialSpot) != forbidden.end()){
            return false;
        }else if(find(visitedSpots.begin(), visitedSpots.end(), potentialSpot) != visitedSpots.end()){
            return false;
        }else if((justJumpedBack) && (currentSpot > potentialSpot)){
            return false;
        }else{
            return true;
        }
        
    }


    /**********************************************************************
    Here is the main engine block for this whole thing

    need to do some re-writing but so far I've kept it decently simple/clean
    **********************************************************************/
    int minimumJumps(vector<int>& forbidden, int forwardJump, int backwardJump, int homeSpot) {
        vector<int> visitedSpots;
        queue<spotData> nextToVisit;
        int currentSpot = 0, currentSpotJumpCount = 0, minimumNumberOfJumps = numeric_limits<int>::max();
        bool justJumpedBack = false;

        nextToVisit.push({0, false, 0});
        while(!nextToVisit.empty()){
            currentSpot = nextToVisit.front().currentSpot;
            justJumpedBack = nextToVisit.front().justJumpedBack;
            currentSpotJumpCount = nextToVisit.front().numberOfJumps;
            visitedSpots.push_back(currentSpot);
            nextToVisit.pop();

            if(isValidLandingSpot(visitedSpots, forbidden, currentSpot, currentSpot + forwardJump, homeSpot, backwardJump, justJumpedBack)){
                nextToVisit.push({currentSpot + forwardJump, false, currentSpotJumpCount + 1});
                if((currentSpot + forwardJump == homeSpot) && (currentSpotJumpCount + 1 < minimumNumberOfJumps)){
                    minimumNumberOfJumps = currentSpotJumpCount + 1;
                }
            }
            if(isValidLandingSpot(visitedSpots, forbidden, currentSpot, currentSpot - backwardJump, homeSpot, backwardJump, justJumpedBack)){
                nextToVisit.push({currentSpot - backwardJump, true, currentSpotJumpCount + 1});
                if((currentSpot - backwardJump == homeSpot) && (currentSpotJumpCount + 1 < minimumNumberOfJumps)){
                    minimumNumberOfJumps = currentSpotJumpCount + 1;
                }
            }
            
        }
        
        if(minimumNumberOfJumps == numeric_limits<int>::max()){
            return -1;
        }else{
            return minimumNumberOfJumps;
        }
    }
};
