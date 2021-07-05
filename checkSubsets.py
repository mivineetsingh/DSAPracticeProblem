"""
Sample input:
codingminutes
cmines

Sample output:
True
"""


def checkSubsets(mainString, subString):
    i, j = len(mainString)-1, len(subString)-1

    while(i >= 0 and j >= 0):
        if(mainString[i] == subString[j]):
            j -= 1
        i -= 1
    return j == -1


print(checkSubsets("vineetsingh", "svine"))
