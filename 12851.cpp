#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

bool visit[MAX];
int n, k, s, c;

void bfs(void)
{
	queue<pair<int, int>> q;
	
	q.push({n, 0});
	
	while (!q.empty())
	{
		int now = q.front().first;
		int sec = q.front().second;
		q.pop();
		
		visit[now] = true;
		
		if (s && sec == s && now == k)
			c++;
		
		if (!s && now == k)
		{
			s = sec;
			c++;
		}
		
		if (now + 1 < MAX && !visit[now + 1])
			q.push(make_pair(now + 1, sec + 1));
		if (now - 1 >= 0 && !visit[now - 1])
			q.push(make_pair(now - 1, sec + 1));
		if (now * 2 < MAX && !visit[now * 2])
			q.push(make_pair(now * 2, sec + 1));
	}
}

int main(void)
{
	scanf("%d %d", &n, &k);
	
	bfs();
	printf("%d\n%d", s, c);
	
	return 0;
}

