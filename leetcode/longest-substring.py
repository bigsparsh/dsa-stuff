s = "pwwkew"
max = 0

for index, ch in enumerate(s): 
    cnt = 0
    lst = ""
    for ch2 in s[index:]:
        if ch2 not in lst:
            cnt = cnt + 1
            lst = lst + ch2
        else:
            break
    if (cnt > max):
        max = cnt

# return max
print(max)
