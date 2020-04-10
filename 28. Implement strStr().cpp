/*
Link: 


*/
// using iteration
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j, n = haystack.length(), m = needle.length();
        if(!m)
            return 0;
        if(!n || n < m)
            return -1;
        for(i = 0; i <= n - m ; i++){
            if(haystack[i] == needle[0]){
                int k = i;
                for(j = 0; j < m ; j++){
                    if(haystack[k] == needle[j] && k < n && j < m){
                        k++;
                        if(j == m-1)
                            return i;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    return -1;
    }
};