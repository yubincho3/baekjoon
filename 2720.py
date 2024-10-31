for c in [*map(int, open(0))][1:]:
    q, c = divmod(c, 25)
    d, c = divmod(c, 10)
    n, p = divmod(c, 5)
    print(q, d, n, p)
