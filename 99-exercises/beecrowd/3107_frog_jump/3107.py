def min_ignore_none(a: int|None, b: int|None) -> int|None:
    if a is None:
        return b
    if b is None:
        return a
    return min(a, b)

def solve(rocks: list[int], goal: int, small: int, long: int) -> int:
    memo = dict()
    memo[1] = {'s': 0, 'l': 0}
    
    pos = rocks + [goal]
    for p in pos:
        s = None
        l = None
        for j in range(1, long+1):
            if p-j not in memo:
                continue

            if j <= small:
                s = min_ignore_none(s, memo[p-j]['s'])
                s = min_ignore_none(s, memo[p-j]['l'])
            else:
                l = min_ignore_none(l, memo[p-j]['s'])

        s = 1 + s if s is not None else None
        l = 1 + l if l is not None else None
        if s or l:
            memo[p] = {'s': s, 'l': l}
    
    return min_ignore_none(memo[goal]['s'], memo[goal]['l']) if goal in memo else -1


while True:
    try:
        inp1 = input()
        if inp1 == '': break

        _, m = map(int, inp1.split(' '))

        rocks = []
        inp2 = input()
        if inp2 != '':
            rocks = list(map(int, inp2.split(' ')))

        small, long = map(int, input().split(' '))

        res = solve(rocks, m, small, long)
        print(res)

    except EOFError:
        break