def solve(targets: list[int]):
    edges = []
    memo = {}
    for s, t in enumerate(targets, 1):
        ok = solve_subproblem(s, t, edges, memo, -1)
        if not ok:
            return 'No solution'

    res = f"{len(edges)} {' '.join([str(e) for e in reversed(edges)])}"
    return res

def solve_subproblem(s: int, t: int, edges: list[int], memo: dict[int: list[int]], prev_i: int):
    idxs = []
    if t-1 in memo:
        idxs += memo[t-1]
    if t in memo:
        idxs += memo[t]
    i = first_after_previous_or_none(prev_i, idxs)
    
    if i is None:
        if t < s:
            return False
        else:
            set_edges(s, t, edges, memo)
            return True
    else:
        if edges[i] == t-1:
            return solve_subproblem(s, t-1, edges, memo, i)
        elif edges[i] == t:
            return solve_subproblem(s, t+1, edges, memo, i)

def first_after_previous_or_none(prev: int, idxs: list[int]):
    res = None
    for i in idxs:
        if i > prev and (res is None or i < res):
            res = i
    return res

def set_edges(s: int, t: int, edges: list[int], memo: dict[int: int]):
    if t == s: return

    edges.append(t-1)

    idx = len(edges)-1
    if t-1 in memo:
        memo[t-1].append(idx)
    else:
        memo[t-1] = [idx]

    set_edges(s, t-1, edges, memo)

while True:
    inp = input()
    if int(inp[0]) == 0:
        break
    
    _, targets = inp.split(' ', 1)
    ts = [int(t) for t in targets.split(' ')]
    res = solve(ts)
    print(res)