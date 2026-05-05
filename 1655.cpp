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
        unordered_map<int, int> dupesFound, dupeCatagories;

        /************************
        * Just make it dirty    *
        *                       *
        * we can optimize once  *
        * it's working          *
        ************************/
        
        if(quantity.size() > nums.size()){ // if we have more requests then items, it's not possible to serve everyone
            return false;
        }

        for(int i = 0; i < nums.size(); i++){
            if(dupesFound.count(nums[i]) == 0){
                dupesFound.insert({nums[i], 1});
            }else{
                dupesFound[nums[i]] += 1;
            }
        }
        for(int j = 0; j < dupesFound.size(); j++){
            if(dupesFound[j] > 1){
                if(dupeCatagories.count(dupesFound[j]) == 0){
                    dupeCatagories.insert({dupesFound,})
                }
            }
        }
        return true;
    }
};
