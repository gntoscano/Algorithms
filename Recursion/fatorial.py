#This function is using recursion to call itself until the process end

def fat(num):
    if num == 1: #If number equals 1, the process stop
        return 1
    else:
        return num * fat(num - 1) #This process occurs until the number isn"t 1

print(fat(int(input("Write a number to calculate fatorial: "))))
