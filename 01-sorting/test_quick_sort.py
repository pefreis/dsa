from quick_sort import *

def test_quick_sort():
    assert quick_sort([]) == []
    assert quick_sort([1]) == [1]
    assert quick_sort([15,-5,24,98,0,-63,1250]) == [-63,-5,0,15,24,98,1250]
    assert quick_sort([15,-5,24,98,0,-63]) == [-63,-5,0,15,24,98]

def test_basic_quick_sort():
    assert basic_quick_sort([15,-5,24,98,0,-63,1250]) == [-63,-5,0,15,24,98,1250]
    assert basic_quick_sort([15,-5,24,98,0,-63]) == [-63,-5,0,15,24,98]