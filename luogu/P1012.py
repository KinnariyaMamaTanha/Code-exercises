n = int(input())
nums = []
for i in range(0, n):
    nums.append(input())
for i in range(0, n - 1):
    j = i + 1
    tmp = nums[j]
    while j > 0 and int(nums[j - 1] + tmp) < int(tmp + nums[j - 1]):
        nums[j] = nums[j - 1]
        j -= 1
    nums[j] = tmp 
for i in range(0, n):
    print(nums[i], end = '')