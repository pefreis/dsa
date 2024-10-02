def _merge(left: list, right: list) -> list:
    merged = []
    
    l, r = 0, 0
    while l < len(left) or r < len(right):
        if l == len(left):
            merged.append(right[r])
            r += 1
            continue

        if r == len(right):
            merged.append(left[l])
            l += 1
            continue

        if left[l] < right[r]:
            merged.append(left[l])
            l += 1
            continue

        merged.append(right[r])
        r += 1

    return merged



def merge_sort(arr: list) -> list:
    n = len(arr)
    if n == 1:
        return arr
    
    a = merge_sort(arr[:int(n/2)])
    b = merge_sort(arr[int(n/2):])

    return _merge(a, b)
