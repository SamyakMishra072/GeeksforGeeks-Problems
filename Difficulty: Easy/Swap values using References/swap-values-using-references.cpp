// Function to swap A and B
// using reference
void swap(int &a, int &b) {
    a=a^b;
    b=a^b;
    a=a^b;
}