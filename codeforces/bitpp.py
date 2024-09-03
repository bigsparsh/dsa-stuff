statements = []
value = 0
for i in range(int(input())):
    statements.append(input())
    if statements[i][0] == 'X':
        if statements[i][1] == '+' and statements[i][2] == "+":
            value += 1
        if statements[i][1] == '-' and statements[i][2] == "-":
            value -= 1
    else:
        if statements[i][0] == '+' and statements[i][1] == "+":
            value += 1
        if statements[i][0] == '-' and statements[i][1] == "-":
            value -= 1
print(value)
