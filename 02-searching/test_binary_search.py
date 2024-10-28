from binary_search import *

def test_binary_search():
    test_cases = [
        {"arr": [], "val": 5, "expected": (0, False)},
        {"arr": [5], "val": 5, "expected": (0, True)},
        {"arr": [5], "val": 3, "expected": (0, False)},
        {"arr": [5], "val": 6, "expected": (1, False)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 5, "expected": (0, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 7, "expected": (1, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 13, "expected": (2, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 17, "expected": (3, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 19, "expected": (4, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 23, "expected": (5, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 29, "expected": (6, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 31, "expected": (7, True)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 18, "expected": (4, False)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": 32, "expected": (8, False)},
        {"arr": [5, 7, 13, 17, 19, 23, 29, 31], "val": -1, "expected": (0, False)},
    ]
    
    for tc in test_cases:
        assert(search(tc["arr"], tc["val"]) == tc["expected"])