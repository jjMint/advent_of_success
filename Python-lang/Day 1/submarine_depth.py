data = open('input_1.txt', mode='r').readlines()

depth = [int(i) for i in data]

count = -1
prev = 0
for x in depth:
    if x > prev:
        count += 1
    prev = x
print(count)