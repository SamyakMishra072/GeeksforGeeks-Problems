# Armstrong Number (Basic)

Given an integer `n`, determine whether it is an Armstrong number.

An Armstrong number of order `k` is a number that is equal to the sum of its digits each raised to the power `k`.

Examples:
- 153 -> 1^3 + 5^3 + 3^3 = 153 (Armstrong)
- 370 -> 3^3 + 7^3 + 0^3 = 370 (Armstrong)
- 123 -> 1^3 + 2^3 + 3^3 = 36 (Not Armstrong)

## Function Signature
```
bool isArmstrong(int n)
```

Returns `true` if `n` is an Armstrong number, otherwise `false`.

## Notes
- Works for non-negative integers.
- Time complexity: O(d), where d is the number of digits.
