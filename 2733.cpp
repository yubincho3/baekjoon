#include <bits/stdc++.h>
using byte = unsigned char;
using namespace std;

stack<int> lbracket;
map<int, int> lpair;
map<int, int> rpair;
string result;
byte mem[32769];
byte *ptr = mem;
int idx;

string cmd, input;
int t;

void Execute(void)
{
	do
	{
		switch (cmd[idx])
		{
			case '>':
				if (ptr == mem + 32767)
					ptr = mem;
				else
					ptr++;
				break;
			case '<':
				if (ptr == mem)
					ptr += 32767;
				else
					ptr--;
				break;
			case '+':
				++*ptr;
				break;
			case '-':
				--*ptr;
				break;
			case '.':
				result.push_back(*ptr);
				break;
			case '[':
				if (*ptr == 0)
					idx = lpair[idx];
				break;
			case ']':
				if (*ptr != 0)
					idx = rpair[idx];
				break;
		}
	} while (cmd[++idx]);
}

void Initialize(void)
{
	memset(mem, 0, sizeof(mem));
	lpair.clear();
	rpair.clear();
	result.clear();
	cmd.clear();
	ptr = mem;
	idx = 0;
}

int main(void)
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	cin >> t;
	cin.ignore();
	
	for (int i = 1; i <= t; i++)
	{
		while (true)
		{
			getline(cin, input);
			
			if (input == "end")
				break;
			
			size_t finded = input.find("%");
			if (finded != string::npos)
				cmd += input.substr(0, finded);
			else
				cmd += input;
		}
		
		int cnt = 0;
		for (int i = 0; i < cmd.length(); i++)
		{
			if (cmd[i] == '[')
				cnt++;
			else if(cmd[i] == ']')
				cnt--;
		}
		
		if (cnt == 0)
		{
			for (int i = 0; i < cmd.length(); i++)
			{
				if (cmd[i] == '[')
					lbracket.push(i);
				else if (cmd[i] == ']')
				{
					int left = lbracket.top();
					lbracket.pop();
					
					lpair.insert({left, i});
					rpair.insert({i, left});
				}
			}
			
			Execute();
		}
		else
			result = "COMPILE ERROR";
				
		printf("PROGRAM #%d:\n", i);
		printf("%s\n", result.c_str());
		Initialize();
	}
	
	return 0;
}

