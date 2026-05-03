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



        /*******************************************************************************
        * The basic stucture for information I need to track for every spot            *
        * we visit                                                                     *
        *                                                                              *
        * I've also overloaded the + operator to allow me to easily create new         *
        * jump spots, though it will require making all backward jumps into negative   *
        * numbers, but that should be fine                                             *
        ********************************************************************************/

class Solution {
public:

    // Basic data structure

    struct spotData{
    int currentSpot;
    bool justJumpedBack;
    int numberOfJumps;
    bool visitedByFrontJump;
    bool visitedByBackwJump;

    // Default constructor for start of program
    
    spotData(){
        currentSpot = 0;
        justJumpedBack = true;
        numberOfJumps = 0;
        visitedByFrontJump = true;
        visitedByBackwJump = true;        
    }

    // All following structures should be created by jumps after original

    spotData operator+(int jumpValue){
        spotData newSpot;
        newSpot.currentSpot = this->currentSpot + jumpValue;
        newSpot.justJumpedBack = jumpValue < 0;
        newSpot.numberOfJumps = this->numberOfJumps + 1;
        newSpot.visitedByFrontJump = !newSpot.justJumpedBack;
        newSpot.visitedByBackwJump = newSpot.justJumpedBack;
        return newSpot;
    }

    };

    /**************************************************************
    *        Main engine block for this whole thing               *
    **************************************************************/
    int minimumJumps(vector<int>& forbidden, int forwardJump, int backwardJump, int homeSpot) {
        unordered_map<int, spotData> visitedSpots;
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
        queue<spotData> nextToVisit;
        nextToVisit.push(spotData());
        int currentSpot, upperBound = homeSpot + forwardJump + backwardJump;
        if(!forbidden.empty())
            upperBound = max(upperBound, *max_element(forbidden.begin(), forbidden.end()) + forwardJump + backwardJump);
        
        while(!nextToVisit.empty()){
            currentSpot = nextToVisit.front().currentSpot;
            if(visitedSpots.count(currentSpot) == 0){
                visitedSpots[currentSpot] = nextToVisit.front();
            }else{
                visitedSpots[currentSpot].visitedByFrontJump = !nextToVisit.front().justJumpedBack;
                visitedSpots[currentSpot].visitedByBackwJump = nextToVisit.front().justJumpedBack;
            }
            
            // check if home
            if(currentSpot == homeSpot){
                return nextToVisit.front().numberOfJumps;
            }
            
            /******************************************
            *    possible spot validation section     *
            ******************************************/
            
            if(forbiddenSet.count(currentSpot + forwardJump) == 0 &&         // if not forbidden
              (currentSpot + forwardJump <= upperBound) &&                   // if not beyond upper bound
              (visitedSpots.count(currentSpot + forwardJump) == 0 || !(nextToVisit.front().visitedByFrontJump))){ // if either not visited, or not visited by a forward jump
                
                nextToVisit.push( nextToVisit.front() + forwardJump );
                if(visitedSpots.count(currentSpot + forwardJump) == 0){
                        visitedSpots[currentSpot] = nextToVisit.front(); // this line is wrong, but we are kind of drunk, fix tomorrow
                }else{
                        visitedSpots[currentSpot].visitedByFrontJump = true;
                }
            }
            if(forbiddenSet.count(currentSpot - backwardJump) == 0 &&         // if not forbidden
              (currentSpot - backwardJump > 0) &&                             // if not a negative location
              !(visitedSpots[currentSpot].justJumpedBack) &&                  // if this isnt a second in a row backwards jump
              (visitedSpots.count(currentSpot - backwardJump) == 0 || !(visitedSpots[currentSpot - backwardJump].visitedByBackwJump))){ // if either not visited, or not visited by a backwards jump
        
                nextToVisit.push( nextToVisit.front() + (-backwardJump));
                if(visitedSpots.count(currentSpot - backwardJump) == 0){
                        visitedSpots[currentSpot - backwardJump] = nextToVisit.front(); // this line is wrong, but we are kind of drunk, fix tomorrow
                }else{
                visitedSpots[currentSpot].visitedByBackwJump = nextToVisit.front().justJumpedBack;
                }
                
            }
            nextToVisit.pop();

        }

     return -1;   
    }
};
