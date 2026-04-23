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

        int count = 0, lowestRemovals = 0;
        bool isA = true;
        vector<int> countBuckets;
        std::vector<char> bucketLabels;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                if(i == 0){
                    count++;
                }else if(isA){
                    count++;
                }else{
                    countBuckets.push_back(count);
                    bucketLabels.push_back('a');
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
                    bucketLabels.push_back('b');
                    count = 1;
                }
            }
        }

        if(!countBuckets.empty()){
            int preBs = 0, postAs = 0;
            for(int j = countBuckets.size() - 1; j >= 0; j--){
                for(int k = countBuckets.size() - 1; k >= 0; k--){
                    if(k >= j && bucketLabels[k] == 'a'){
                        postAs += countBuckets[k];
                    }else if(k < j && bucketLabels[k] == 'b'){
                        preBs += countBuckets[k];
                    }
                }
                if(preBs + postAs < lowestRemovals){
                    lowestRemovals = preBs + postAs;
                }
            }
        // moving left to right, using 2 counters, figure out the cost of
        // "making this the split point between all a's and all b's"
            
        }
        return lowestRemovals;
    }
};
