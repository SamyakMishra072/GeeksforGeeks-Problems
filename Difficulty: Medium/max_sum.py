def max_sum_no_adjacent(nums):
    n=len(nums)
    
    if n==0:
        return 0
    if n==1:
        return nums[0]
    
    # Initializing DP array
    dp=[0]*n
    dp[0]=nums[0]
    dp[1]=max(nums[0],nums[1])
    
    # Filling DP array
    for i in range(2,n):
        dp[i]=max(dp[i-1],nums[i]+dp[i-2])

    return dp[-1]

nums=list(map(int,input("Enter the array of integers separated by space: ").split()))
result=max_sum_no_adjacent(nums)
print("Maximum sum of non-adjacent elements:", result)
