from numpy.random import randint

def _pick_pivot(arr: list, start_idx: int, end_idx: int) -> int:
    return randint(start_idx, end_idx+1)

def _lomuto_partition(arr: list, start_idx: int, end_idx: int, pivot_idx: int) -> tuple[int, list]:
    pivot = arr[pivot_idx]
    arr[pivot_idx], arr[end_idx] = arr[end_idx], arr[pivot_idx]
    
    i = start_idx - 1
    for j in range(start_idx, end_idx):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    i += 1
    arr[i], arr[end_idx] = arr[end_idx], arr[i]
    return i, arr

def _partition(arr: list, start_idx: int, end_idx: int, pivot_idx: int) -> tuple[int, list]:
    return _lomuto_partition(arr, start_idx, end_idx, pivot_idx)

def _sort(arr: list, start_idx: int, end_idx: int) -> list:
    if start_idx >= end_idx:
        return arr
    
    p = _pick_pivot(arr, start_idx, end_idx)
    p, arr = _partition(arr, start_idx, end_idx, p)

    arr = _sort(arr, start_idx, p-1)
    arr = _sort(arr, p+1, end_idx)

    return arr

def quick_sort(arr: list) -> list:
    return _sort(arr, 0, len(arr)-1)

def basic_quick_sort(arr: list) -> list:
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

    return basic_quick_sort(l) + e + basic_quick_sort(g)
