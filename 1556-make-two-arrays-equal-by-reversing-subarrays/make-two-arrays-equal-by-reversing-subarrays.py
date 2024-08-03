class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        for i in target:
            if target.count(i) != arr.count(i):
                return False
        return True