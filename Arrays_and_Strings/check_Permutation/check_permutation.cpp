// 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.
// Hints: #7, #84, #722, #737

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check_permutation(string str1, string str2) //using sort
{
	if(str1.length() != str2.length())
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	for(int i = 0; i< str1.length(); i++)
	{
		if(str1[i] != str2[i])
			return false;
	}
	return true;
}

bool check_permutation2(const string &str1, const string &str2) //using count
{
	if(str1.length() != str2.length())
		return false;
	
	int count[256] = {0};
	for(int i=0; i<str1.length(); i++)
	{
		int val = str1[i];
		count[val]++;
	}
	
	for(int j=0; j < str2.length(); j++)
	{
		int val = str2[j];
		count[val]--;
		if(count[val] < 0)
			return false;
	}
	return true;
}

int main()
{
	string str1 = "hello";
    string str2 = "oellh";
	
	if(check_permutation(str1,str2))
		cout << endl << str1 <<" and " << str2 << " are permutations of each other.";
	else
		cout << endl << str1 <<" and " << str2 << " are not permutations of each other.";
	
	str1 = "testest";
    str2 = "estxest";
	
	if(check_permutation(str1,str2))
		cout << endl << str1 <<" and " << str2 << " are permutations of each other.";
	else
		cout << endl << str1 <<" and " << str2 << " are not permutations of each other.";
	
	cout << endl << "Method 2 - Using character count";
    str1 = "testest";
    str2 = "estxest";
    if(check_permutation2(str1, str2))
      cout << endl << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << endl << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if(check_permutation2(str1, str2))
      cout << endl << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << endl << str1 <<" and " << str2 << " are not permutation of each other" << endl;
	
	return 0;
	
}