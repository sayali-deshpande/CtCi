// Palindrome Permutation: Given a string, write a function to check if it is a permutation of
// a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
// permutation is a rearrangement of letters. The palindrome does not need to be limited to just
// dictionary words.
// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat'; "atc o eta·; etc.)
// Time complexity: 0(n) n = length of string

#include <iostream>
#include <string>

using namespace std;

int getCharIndex(char c)
{
    int index = -1;
    if( c >= 'a' && c <= 'z')
        index = c - 'a';
    else if(c >= 'A' && c <= 'Z')
        index = c - 'A';
    return index;
}

bool isPalindrome1(const string &str)
{
    int frequency[26] = {0};
    int oddCount = 0;
    
    for(auto c: str)
    {
        int idx = getCharIndex(c);
        if(idx != -1)
        {
            ++frequency[idx];
            if(frequency[idx] % 2 == 1)
                ++oddCount;
            else 
                --oddCount;
        }
    }
    
    return (oddCount <= 1);
}

int toggle(int bitVector, int idx)
{
    if(idx < 0)
        return bitVector;
        
    int mask = 1 << idx;
    
    if((bitVector & mask) == 0)
        bitVector |= mask;
    else
        bitVector &= ~mask;
        
    return bitVector;
}

bool isExactlyOneBitSet(int bitVector)
{
    return (bitVector & (bitVector - 1) == 0);    
}

bool isPalindrome2(const string &str)
{
    int bitVector = 0;
    int index = 0;
    for(auto c : str)
    {
        index = getCharIndex(c);
        bitVector = toggle(bitVector, index);
    }
    return ((bitVector == 0) || isExactlyOneBitSet(bitVector));
}

int main()
{
    string str = "aabbccd";
    cout << endl << "is " << str << " palindrome - " << boolalpha << isPalindrome1(str);
    
    cout << endl << "Using another approach";
    string str1 = "A big Cat";
    cout << endl << "is " << str1 << " palindrome - " << boolalpha << isPalindrome2(str1);
    return 0;
}
