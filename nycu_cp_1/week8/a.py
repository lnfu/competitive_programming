def judge(n):
    for i in ['+', '-', '*', '//']:
        for j in ['+', '-', '*', '//']:
            for k in ['+', '-', '*', '//']:
                s = '4 ' + i + ' 4 ' + j + ' 4 ' + k + ' 4'
                if (eval(s)) == n:
                    print(s.replace('//', '/') + ' = ' + str(int(n)))
                    return
    print("no solution")
    return

m = int(input())
for t in range(m):
    n = float(input())
    judge(n)
