Readme.md

So it is Dijkstra algorithm realisation with complexity O(n^2logn) in worst case.
Based on priority queue (queue was implemented on basement of heap).

How to run:
In command line pass the name of input file as first argument
Input file should have following structure: 
- first line is the number of vertexes
- second - start vertex (to find paths from it to other vertexes in graph)
other lines consists of list of edges
first line here is list of edges from the first(zero) vertex to adjacent edges and their weight.
For example vertex number 0 has 2 neighbours : vertex 1 and 3 with 100 and 200 weights correspondently . So the first line should look like this: 
1 100 3 200
Other lines is written with the same rule.

Second arg in command line is the nme of out file.
