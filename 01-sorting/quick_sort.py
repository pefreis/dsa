def quick_sort(arr: list) -> list:
    if len(arr) <= 1:
        return arr

    l, e, g = [], [], []
    
    pivot = arr[0]
    for n in arr:
        if n < pivot:
            l.append(n)
        elif n == pivot:
            e.append(n)
        else:
            g.append(n)

    return quick_sort(l) + e + quick_sort(g)
