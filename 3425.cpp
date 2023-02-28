#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

vector<pair<int, int>> cmds;
char str[5];
int t, n;

pair<int, int> parse(string s)
{
	pair<int, int> ret;
	
	if (s == "NUM")
	{
		scanf("%d", &n);
		ret = {0, n};
	}
	else if (s == "POP")
		ret = {1, 0};
	else if (s == "INV")
		ret = {2, 0};
	else if (s == "DUP")
		ret = {3, 0};
	else if (s == "SWP")
		ret = {4, 0};
	else if (s == "ADD")
		ret = {5, 0};
	else if (s == "SUB")
		ret = {6, 0};
	else if (s == "MUL")
		ret = {7, 0};
	else if (s == "DIV")
		ret = {8, 0};
	else
		ret = {9, 0};
	
	return ret;
}

long long Execute(int top)
{
	stack<long long> stk;
	
	stk.push(top);
	
	for (auto& p : cmds)
	{
		if (stk.size() && abs(stk.top()) > MAX)
			return MAX + 1;
		
		long long temp1, temp2;
		
		switch (p.first)
		{
			case 0:
				stk.push(p.second);
				break;
			case 1:
				if (stk.empty())
					return MAX + 1;
				stk.pop();
				break;
			case 2:
				if (stk.empty())
					return MAX + 1;
				stk.top() = -stk.top();
				break;
			case 3:
				if (stk.empty())
					return MAX + 1;
				stk.push(stk.top());
				break;
			case 4:
				if (stk.size() < 2)
					return MAX + 1;
				
				temp1 = stk.top();
				stk.pop();
				temp2 = stk.top();
				stk.pop();
				
				stk.push(temp1);
				stk.push(temp2);
				break;
			case 5:
				if (stk.size() < 2)
					return MAX + 1;
				
				temp1 = stk.top();
				stk.pop();
				
				stk.top() += temp1;
				break;
			case 6:
				if (stk.size() < 2)
					return MAX + 1;
				
				temp1 = stk.top();
				stk.pop();
				
				stk.top() -= temp1;
				break;
			case 7:
				if (stk.size() < 2)
					return MAX + 1;
				
				temp1 = stk.top();
				stk.pop();
				
				stk.top() *= temp1;
				break;
			case 8:
				if (stk.size() < 2 || !stk.top())
					return MAX + 1;
				
				temp1 = stk.top();
				stk.pop();
				
				stk.top() /= temp1;
				break;
			case 9:
				if (stk.size() < 2 || !stk.top())
					return MAX + 1;
				
				temp1 = stk.top();
				stk.pop();
				
				stk.top() %= temp1;
				break;
		}
	}
	
	if (stk.size() != 1 || abs(stk.top()) > MAX)
		return MAX + 1;
	else
		return stk.top();
}

int main(void)
{
	while (true)
	{
		while (true)
		{
			scanf("%s", str);
			
			if (!strcmp(str, "QUIT"))
				return 0;
			if (!strcmp(str, "END"))
				break;
			cmds.push_back(parse(str));
		}
		
		for (scanf("%d", &t); t--;)
		{
			scanf("%d", &n);
			
			long long ans = Execute(n);
			printf(abs(ans) > MAX ? "ERROR\n" : "%d\n", ans);
		}
		
		printf("\n");
		cmds.clear();
	}
}

