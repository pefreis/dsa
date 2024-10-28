def search(arr: list, val: int) -> tuple[int, bool]:
    if len(arr) == 0:
        return 0, False

    if len(arr) == 1:
        if val == arr[0]:
            return 0, True
        if val < arr[0]:
            return 0, False
        return 1, False

    l, r = 0, len(arr)-1
    while l < r:
        m = l + int((r-l)/2)
        if val == arr[m]:
            return m, True
        if val < arr[m]:
            r = m
        else:
            l = m + 1
    
    if val == arr[l]:
        return l, True
    
    if val < arr[l]:
        return l, False
    
    return l + 1, False
