/*
Title: Diffuse The Bomb
Author: Cavan Ray Theiss

Description: decrypt the code to diffuse the bomb

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous -k numbers.
If k == 0, replace the ith number with 0.

The array is circular, so when you reach the end it goes back to the beginning

*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> decrypted(code.size());
        if(k > 0){
            for(int d = 0; d < code.size(); d++){
                int sum = 0;
                for(int l = 1; l <= k; l++){
                    if(d+l < code.size()){
                        sum = sum + code[d + l];
                    }else{
                        sum = sum + code[l-(code.size()-d)];
                    }
                }
                decrypted[d] = sum;
            }
            
        }else if(k < 0){
                for(int d = 0; d < code.size(); d++){
                    int sum = 0;
                    for(int l = -1; l >= k; l--){
                        if(d+l < code.size()){
                            sum = sum + code[d + l];
                        }else{
                            sum = sum + code[l-(code.size()-d)];
                        }
                    }
                    decrypted[d] = sum;
                }
            
        }else{
            for(int i = 0; i < code.size(); i++){
                decrypted[i] = 0;
            }
        }

        return decrypted;
    }
};
