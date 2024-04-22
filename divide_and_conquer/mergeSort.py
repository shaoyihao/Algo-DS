INF = 0x3f3f3f3f

def merge(q, l, mid, r):
    arr1, arr2 = q[l: mid + 1], q[mid + 1: r + 1]
    arr1.append(INF), arr2.append(INF)

    i, j = 0, 0
    for k in range(l, r + 1):
        if arr1[i] <= arr2[j]:
            q[k] = arr1[i]
            i += 1
        else:
            q[k] = arr2[j]
            j += 1

def mergeSort(q, l, r):
    if l < r:
        mid = (l + r) // 2
        mergeSort(q, l, mid), mergeSort(q, mid + 1, r)
        merge(q, l, mid, r)


# if __name__ == "__main__":
#     n = int(input())
#     arr = [int(x) for x in input().split()]
# 
#     mergeSort(arr, 0, len(arr) - 1)
#     for x in arr: print(x, end=' ')
