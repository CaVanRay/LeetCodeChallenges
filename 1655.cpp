/*****************************************************************************************************************
|    Challenge #: 1655                                                                                           |     
|    Difficulty: Hard                                                                                            |    
|    Title: Distribute Repeating Integers                                                                        |    
|    Author: Cavan Ray Theiss                                                                                    |            
|                                                                                                                |            
|    Description:                                                                                                |            
|                                                                                                                |                                
|    You are given an array of n integers, nums, where there are at most 50 unique values in the array.          |       
|    You are also given an array of m customer order quantities, quantity, where quantity[i] is the              |       
|    amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:      |          
|                                                                                                                |                
|    The ith customer gets exactly quantity[i] integers,                                                         |                           
|    The integers the ith customer gets are all equal, and Every customer is satisfied.                          |         
|    Return true if it is possible to distribute nums according to the above conditions.                         |                               
|                                                                                                                |            
*****************************************************************************************************************/
/*
bool solutionChecker(int customer, vector<int>& counts, vector<int>& quantity){
    if(customer == quantity.size()){
        return true;
    }

    int needed = quantity[customer];

    for(int i = 0; i < counts.size(); i++){
        if(counts[i] >= needed){
            counts[i] -= needed;
            if(solutionChecker(customer + 1, counts, quantity)){
                return true;
            }
            counts[i] += needed;
        }
    }
    return false;
}
*/




bool solutionChecker(int mask, vector<int> counts, vector<int>& quantity, unordered_map<int, bool>& attemptedCombos){
    if(mask == (1 << quantity.size()) - 1) return true;

    int customer = -1;
    for(int i = 0; i < quantity.size(); i++){
        if(!(mask & (1 << i))){
            customer = i;
            break;
        }
    }

    if(attemptedCombos.count(mask)) return attemptedCombos[mask];

    int needed = quantity[customer];
    for(int i = 0; i < counts.size(); i++){
        if(counts[i] >= needed){
            counts[i] -= needed;
            if(solutionChecker(mask | (1 << customer), counts, quantity, attemptedCombos)){
                return attemptedCombos[mask] = true;
            }
           //counts[i] += needed;
        }
    } 
    return attemptedCombos[mask] = false;
}

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {

        // Variable declarations
        unordered_map <int, int> combinedDupes;
        unordered_map <int, bool> attemptedCombos;
        vector<int> dupeCounts;

        // Sorting provided info from largest to smallest
        sort(nums.begin(), nums.end(), greater<int>());
        sort(quantity.begin(), quantity.end(), greater<int>());

        // Counting the different numbers of duplicates
        for(auto& number : nums){
            combinedDupes[number] += 1;
        }
        for(auto& pair : combinedDupes){
            dupeCounts.push_back(pair.second);
        }

        // return the solution provided by recursive function solutionChecker()
        return(solutionChecker(0, dupeCounts, quantity, attemptedCombos));
        
    }
};
