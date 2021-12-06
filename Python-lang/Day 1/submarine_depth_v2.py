data = open('input_1.txt', mode='r').readlines()

depth = [int(i) for i in data]


count = -1
prev = 0

for x in list(range(0,len(depth))):
    if x>1:
        w = depth[x-2] + depth[x-1] + depth[x]
        print(w)
        if w>prev:
            count+=1
        prev = w

print(count)