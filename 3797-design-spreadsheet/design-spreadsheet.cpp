class Spreadsheet {
public:
    unordered_map<string, int>mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string cell) {
        int i = 1;
        while(cell[i] != '+'){
            i++;
        }
        string val1 = cell.substr(1, i-1), val2 = cell.substr(i+1);
        int left = (val1[0] >= 'A' && val1[0] <= 'Z') ? mp[val1] : stoi(val1);
        int right = (val2[0] >= 'A' && val2[0] <= 'Z') ? mp[val2] : stoi(val2);
        // cout<<val1<<" "<<mp[val1]<<endl;
        return left + right;  
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */