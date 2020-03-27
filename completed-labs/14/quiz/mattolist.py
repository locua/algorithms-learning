"""
Converting adjacency matrix to adjacency list
"""

# python3 converter.py

def sortThird(val):
    return val[2]

def main():
    row1 = list(input("Row 1: "))
    row2 = list(input("Row 2: "))
    row3 = list(input("Row 3: "))
    row4 = list(input("Row 4: "))
    vlist = list(input("Vertices: "))
    allRows = []
    allRows.append(row1)
    allRows.append(row2)
    allRows.append(row3)
    allRows.append(row4)

    elist = ""
    elist_list = []
    weights = ["1", "2", "3", "4", "5", "6"]

    for i in range(len(allRows)):
        for j in range(len(allRows[i])):
            if allRows[i][j] != "0":
                fromV = vlist[i]
                toV = vlist[j]
                w = str(allRows[i][j])

                elist_list.append([fromV, toV, int(w)])
                # elist += "({0}, {1}, {2}),".format(fromV, toV, w)

    elist_list.sort(key = sortThird)

    for edge in elist_list:
        elist += "("
        for val in edge:
            elist += str(val)
            elist += ","
        elist = elist[:-1]
        elist += "),"

    print()
    print(elist[:-1])

if __name__ == "__main__":
    main()
