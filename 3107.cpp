#include <bits/stdc++.h>
using namespace std;

char str[33];
int group;

int main(void)
{
	scanf("%s", str);
	
	vector<string> parsed;
	stringstream ss(str);
	string temp;
	
	while (getline(ss, temp, ':'))
	{
		if (temp.empty() == false)
		{
			while (temp.size() < 4)
				temp = "0" + temp;
			
			group++;
		}
		
		parsed.push_back(temp);
	}
	
	vector<string> result;
	bool flag = false;
	
	for (const string& temp : parsed)
	{
		if (temp.empty())
		{
			if (flag == false)
			{
				for (int i = group; i < 8; i++)
					result.push_back("0000");
				
				flag = true;
			}
		}
		else
			result.push_back(temp);
	}
	
	for (int i = 0; i < 8; i++)
	{
		if (i > 0)
			printf(":");
		printf("%s", result[i].c_str());
	}
	
	return 0;
}

