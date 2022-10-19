N = int(input())

nums = set()
arr = []
dic = {}
for e in map(int, input().split()):
    arr.append(e)
    if e not in nums:
        nums.add(e)
nums = sorted(list(nums))
for i in range(len(nums)):
    dic[nums[i]] = i
for j in range(len(arr)):
    if j == len(arr)-1:
        print(dic[arr[j]])
    else:
        print(dic[arr[j]], end=' ')

