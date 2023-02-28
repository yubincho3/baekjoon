#include <bits/stdc++.h>
using namespace std;

struct Node
{
    unique_ptr<Node> next[11] = {};
    bool isEnd = false;
};

string str[10001];
char in[11];
int t, n;

string solve()
{
    Node root;

    sort(str, str + n, [](string &a, string &b) -> bool
    {
        return a.length() < b.length();
    });

    for (int i = 0; i < n; i++)
    {
        Node *now = &root;

        for (int j = 0; j < str[i].length(); j++)
        {
            auto &tar = now->next[str[i][j] - '0'];

            if (tar == nullptr)
            {
                tar = make_unique<Node>();
                tar->isEnd = j == str[i].length() - 1;
            }
            else if (tar->isEnd)
                return "NO";

            now = tar.get();
        }
    }

    return "YES";
}

int main()
{
    for (scanf("%d", &t); t--;)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf(" %s", in);
            str[i] = in;
        }

        printf("%s\n", solve().c_str());
    }

    return 0;
}
