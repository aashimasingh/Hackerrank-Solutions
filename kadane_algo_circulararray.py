def kadane (arr) :
    n = len(arr)
    max_ending_here = 0
    max_so_far = 0
    for i in range(n) :
        max_ending_here = max_ending_here + arr[i]
        if (max_ending_here < 0):
            max_ending_here = 0
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here
    
    return max_so_far

def maxMoney(arr,n):
    ##Your code here
    first_case = kadane(arr)
    arr_sum = 0
    for i in range(n) :
        arr_sum += arr[i]
        arr[i] = -arr[i]
    
    arr_sum = arr_sum + kadane(arr)
    if first_case > arr_sum:
        return first_case
    else:
        return arr_sum

