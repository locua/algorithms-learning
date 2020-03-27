'''
Parser for edges
'''

# python3 parser.py

def sortFirst(val):
	return val[0]

def main():
	unfiltered_edges = input("edges: ")
	unfiltered_edges = list(unfiltered_edges)

	vertex = list(input("Vertices: "))

	for i in range(len(unfiltered_edges)):
		if unfiltered_edges[i-1] == ")" and i != 0:
			unfiltered_edges[i] = ";"

		if unfiltered_edges[i] in vertex:
			unfiltered_edges[i] = str(vertex.index(unfiltered_edges[i]))

	# print(unfiltered_edges)

	final_string = ""
	for i in unfiltered_edges:
		final_string += i

	edge_list = final_string.split(";")

	temp = []

	for i in edge_list:
		i = list(i)
		if len(i) == 7:
			temp.append([i[1], i[3], i[5]])
			print("addEdge(graph, {0}, {1}, {2}); ".format(i[1], i[3], i[5]))

		elif len(i) == 8:
			temp.append([i[1], i[3], i[5]+i[6]])
			print("addEdge(graph, {0}, {1}, {2}); ".format(i[1], i[3], i[5]+i[6]))

	temp.sort(key=sortFirst)

	print()

	for i in temp:
		print("{0} - {1}  {2}".format(i[0],i[1],i[2]))

if __name__ == '__main__':
	main()
