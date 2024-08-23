from fractions import Fraction
class Solution:
    def fractionAddition(self, expression: str) -> str:
        s = eval(expression)
        if(s == int(s)):
            return str(int(s))+"/1"
        return str(Fraction(s).limit_denominator())