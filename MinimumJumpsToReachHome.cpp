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


    /***************************************************************************
    * isValidLandingSpot()  will check prospective spots to prevent landing on *
    * forbidden spots or revisiting already visited locations                  *
    ***************************************************************************/
    bool isValidLandingSpot(){
        bool isValid = true;
            
        /************************************************
        *             TO ADD LATER                      *
        ************************************************/

       return isValid;     
    }


    /**************************************************************
    *        Main engine block for this whole thing               *
    **************************************************************/
    int minimumJumps(vector<int>& forbidden, int forwardJump, int backwardJump, int homeSpot) {
        unordered_map<int, spotData> visitedSpots;
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
        queue<spotData> nextToVisit;
        nextToVisit.push(spotData());
        bool seekingHome = true;
        int currentSpot, minimumNumberOfJumps = numeric_limits<int>::max();
        
        while(!nextToVisit.empty()){
            currentSpot = nextToVisit.front().currentSpot;
            visitedSpots[currentSpot] = nextToVisit.front();
            
            // check if home
            if(currentSpot == homeSpot){
                minimumNumberOfJumps = min(minimumNumberOfJumps, nextToVisit.front().numberOfJumps);
            }
            
            /******************************************
            * Normally this would be the validation   *
            * step but for now, just until I get      *
            * the basic loop working, I will be       *
            * skipping validation                     *
            ******************************************/
            
            if(forbiddenSet.count(currentSpot + forwardJump) == 0 && (currentSpot + forwardJump <= homeSpot + backwardJump) ){
                if(visitedSpots.count(currentSpot + forwardJump) == 0){
                        nextToVisit.push( nextToVisit.front() + forwardJump );
                }
            }
            if(forbiddenSet.count(currentSpot - backwardJump) == 0 && (currentSpot - backwardJump > 0)){
                if(visitedSpots.count(currentSpot - backwardJump) == 0){
                        nextToVisit.push( nextToVisit.front() + (-backwardJump));
                }
            }
            nextToVisit.pop();

        }
            if(minimumNumberOfJumps == numeric_limits<int>::max()){
                    minimumNumberOfJumps = -1;
            }
     return minimumNumberOfJumps;   
    }
};
