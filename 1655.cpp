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

        /***************************
        * Just to make it easier   *
        *                          *
        * I'm sorting both list    *
        * from largest to smallest *
        ***************************/

        sort(nums.begin(), nums.end(), greater<int>());
        sort(quantity.begin(), quantity.end(), greater<int>());
        
        /************************
        * Just make it dirty    *
        *                       *
        * we can optimize once  *
        * it's working          *
        ************************/
        
        if(quantity.size() > nums.size()){ // if we have more requests then items, it's not possible to serve everyone
            return false;
        }

        /****************************************************
        *                                                   *
        *   First we run through the provided nums vector   *
        *                                                   *
        *   all duplicates are combined in an unordered_map *
        *                                                   *
        ****************************************************/
        for(int i = 0; i < nums.size(); i++){
            if(dupesFound.count(nums[i]) == 0){
                dupesFound.insert({nums[i], 1});
            }else{
                dupesFound[nums[i]] += 1;
            }
        }

        /****************************************************
        *                                                   *
        *   Next we toss anything counted only once         *
        *                                                   *
        *   and what is left over gets combined into        *
        *   another unordered_map along with a count        *
        *   of how many of each duplicate amount was found  *
        *                                                   *
        ****************************************************/
        for(int j = 0; j < dupesFound.size(); j++){
            if(dupesFound[j] > 1){
                if(dupeCatagories.count(dupesFound[j]) == 0){
                    dupeCatagories.insert({dupesFound[j], 1});
                }else{
                    dupeCatagories[dupesFound[j]] += 1;
                }
            }
        }
        
        /****************************************************
        *                                                   *
        *   Lastly, we now go through the list of orders    *
        *                                                   *
        *   every match we find subtracts from that size    *
        *   if that size isn't found, or hits zero we can   *
        *   either return false, Or try going up a size     *
        *                                                   *
        ****************************************************/
        for(int k = 0; k < quantity.size(); k++){
            if(dupeCatagories.count(quantity[k]) == 0){
                return false; // this is temporary and will be changed later to check for larger sizes
            }else if(dupeCatagories[quantity[k]] > 0){
                dupeCatagories[quantity[k]] -= 1;
            }else{
                return false; // this is temporary and will be changed later to check for larger sizes
            }
        }
        
        return true;
    }
};
