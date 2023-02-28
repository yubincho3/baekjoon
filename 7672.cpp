#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<>> mnq;
priority_queue<int> mxq;
map<int, int> mp;
int t, k, n;
char c;

int main()
{
    for (scanf("%d", &t); t--;)
    {
        for (scanf("%d", &k); k--;)
        {
            scanf(" %c %d", &c, &n);

            if (c == 'I')
            {
                mnq.push(n);
                mxq.push(n);

                if (mp.count(n) == 0)
                    mp[n] = 0;

                mp[n]++;
            }
            else if (n == 1)
            {
                while (!mxq.empty() && !mp[mxq.top()])
                    mxq.pop();

                if (!mxq.empty())
                {
                    mp[mxq.top()]--;
                    mxq.pop();
                }
            }
            else
            {
                while (!mnq.empty() && !mp[mnq.top()])
                    mnq.pop();

                if (!mnq.empty())
                {
                    mp[mnq.top()]--;
                    mnq.pop();
                }
            }
        }

        while (!mxq.empty() && !mp[mxq.top()])
            mxq.pop();

        while (!mnq.empty() && !mp[mnq.top()])
            mnq.pop();

        if (mnq.empty() || mxq.empty())
            printf("EMPTY\n");
        else
            printf("%d %d\n", mxq.top(), mnq.top());

        while (!mxq.empty())
            mxq.pop();
        while (!mnq.empty())
            mnq.pop();
        mp.clear();
    }

    return 0;
}
