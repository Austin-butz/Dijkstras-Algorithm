all:
	g++ -g -Wall Graph.cpp GraphTests.cpp -o graph-tests
	g++ -g -Wall BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests