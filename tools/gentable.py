# Generating the scantable code takes a bit of work
# so this python script will do it for me.
# be careful with 51

def special_translation():
    if(lower[i].lower() == 'backspace'):
        upper[i] = lower[i] = 0 
        return True
    elif(lower[i].lower() == 'tab'):
        upper[i] = lower[i] = '\t' 
        return True
    elif(lower[i].lower() == 'lshift'):
        upper[i] = lower[i] = 0
        return True
    elif(lower[i].lower() == 'space'):
        upper[i] = lower[i] = ' '
        return True
    elif(lower[i].lower() == 'enter'):
        upper[i] = lower[i] = '\n'
    return False


f = open("scancodes.csv", 'r')

lower = [0] * 256
upper = [0] * 256

for line in f.readlines():
    line = line.strip("\r\n")
    line = line.split(',')

    #line in format [hex, symLower symUpper, dec] or [hex, symBoth, dec]
    middleElement = line[1].split(' ')

    if(len(middleElement) == 2): #symLower, symHigher case
        lower[int(line[2])] = middleElement[0]
        upper[int(line[2])] = middleElement[1]
        pass
    elif(len(middleElement) == 1): #symBoth case
        lower[int(line[2])] = middleElement[0]
        upper[int(line[2])] = middleElement[0]
        pass
    else: #special cases
        pass


# Correct Lowercase/Uppercase and change stuff like ENTER -> \n
for i in range(len(lower)):
    if(str(type(lower[i])) == '<type \'str\'>'):
        if(special_translation()):
            pass
        elif(len(lower[i]) == 1):
            lower[i] = lower[i].lower()
        else:
            lower[i] = 0

for i in range(len(upper)):
    if(str(type(upper[i])) == '<type \'str\'>'):
        if(len(upper[i]) == 1):
            upper[i] = upper[i].upper()
        else:
            upper[i] = 0

# Deal with shifts ... 15 is ascii for shift in and 14 is ascii for shift out
upper[52] = 15
lower[52] = 15

upper[170] = 14
lower[170] = 14

print("char sc_upper[256] = {};".format(upper))
print("char sc_lower[256] = {};".format(lower))