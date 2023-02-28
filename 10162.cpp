#include <bits/stdc++.h>
using namespace std;

int t;

int main(void)
{
	scanf("%d", &t);
	if (t % 10 == 0)
		printf("%d %d %d", t / 300, (t % 300 / 60), (t % 300 % 60 / 10));
	else
		printf("-1");
	
	return 0;
}

