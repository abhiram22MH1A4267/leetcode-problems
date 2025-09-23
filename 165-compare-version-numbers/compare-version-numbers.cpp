class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int n = ver1.length(), m = ver2.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            int val1 = 0, val2 = 0;
            while(i < n && ver1[i] != '.'){
                val1 = (val1 * 10) + (ver1[i] - '0');
                i++;
            }
            while(j < m && ver2[j] != '.'){
                val2 = (val2 * 10) + (ver2[j] - '0');
                j++;
            }

            if(val1 < val2) return -1;
            else if(val2 < val1) return 1;

            i++;
            j++;
        }
        cout<<i<<" "<<j<<endl;
        while(i < n){
            if(ver1[i] != '0' && ver1[i] != '.') return 1;
            i++;
        }
        while(j < m){
            if(ver2[j] != '0' && ver2[j] != '.') return -1;
            j++;
        }

        return 0;
    }
};