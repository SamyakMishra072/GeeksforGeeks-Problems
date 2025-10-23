from typing import List
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        result=0          # Stores the maximum number of fruits we can collect
        f1,f2=-1,-1       # Represents the two types of fruits in our baskets
        count1,count2=0,0
        prev=0
        for f in fruits:
            if f==f1:     #Same fruit as f1 → extend current streak
                count1+=1
                prev+=1
            elif f==f2:   #Same fruit as f2 → swap f1 and f2, extend current streak
                f1,f2=f2,f1
                count1,count2=count2+1,count1
                prev=1
            else:         #New fruit type → update result and reset counts
                result = max(result, count1 + count2)
                f1,f2=f,f1     # Update fruit types
                count1,count2=1,prev
                prev=1
        return max(result,count1+count2)