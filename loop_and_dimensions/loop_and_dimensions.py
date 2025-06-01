# 09/13/24

# PART A
n = int(input("Enter the value of n: "))
n1 = n
for i in range(n*n):
	print(+1,end='  ')
	if i+1 == n1:
		print()
		n1 = n1 + n
print()


# PART B
n = int(input('Enter dimension: '))
for i in range(n):
    for j in range(0,i+1):
        print('* ',end='')
    print()


# PART C
'''
n = int(input('Enter dimension: '))
n1 = 0
for i in range(n):
    if i == n1:
        print('* ',end='')
        
        i+1
        
        print(i,end='')
        print(n1,end='')
        print()
print()
        
#    elif i == n:
#        print('* ',end='')
#    else:
#        print('* ',end='')
'''