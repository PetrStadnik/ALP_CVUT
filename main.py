def over(v):
    x = 0
    for i in range(len(v)):
        if abs((v[:i] + [""] + v[i + 1:]).index(v[i]) - i) % 2 == 0:
            x = 1
    if x == 0:
        global newlist
        newlist.append(v)
        print(v)

def variace(p, arr):
    #print(str(p) + "--->" + str(arr))
    if 0 < len(arr):
        p += 1
        for i in range(len(arr)):
            s[p-2] = arr[i]
            variace(p, arr[:i]+arr[i+1:])

    else:
        global x
        x += 1
        #print(x)
        over(s)


if __name__ == '__main__':
    newlist = []
    x = 0
    chars = list(input())
    s = [""] * len(chars)
    variace(1, chars.copy())
    print(newlist)

