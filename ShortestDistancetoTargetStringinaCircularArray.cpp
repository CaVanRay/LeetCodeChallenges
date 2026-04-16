/*
Rank: Easy
Title: Shortest Distance to Target String in a Circular Array
Author: Cavan Ray Theiss

Description: Given a circular array of strings, a starting point, and 
a word to look for, We need to return the shortest distance
from our starting point to the word we need to search for.

Input: An array of strings, a string to search for, an integer
for the starting index where we begin

Output: an integer representing the smallest distance between the starting
index and the string we are searching for
*/

class Solution {

};

/*
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int fullSize = words.size();
        int minimalDistance;
        
        auto it = std::find(words.begin(), words.end(), target);
        int idx = std::distance(words.begin(), it);
        if(it != words.end()){
            if(idx == startIndex){
                return 0;
            }else{
                if(idx < startIndex){
                    minimalDistance = startIndex - idx;
                    minimalDistance = min(minimalDistance, (fullSize - startIndex + idx));
                    return minimalDistance;
                }else{
                    minimalDistance = idx - startIndex;
                    minimalDistance = min(minimalDistance, (fullSize - idx + startIndex));
                    return minimalDistance;
                }
            }
        }else{
            return -1;
        }
        
    }
};
*/
