#include<iostream>
#include<string>
#include <unordered_set>
using namespace std;

int function(string s)
{
	if (s.size() == 0)
	{
		return 0;
	}
	unordered_set<char> lookup;
	int maxStr = 0;
	int left = 0;
	for (int i = 0; i < s.size(); i++) {
		while (lookup.find(s[i]) != lookup.end()) {
			lookup.erase(s[left]);
			left++;
		}
		maxStr = max(maxStr, i - left + 1);
		lookup.insert(s[i]);
	}
	return maxStr;

}

int main()
{
	string s = "qwewklsd";
	cout<<function(s);
}