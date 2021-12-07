##Imports data as list of strings
data = open('input_3.txt', mode='r').readlines()

input = []
for i in range(1,len(data)):
    input.append(data[i].strip())

del data

sumtracker = 0
gamma = []
epsilon =[] 
sumtracker = [0] * len(input[0]) #frequency tracker for each position



for c in range(0,len(input[0])): #iterate through each column
    sumtracker = 0 #reset sumtracker for each column
    for r in range(0,len(input)): #Iterate through each row count number of occurances of '1'
        sumtracker += int(input[r][c])

    if sumtracker >= len(input)/2: #check if '1' is most common value at specific column
        print(c)
        for r in input: #iterate through rows and delete rows without '1' at specific column
            if r[c] != '1':
                input.remove(r)
    else:
        print(c)
        for r in input: #iterate through rows and delte rows without '0' at specific column
            if r[c] != '0':
                input.remove(r)

print(input)


