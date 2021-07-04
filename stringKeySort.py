def stringKeySort():
    nRows = int(input("Enter the number of rows \n"))

    strList = []

    for i in range(nRows):
        tempList = list(input().split(" "))
        strList.append(tempList)

    colNum, isReverse, sortingType = input().split(" ")
    colNum = int(colNum)

    result = []

    # if sortType is numeric
    if(sortingType == "numeric"):
        if(isReverse == "false"):
            result = sorted(strList, key=lambda val: int(val[colNum]))
        else:
            result = sorted(strList, key=lambda val: int(
                val[colNum]), reversed=True)
    # if sortType is lexicographic
    if(sortingType == "lexicographic"):
        if(isReverse == "false"):
            result = sorted(strList, key=lambda val: val[colNum])
        else:
            result = sorted(strList, key=lambda val:
                            val[colNum], reversed=True)

    return result


print(stringKeySort())
