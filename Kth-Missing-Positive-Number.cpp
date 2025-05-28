class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missingArr ; 
        int j = 0 ; 
        for(int i = 1 ; i < arr[arr.size()-1]; i++){
            if(arr[j] == i){
                j++ ; 
            }
            else{
                missingArr.push_back(i) ;
            }
        }
        if(missingArr.size() < k ) return arr[arr.size()-1] + (k-missingArr.size()) ;
        else return missingArr[k-1] ;
    }
};