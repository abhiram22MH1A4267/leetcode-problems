class ProductOfNumbers {
public:
    vector<int>mat;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        mat.push_back(num);
    }
    
    int getProduct(int k) {
        int n = mat.size();
        if(k > n) return -1;
        int ans = 1;
        for(int i = n-1; i >= n-k; i--){
            ans *= mat[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */