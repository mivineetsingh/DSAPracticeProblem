def subsequencesList(input, output, result):
    if(len(input) == 0):
        result.append(output)
        return

    currChar = input[0]
    remainingInput = input[1:]

    # include
    subsequencesList(remainingInput, output+currChar, result)
    # exclude
    subsequencesList(remainingInput, output, result)


result = []

subsequencesList("acb", "", result)

result.sort()
result.sort(key=lambda x: len(x))

print(result)
