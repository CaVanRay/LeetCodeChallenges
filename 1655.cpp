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


// OK, starting from scratch
/*************************************************
*    Ok, I'm throwing out everything from before *
*    and starting from scratch                   *
*    To do this correctly I need to use:         *
*        - Backtracking                          *
*        - Dynamic Programming                   *
*        - Recursion                             *
*        - Memoize                               *
*                                                *
*************************************************/
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
// variable declarations
unordered_map <int, int> combinedDupes, dupeQuantityBuckets;
        
// First Count frequencies

// Next set up recursion function

// Add in mamoization
        
    }
};
