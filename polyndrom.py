'''Returns if the string is a polyndrom'''


def Polyndrom(string):
    secondString = string[::-1]
    if len(secondString) != len(string):
        return False
    for i in range(0, len(string) - 1):
        if i == ' ':
            continue
        elif string[i] != secondString[i]:
            return False
    return True
