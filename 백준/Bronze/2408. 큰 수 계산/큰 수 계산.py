import sys
n = int(sys.stdin.readline())
expression = []
for _ in range(2 * n - 1):
    expression.append(sys.stdin.readline().strip())
full_expr = "".join(expression).replace("/", "//")
print(eval(full_expr))