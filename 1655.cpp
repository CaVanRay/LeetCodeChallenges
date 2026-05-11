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

    // if no customers left, all orders have been successfully filled
    if(customer == quantity.size()){
        return true;
    }

    // current order to focus on filling
    int needed = quantity[customer];

    // Check inventory of duplicates against current order
    for(int i = 0; i < counts.size(); i++){

        // if item in inventory is larger or equal to order, remove what is taken
        // then move onto next order to fill
        // when the next order returns true, return true for this order (recursion)
        if(counts[i] >= needed){
            counts[i] -= needed;
            if(solutionChecker(customer + 1, counts, quantity)){
                return true;
            }
            counts[i] += needed;
        }
    }
    // if this point is reached, we were unsuccessful in filling all orders
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
