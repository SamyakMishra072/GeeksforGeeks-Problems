# Merge Intervals (Medium)

Given an array of intervals where each interval is represented as `[start, end]`, merge all overlapping intervals and return the result.

## Function Signature
```
vector<vector<int>> merge(vector<vector<int>>& intervals)
```

## Approach
- Sort intervals by start time.
- Iterate and merge when current start <= last merged end.
- Otherwise, push a new interval.

## Complexity
- Time: O(n log n) for sorting, O(n) for merging.
- Space: O(n) for result.
