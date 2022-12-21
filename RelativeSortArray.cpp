class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int, int> mp;
        vector<int> result, inter;

        for(int i = 0; i < arr1.size(); i++) 
            mp[arr1[i]]++;

        for(int i = 0; i < arr2.size(); i++) {

            for(int j = 0; j < mp[arr2[i]]; j++)
                result.push_back(arr2[i]);

            mp[arr2[i]] = 0;
        
        }

        for(auto i = mp.begin(); i != mp.end(); i++)
            if(i -> second != 0) {
                for(int j = 0; j <i -> second; j++)
                    inter.push_back(i -> first);
            }
                

        sort(inter.begin(), inter.end());

        for(int i : inter) result.push_back(i);

        return result;
    }
};