def f(arr1, arr2):
    l1 = len(arr1)
    l2 = len(arr2)

    num1 = 0
    num2 = 0

    for i in range(l1-1, -1, -1):
        num1 += arr1[i] * 10**i
    for i in range(l2-1, -1, -1):
        num2 += arr2[i] * 10**i

    ret = []
    num = str(num1 + num2)
    for i in range(len(num)-1, -1, -1):
        ret.append(num[i])
    
    return ret

arr1 = [9,9,9,9,9,9,9]
arr2 = [9,9,9,9]
print(f(arr1, arr2))