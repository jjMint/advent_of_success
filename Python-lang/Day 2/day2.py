data = open('input_2.txt', mode='r').readlines()

direction = []
distance = []
for i in data:
    direction.append(i.split()[0])
    distance.append(int(i.split()[1]))
 


x = 0 #horizontal position
y = 0 #vertical positon (positive is downwards travel)

for i in range (0, len(direction)):
    
    if direction[i] == 'forward':
        x += distance[i]
    elif direction[i] == 'up':
        y -= distance[i]
    elif direction[i] == 'down':
        y += distance [i]

print(x*y)