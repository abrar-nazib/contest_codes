def decode_secret(file_path: str) -> str:
    word_dict = {}
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            words = line.split()
            word_dict[int(words[0])] = words[1]
    key = 1
    i=2
    secret = ''
    while key in word_dict:
        secret += word_dict[key] + ' '
        key += i
        i+=1
    secret = secret.strip()
    return secret


if __name__ == "__main__":
    # decode_secret('coding_challange_input.txt')
    print(decode_secret('coding_challange_input.txt'))