from io import StringIO

ORD_A = ord('A')

def solve(s):
    cnt = [0] * 26

    for c in s:
        cnt[ord(c) - ORD_A] += 1

    with StringIO() as ans:
        remained = ''

        for i in range(26):
            q, r = divmod(cnt[i], 2)

            if r != 0 and remained:
                return "I'm Sorry Hansoo"

            ans.write(chr(ORD_A + i) * q)
            remained = chr(ORD_A + i) if r else remained

        temp = ans.getvalue()[::-1]
        ans.write(remained)
        ans.write(temp)

        return ans.getvalue()

print(solve(input()))
