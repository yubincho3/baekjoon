#include <bits/stdc++.h>
using namespace std;

int pr[1001];
int in[1001];
int t, n;

void getPostOrder(int root, int s, int e, vector<int> &v)
{
    for (int i = s; i < e; i++)
    {
        if (in[i] == pr[root])
        {
            getPostOrder(root + 1, s, i, v);
            getPostOrder(root - s + i + 1, i + 1, e, v);
            v.push_back(pr[root]);
        }
    }
}

vector<int> solve()
{
    vector<int> ret;

    getPostOrder(0, 0, n, ret);

    return ret;
}

int main()
{
    for (scanf("%d", &t); t--;)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &pr[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &in[i]);

        for (int i: solve())
            printf("%d ", i);
        printf("\n");
    }

    return 0;
}
