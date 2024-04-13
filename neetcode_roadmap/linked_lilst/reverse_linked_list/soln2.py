number = int(input(""))

length_list = []
for each in range(1,number+1):
    word = input("").lower()
    
    if len(word) >= 10:
        str_00 = word[0] + str(len(word)-2) + word[len(word)-1]
        print(str_00)
    else:
        print(word)