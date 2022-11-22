val = list(map(int, input().split()))
op =  input().split()

infix = []
post = []
post_priority = []
temp = []
temp_priority = []

# 1 2 3 4 5 6
# + - * + -
# 1+2-3*4+5-6
# 12+34*-5+6-

# 補足運算子
offset = 0
if(len(val) - 1 >= len(op)):
    add_op = len(val) - len(op)
    for i in range(add_op):
        if(i >= len(op)):
            offset += len(op)
        # print(i - (add_op))
        op.append(op[i - offset])
# print(val)
print("補足運算子: ", op)

# 合成中序
for i in range(len(val) - 1):
    infix.append(val[i])
    infix.append(op[i])
infix.append(val[len(val) - 1])
print("合成中序: ", infix)

# 中序轉後序
for i in infix:
    if(type(i) == int):
        post.append(i)
    else:
        if(len(temp) != 0):
            if(i == '*' or i == '/' or i == '%'):
                now_priority = 2
            else:
                now_priority = 1

            while(len(temp_priority) != 0):
                if(temp_priority[-1] >= now_priority):
                    post.append(temp.pop())
                    temp_priority.pop()
                else:
                    break
        
        temp.append(i)
        if(i == '*' or i == '/' or i == '%'):
            temp_priority.append(2)
        elif(i == '+' or i == '-'):
            temp_priority.append(1)
    # print(i, len(temp), temp_priority)

while(len(temp_priority) != 0):
    post.append(temp.pop())
    temp_priority.pop()
print("中序轉後序: ", post)

# 後序計算結果
value_count = []
result = 0
index = 0
while(index < len(post)):
    if(type(post[index]) == int):
        value_count.append(post[index])
    else:
        if(len(value_count) > 1):
            if(post[index] == '+'):
                value_count[0] = value_count[0] + value_count[1]
            elif(post[index] == '-'):
                value_count[0] = value_count[0] - value_count[1]
            elif(post[index] == '*'):
                value_count[0] = value_count[0] * value_count[1]
            elif(post[index] == '/'):
                value_count[0] = int(value_count[0] / value_count[1])
            elif(post[index] == '%'):
                value_count[0] = int(value_count[0] % value_count[1])
            index += 1
        
        if(type(post[index]) != int):
            if(post[index] == '+'):
                result += value_count[0]
            elif(post[index] == '-'):
                result -= value_count[0]
            elif(post[index] == '*'):
                result *= value_count[0]
            elif(post[index] == '/'):
                result += int(value_count[0] / value_count[1])
            elif(post[index] == '%'):
                result += int(value_count[0] % value_count[1])
        else:
            result = value_count[0] 
            index -= 1 
        value_count.clear()
    index += 1    
print("結果", result)