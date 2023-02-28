#include <bits/stdc++.h>
using namespace std;

bool mtrx[751][751];
int arr[1501];
int n;

vector<int> solve()
{
    for (int r = 0; r < n; r++)
        for (int c = 0; c <= n; c++)
            mtrx[r][c] = arr[r + c];

    vector<int> s(n, -1);

    for (int r = 0, idx = 0; r < n; r++)
    {
        bool isTrueExist = false;

        for (int i = r; i <= n; i++)
        {
            if (mtrx[i][r])
            {
                if (i != r)
                    swap(mtrx[i], mtrx[r]);

                isTrueExist = true;
                break;
            }
        }

        if (!isTrueExist)
            continue;

        for (int i = idx + 1; i < n; i++)
            if (mtrx[i][r])
                for (int c = idx; c <= n; c++)
                    mtrx[i][c] ^= mtrx[r][c];

        s[r] = idx++;
    }

    vector<int> ret;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == -1)
            s[i] = 0;
        else
        {
            bool si = mtrx[s[i]][n];

            for (int c = i + 1; c < n; c++)
                si ^= mtrx[s[i]][c] * s[c];

            if (si && !mtrx[s[i]][i])
                return {-1};

            s[i] = si;
        }

        ret.push_back(s[i]);
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", &arr[i]);

    for (int t: solve())
        printf("%d ", t);

    return 0;
}
