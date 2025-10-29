# Program to count vowels in a string
def count_vowels(s):
    vowels="aeiouAEIOU"  # Include both lowercase and uppercase vowels
    count=0
    for char in s:
        if char in vowels:
            count+=1
    return count

# Taking input from user
string_input=input("Enter a string: ")
vowel_count=count_vowels(string_input)
print("Number of vowels:",vowel_count)
