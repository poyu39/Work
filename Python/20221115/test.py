# coding=utf-8
arr1 = input().split()
arr2 = input().split()
if(len(arr1) - 1 >= len(arr2)):
    a = len(arr1) - len(arr2)
    for i in range((a), len(arr1) - 1):
        arr2.append(arr2[i - a])
print(arr1)
print(arr2)
arr3 = []
k=int(0)
while k<len(arr1)-1:
    arr3.append(arr1[k])
    arr3.append(arr2[k])
    k += 1
arr3.append(arr1[k])
r=float(0)
while '%' in arr3 or '*' in arr3 or '/' in arr3 :
    for i in range(0,len(arr3)):
        if arr3[i] == '%':
            r = str(int(arr3[i-1])%int(arr3[i+1]))
            del arr3[i-1],arr3[i-1],arr3[i-1]
            arr3.insert(i-1,r)
            break
        elif arr3[i] == '*':
            r = str(int(arr3[i-1])*int(arr3[i+1]))
            del arr3[i-1],arr3[i-1],arr3[i-1]
            arr3.insert(i-1,r)
            break
        elif arr3[i] == '/':
            r = str(int(arr3[i-1])/int(arr3[i+1]))
            del arr3[i-1],arr3[i-1],arr3[i-1]
            arr3.insert(i-1,r)
            break
while '+' in arr3 or '-' in arr3:
    for i in range(0,len(arr3)):
        if arr3[i] == '+':
            r = str(int(arr3[i-1])+int(arr3[i+1]))
            del arr3[i-1],arr3[i-1],arr3[i-1]
            arr3.insert(i-1,r)
            break
        elif arr3[i] == '-':
            r = str(int(arr3[i-1])-int(arr3[i+1]))
            del arr3[i-1],arr3[i-1],arr3[i-1]
            arr3.insert(i-1,r)
            break  
print(arr3)