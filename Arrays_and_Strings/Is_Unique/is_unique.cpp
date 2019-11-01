// 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?
// Hints: #44, #7 7 7, #732

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

bool is_unique_char_vector(const string &str)
{
	if(str.length() > 128)
		return false;
	else
	{
		vector<int> char_set(128);
		for(int i = 0; i<str.length(); i++)
		{
			int index = str[i];
			if(char_set[index])
				return false;
			char_set[index] = true;
		}
		return true;
	}
}

bool is_unique_char_bitset(const string &word)
{
	bitset<256> bits(0);

	for(int i = 0; i<word.length(); i++)
	{
		int val = word[i];
		if(bits.test(val))
			return false;
		bits.set(val);
	}
	return true;
}

bool is_unique_char_set(const string &word)
{
	if(word.length() > 128)
		return false;
	else
	{
		set<char> charSet;
		for(int i = 0; i< word.length(); i++)
		{
			bool is_in = ( charSet.find(word[i]) != charSet.end() );
			if(is_in) return false;
			charSet.insert(word[i]);
		}
		return true;
	}
}

bool is_unique_char_NoDS_NLogN(const string &word)
{
	string str = word;
	sort(str.begin(), str.end());
	for(int i = 0; i<str.length(); i++)
	{
		if(str[i] == str[i+1])
			return false;
	}
	return true;
}

int main()
{
	string word = "apple";
	cout << "String : " << word <<" - is unique :"<< boolalpha << is_unique_char_NoDS_NLogN(word);
    return 0;
}
