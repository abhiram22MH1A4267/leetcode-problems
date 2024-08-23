class Solution {
public:
    struct frac_t {
        int above;
        int below;
    };
    void getFrac(vector<frac_t>&fracs, string expr){
        int N = expr.length();
        int index = 0;
        int sign = 1;
        frac_t frac;
        int digit = 0;
        while(index < N){
            if(isdigit(expr[index])){
                digit = digit * 10 + (expr[index]-'0');
            }
            else if(expr[index] == '/'){
                frac.above = sign * digit;
                digit = 0;
                sign = 1;
            }
            else{
                frac.below = sign * digit;
                fracs.push_back(frac);
                digit = 0;
                sign = expr[index] == '+' ? 1 : -1;
            }
            ++index;
        }
        frac.below = sign * digit;
        fracs.push_back(frac);
    }
    void addFrac(frac_t &result, frac_t toAdd) {
        if (result.below == 0) {
            result = toAdd;
            return ;
        }

        int below_lcm = lcm(result.below, toAdd.below);
        result.above *= below_lcm / result.below;
        toAdd.above *= below_lcm / toAdd.below;

        result.above += toAdd.above;
        result.below = below_lcm;
    }
    string fractionAddition(string expression) {
        vector<frac_t>fracs;
        getFrac(fracs,expression);
        frac_t result(0, 0);
        for (frac_t frac : fracs) {
            addFrac(result, frac);
        }

        if (result.above == 0) {
            return "0/1";
        }

        int result_gcd = gcd(result.above, result.below);
        result.above /= result_gcd;
        result.below /= result_gcd;

        return to_string(result.above) + "/" + to_string(result.below);
    }
};