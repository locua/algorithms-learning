array = []

with open("lab18-words.txt", 'r') as ins:
    i = 0
    for line in ins:
        if i == 0:
            print(line)
        array.append(line[0:3])
        i += 1
        if i == 59995:
            break;

aIn = []
for i in range(len(array)):
    if not array[i] in aIn:
        aIn.append(array[i])

print(len(aIn))
