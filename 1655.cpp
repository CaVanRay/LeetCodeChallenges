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
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> dupesFound, dupeCatagories;

        sort(nums.begin(), nums.end()), greater<int>();
        sort(quantity.begin(), quantity.end(), greater<int>());
        
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

        for(auto dupes : dupesFound){
            dupeCatagories[dupes.second] += 1;
        }
        
        for(auto& orders : quantity){
            int closestMatch = -1;
            for(auto& pair : dupeCatagories){
                if(pair.first >= orders && pair.second > 0){
                    if(closestMatch == -1 || pair.first < closestMatch){
                        closestMatch = pair.first;
                    }
                }
            }
            if(closestMatch == -1){
                return false;
            }
            dupeCatagories[closestMatch] -= 1;
            int remainder = closestMatch - orders;
            if(remainder > 0){
                dupeCatagories[remainder] += 1;
            }
        }
        
        return true;
    }
};
*/

// OK, starting from scratch
/*************************************************
*    Ok, I'm throwing out everything from before *
*    and starting from scratch                   *
*    
*************************************************/
