'http://www.geeksforgeeks.org/find-lost-element-from-a-duplicated-array/'

def xor_func(s1,s2):
	return s1^s2
arr1=[]
arr2=[]
n=input()
for i in range(n):
	temp=input()
	arr1.append(int(temp))
for i in range(n-1):
	temp=input()
	arr2.append(int(temp))	
a1=reduce(xor_func,arr1)
a2=reduce(xor_func,arr2)
answer=xor_func(a1,a2)

print(answer)



