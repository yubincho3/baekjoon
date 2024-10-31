#include <bits/stdc++.h>
#define MAX_ITER ((int)(5e+7))
using namespace std;

uint8_t mem[100001];
char code[4097];
char buf[4097];
int jmp[4097];
int minCur, maxCur;
int t, m, c, i;
uint8_t *mptr = mem;
char *iptr = buf;

int parse(int index)
{
    if (index > c)
        return -1;

    if (code[index] == ']')
        return index;

    if (code[index] == '[')
    {
        const int close = parse(index + 1);
        jmp[index] = close;
        jmp[close] = index;
        index = close;
    }

    return parse(index + 1);
}

bool execute(int &cur)
{
    int iter = 0;

    while (cur < c)
    {
        if (iter++ == MAX_ITER)
            return true;

        switch (code[cur])
        {
            case '-':
                --*mptr;
                break;
            case '+':
                ++*mptr;
                break;
            case '<':
                if (--mptr < mem)
                    mptr += m;
                break;
            case '>':
                if (++mptr >= mem + m)
                    mptr = mem;
                break;
            case '[':
                *mptr || (cur = jmp[cur]);
                break;
            case ']':
                *mptr && (cur = jmp[cur]);
                break;
            case ',':
                // Hmm...
                *mptr = iptr < buf + i ? *iptr++ : ~0;
                break;
        }

        minCur = min(minCur, ++cur);
        maxCur = max(maxCur, cur);
    }

    return false;
}

int main()
{
    for (scanf("%d", &t); t--;)
    {
        memset(mem, 0, sizeof mem);
        mptr = mem;
        iptr = buf;
        
        cin >> m >> c >> i;
        cin >> code >> buf;
        parse(0);

        int cur = 0;

        if (execute(cur))
        {
            minCur = maxCur = cur;

            execute(cur);

            if (cur < c)
            {
                printf("Loops %d %d\n", minCur - 1, maxCur);
                continue;
            }
        }

        printf("Terminates\n");
    }

    return 0;
}
