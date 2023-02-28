#include <bits/stdc++.h>
using namespace std;

struct Data
{
	int num;
	char c;
	bool isNum;
};

vector<Data> v;
char str[100001];
int n, b, x;

char solve(void)
{
	stack<int> stk;
	
	for (auto& data : v)
	{
		if (data.isNum)
			stk.push(data.num);
		else if (data.c == 'x')
			stk.push(x);
		else
		{
			int first = stk.top();
			stk.pop();
			int second = stk.top();
			stk.pop();
			
			if (data.c == '+')
				first += second;
			else if (data.c == '-')
				first -= second;
			else
				first *= second;
			
			stk.push(first);
		}
	}
	
	return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[stk.top() % b];
}

int main(void)
{
	scanf("%d %d %[^\n]", &b, &n, str);
	
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
			continue;
		
		if (str[i] == 'x' || str[i] == '+' || str[i] == '-' || str[i] == '*')
			v.push_back({0, str[i], false});
		else
		{
			string temp;
			
			while (i < len && str[i] != ' ')
				temp.push_back(str[i++]);
			
			v.push_back({strtol(temp.c_str(), NULL, b), 0, true});
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		printf("%c\n", solve());
	}
	
	return 0;
}

