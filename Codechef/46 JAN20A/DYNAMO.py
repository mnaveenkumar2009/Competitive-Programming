import math
t = int(input())
for i in range(t):
	n = int(input())
	print(int(2 * math.pow(10, n)) + int(input()), flush=True)
	print(int(math.pow(10, n)) - int(input()), flush=True)
	print(int(math.pow(10, n)) - int(input()), flush=True)
	input()