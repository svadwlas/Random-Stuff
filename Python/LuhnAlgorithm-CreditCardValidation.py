if __name__ == '__main__':
    number = input('Enter the credit card number').replace(' ', '')
    if not number.isdigit():
        raise Exception('Invalid Credit Card number. Make sure its all digits with optional spaces')
    digits = [int(char) for char in number]
    digits = digits[-1::-1]
    doubled = [(digit * 2) if ((i+1) %2 ==0) else digit for (i,digit) in enumerate(digits)]
    summed = [num if num < 10 else num-9 for num in doubled]
    if sum(summed) % 10 ==0:
        print ('The number is valid')
    else:
        print ('The number is invalid')
