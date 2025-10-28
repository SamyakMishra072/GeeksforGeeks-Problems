# Palindrome Number (Easy)

Given an integer `x`, determine whether it is a palindrome without converting the number to a string.

A number is a palindrome if it reads the same forward and backward.

## Function Signature
```
bool isPalindromeNumber(long long x)
```

Returns `true` if `x` is a palindrome, otherwise `false`.

## Notes
- Negative numbers are not considered palindromes.
- Avoid string conversion; use arithmetic reversal.
- Includes overflow guard when reversing.
