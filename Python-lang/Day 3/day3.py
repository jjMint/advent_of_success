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
    for r in range(0,len(input)): #Iterate through each row
        sumtracker[c] += int(input[r][c])

for i in sumtracker:
    if i > len(input)/2:
        gamma.append('1')
        epsilon.append('0')
    else:
        gamma.append('0')
        epsilon.append('1')
   

gammastr = ''.join(gamma)
epsilonstr = ''.join(epsilon)

gammavalue = int(gammastr,2)
epsilonvalue = int(epsilonstr,2)

power = gammavalue * epsilonvalue
print(power)