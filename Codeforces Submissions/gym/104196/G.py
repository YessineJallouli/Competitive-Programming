s = input().replace(' ', '')
op = '+'
if op not in s:
    op = '*'
s = s.split("=")
arr = [*s[0].split(op), s[1]]
for i in range(1, len(arr[0])):
    for j in range(1, len(arr[1])):
        exp = arr[1][:j] + arr[0][i:] + " " + op + " " + arr[0][:i] + arr[1][j:]
        res = arr[2]
        try:
            if eval(exp) == int(res):
                print(exp + " = " + res)
                exit()
        except:
            pass

for i in range(1, len(arr[0])):
    for j in range(1, len(arr[2])):
        exp = arr[2][:j] + arr[0][i:] + " " + op + " " + arr[1]
        res = arr[0][:i] + arr[2][j:]
        try:
            if eval(exp) == int(res):
                print(exp + " = " + res)
                exit()
        except:
            pass

for i in range(1, len(arr[1])):
    for j in range(1, len(arr[2])):
        exp = arr[0] + " " + op + " " + arr[2][:j] + arr[1][i:]
        res = arr[1][:i] + arr[2][j:]
        try:
            if eval(exp) == int(res):
                print(exp + " = " + res)
                exit()
        except:
            pass