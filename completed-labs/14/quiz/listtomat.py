"""
Converting adjacency list to adjacency matrix
"""

def main():

    unfiltered_edges = str(input(""))
    unfiltered_edges = list(unfiltered_edges)

    vertex = list(input("Vertices: "))

    for i in range(len(unfiltered_edges)):
        if unfiltered_edges[i-1] == ")" and i != 0:
            unfiltered_edges[i] = ";"

        if unfiltered_edges[i] in vertex:
            unfiltered_edges[i] = str(vertex.index(unfiltered_edges[i]))

    final_string = ""
    for i in unfiltered_edges:
        final_string += i

    edge_list = final_string.split(";")

    temp = []
    final_mat = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]

    for i in edge_list:
        i = list(i)
        print(i)
        fromV = int(i[1])
        toV   = int(i[3])
        w     = int(i[5])

        final_mat[fromV][toV] = w

    print()
    for i in final_mat:
        print(i)

if __name__ == "__main__":
    main()
