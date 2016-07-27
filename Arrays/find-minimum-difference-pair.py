'http://www.geeksforgeeks.org/find-minimum-difference-pair/'

arr=[]
n=input()

for i in range(n):
	arr.append(input())
arr=sorted(arr)
diff=999999999999
for i in range(1,n):
	if abs(arr[i]-arr[i-1]) < diff:
		diff=abs(arr[i]-arr[i-1])

print(diff)
