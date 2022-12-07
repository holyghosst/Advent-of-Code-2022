
file = open("AoC22\day6\input")

line = file.readline()

#first part
for i in range(len(line) - 4):
    l = list((line[i:i+4])) 
    s = set(l)
    if(len(s) == len(l)):
        print(l)
        print(i + 4)
        break

#second part
for i in range(len(line) - 14):
    l = list((line[i:i+14])) 
    s = set(l)
    if(len(s) == len(l)):
        print(l)
        print(i + 14)
        break