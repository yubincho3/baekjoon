#include <bits/stdc++.h>
using namespace std;

string text, pattern;
vector<int> table;
int l, j;

int main(void)
{
	cin >> l >> text;
	pattern = text;
	table.resize(l + 1, 0);
	
	for (int i = 1; i < l; i++)
	{
		while (j > 0 && pattern[j] != text[i])
			j = table[j - 1];
		
		if (pattern[j] == text[i])
			table[i] = ++j;
	}
    
    printf("%d\n", l - table[l - 1]);
	
	return 0;
}

