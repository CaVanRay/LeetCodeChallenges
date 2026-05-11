/*****************************************************************************************************************
|    Challenge #: 1655                                                                                           |     
|    Difficulty: Hard                                                                                            |    
|    Title: Distribute Repeating Integers                                                                        |    
|    Author: Cavan Ray Theiss                                                                                    |            
|                                                                                                                |            
|    Description:                                                                                                |            
|                                                                                                                |                                
|    Given a list of various repeating number and a                                                              |          
|    list of requested amounts of repeating numbers                                                              |  
|    return true/false if the requests can be filled                                                             |           
*****************************************************************************************************************/


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

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {

            // variable declarations
            unordered_map <int, int> combinedDupes;
            vector<int> dupeCounts;

            // sort provided vectors from largest to smallest
            sort(nums.begin(), nums.end(), greater<int>());
            sort(quantity.begin(), quantity.end(), greater<int>());
        
            // Count the frequency of duplicate quantities
            for(auto& number : nums){
                combinedDupes[number] += 1;
            }
            for(auto& pair : combinedDupes){
                dupeCounts.push_back(pair.second);
            }

            // Return result from recursive function
            return(solutionChecker(0, dupeCounts, quantity));
        
    }
};
