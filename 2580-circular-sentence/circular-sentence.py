class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        l = sentence.split(' ')
        for i in range(len(l)-1):
            if(l[i][-1] != l[i+1][0]):
                return False
        if(l[-1][-1] != l[0][0]):
            return False
        return True