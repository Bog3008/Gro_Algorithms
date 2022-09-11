def binary_search(arr, item):
    high = len(arr) - 1
    low = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] == item:
            return mid
        if arr[mid] < item:
            low = mid + 1
        else:
            high = mid - 1
    return None

list = [1, 3, 6, 8, 9, 90]

print( binary_search(list, 9) )
