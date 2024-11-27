class ProductOfNumbers {
public:

    vector<int> p = {1};

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        int curr = p.back();
        if(curr==0){
            p = {1, num};
        }else{
            p.push_back(curr * num);
        }
    }
    
    int getProduct(int k) {
        int n = p.size();
        if(n-1-k<0){
            return 0;
        }
        return (int)(p[n-1]/p[n-1-k]);
    }
};