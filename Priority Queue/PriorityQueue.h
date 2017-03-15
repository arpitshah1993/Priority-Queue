#include<cstdio>
#include<vector>
#include"Node.h"
class PriorityQueue
{
public:
	//vector to create priority queue
	std::vector<Node> PQ;
	PriorityQueue();
	~PriorityQueue();
	int Parent(int);
	int Left(int);
	int Right(int);
	void clear();
	void DecreaseKey(int, Node);
	void MinHeapify(int);
	void HeapInsert(Node);
	std::vector<Node> ExtractAllMin();
	void PrintPriorityQueue(std::vector<Node>);
	void AllMinimum(int i, std::vector<Node> &allMin);
};

