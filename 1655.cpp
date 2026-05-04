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

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered map<int, int> dupesFound;

        /**********************************************************
        * Ok, here's my idea, we count duplicates and take orders *
        * at the same time.                                       *
        *                                                         *
        * as we go through and check for duplicates of each num   *
        * we keep the order list up and everytime the current     *
        * order count is filled it gets rolled over to the next   *
        * order on the list                                       *
        *                                                         *   
        * if we run out of orders before num's, we return true,   *
        * if we run out of num's before orders, we return false   *
        *                                                         *       
        * my only worry is that this solution seems to easy for   *
        * a challenge ranked 'hard', especially seeing how the    *
        * medium level challenge I just finished took about a     *
        * week to finish                                          *
        **********************************************************/

        if(quantity.length > nums.length){ // if we have more requests then items, it's not possible to serve everyone
            return false
        }
        
    }
};
