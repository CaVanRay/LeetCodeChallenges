/*
Title: Minimum Deletions To Make String Balanced
Difficulty: Medium
Author: Cavan Ray Theiss

Description: 

You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. 
s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

to clarify:
You must delete characters so no 'b' appears before any 'a'. 
The goal is to maximize the number of characters kept, specifically by keeping a valid split point between 'a's and 'b's. 

Return the minimum number of deletions needed to make s balanced.
*/

class Solution {
public:
    int minimumDeletions(string s) {

        int count = 0, removals = 0;
        bool isA = true;
        vector<int> countBuckets;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                if(i == 0){
                    count++;
                }else if(isA){
                    count++;
                }else{
                    countBuckets.push_back(count);
                    count = 1;
                }
            }else{
                if(i == 0){
                    count++;
                    isA = false;
                }else if(!isA){
                    count++;
                }else{
                    countBuckets.push_back(count);
                    count = 1;
                }
            }
        }

        if(!countBuckets.empty()){
            
            if(s[0] == 'a'){
                isA = true;
            }else{
                isA = false;
            }
        
            while(countBuckets.size() > 2){
                if(!isA){
                    removals += countBuckets[0];
                    countBuckets.erase(countBuckets.begin());
                }
                if(countBuckets.size() >= 3){
                    if(countBuckets[1] < countBuckets[2]){
                        removals += countBuckets[1];
                        countBuckets[0] += countBuckets[2];
                        countBuckets.erase(countBuckets.begin() + 1, countBuckets.begin() + 3);
                    }
                }
            }
        }
        return removals;
    }
};
