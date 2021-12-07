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

input02 = input.copy()
inputc02 = input.copy()
for c in range(0,len(input02[0])): #iterate through each column
    i=0
    sumtracker = 0 #reset sumtracker for each column
    for r in range(0,len(input02)): #Iterate through each row count number of occurances of '1'
        sumtracker += int(input02[r][c])

    if sumtracker >= len(input02)/2: #check if '1' is most common value at specific column
        for r in range(0,len(input02)): #iterate through rows and delete rows without '1' at specific column
            if r-i > len(input02)-1 or len(input02)==1:
                break
            if input02[r-i][c] != '1':
                del input02[r-i]
                i += 1
    else:     
        for r in range(0,len(input02)): #iterate through rows and delte rows without '0' at specific column
            if r-i > len(input02)-1 or len(input02)==1:
                break
            if input02[r-i][c] != '0':
                del input02[r-i]
                i += 1



for c in range(0,len(inputc02[0])): #iterate through each column
    i=0
    sumtracker = 0 #reset sumtracker for each column
    for r in range(0,len(inputc02)): #Iterate through each row count number of occurances of '1'
        sumtracker += int(inputc02[r][c])

    if sumtracker >= len(inputc02)/2: #check if '1' is most common value at specific column
        for r in range(0,len(inputc02)): #iterate through rows and delete rows without '1' at specific column
            if r-i > len(inputc02)-1 or len(inputc02)==1:
                break
            if inputc02[r-i][c] != '0':
                del inputc02[r-i]
                i += 1
    else:     
        for r in range(0,len(inputc02)): #iterate through rows and delte rows without '0' at specific column
            if r-i > len(inputc02)-1 or len(inputc02)==1:
                break
            if inputc02[r-i][c] != '1':
                del inputc02[r-i]
                i += 1

print(input02)
print(inputc02)


lifesupport = int(input02[0],2) * int(inputc02[0],2)
print(lifesupport)