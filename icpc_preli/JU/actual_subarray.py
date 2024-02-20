def min_deleted_subarray_length(A, B):
    n = len(A)
    start, end = 0, n - 1

    # Find the first mismatch from the beginning
    while start < n and A[start] == B[start]:
        start += 1

    # Find the first mismatch from the end
    while end >= 0 and A[end] == B[end]:
        end -= 1

    # Calculate the minimum length of the deleted subarray
    min_length = max(0, end - start)

    return min_length


print(min_deleted_subarray_length([3, 5, 7], [1, 7, 9]))
