#include "PriorityQueue.h"
#include<iostream>
#include<cmath>

//constructor
PriorityQueue::PriorityQueue()
{
}

//destructor
PriorityQueue::~PriorityQueue()
{
}

//returns index of Parent node
int PriorityQueue::Parent(int i)
{
	return (int)ceil(i / 2.0 - 1);
}

//returns index of Left node
int PriorityQueue::Left(int i)
{
	return 2 * i + 1;
}

//returns index of Right node
int PriorityQueue::Right(int i)
{
	return Left(i) + 1;
}

//decrease the key ofr the node of given index
void PriorityQueue::DecreaseKey(int i, Node n)
{
	if (n.key > PQ[i].key)
	{
		std::cout<<"Error\n";
		return;
	}

	//replace the node with decreased value node
	PQ[i] = n;
	//compares that node woth every parent and swap if it is vioalting the min heap property
	while (i > 0 && PQ[PriorityQueue::Parent(i)].key > PQ[i].key)
	{
		std::swap(PQ[i], PQ[PriorityQueue::Parent(i)]);
		i = PriorityQueue::Parent(i);
	}
}

//min heapify
void PriorityQueue::MinHeapify(int i)
{
	int smallest;

	//finding a smallest
	int left = PriorityQueue::Left(i);

	if (left < PQ.size() && PQ[left].key < PQ[i].key)
		smallest = left;
	else
		smallest = i;

	int right = PriorityQueue::Right(i);

	if (right < PQ.size() && PQ[right].key < PQ[smallest].key)
		smallest = right;
	//smallest found

	if (smallest != i) 
	{
		std::swap(PQ[i], PQ[smallest]);
		MinHeapify(smallest);
	}
}

//inserts given node in Heap
void PriorityQueue::HeapInsert(Node n)
{
	Node temp(INT_MAX, 12);
	PQ.push_back(temp);
	DecreaseKey(PQ.size() - 1, n);
}

// clears the Heap
void PriorityQueue::clear()
{
	PQ.clear();
}

//returns and extract all the minimum from the heap
std::vector<Node> PriorityQueue::ExtractAllMin()
{
	//vector to store all min extracted node
	std::vector<Node> allMin;
	if (PQ.size() <= 0)
	{
		std::cout << "Heap Underflow";
	}
	else
	{
		Node min;
		do
		{
			min = PQ[0];
			PQ[0] = PQ[PQ.size() - 1];
			PQ.pop_back();
			allMin.push_back(min);
			MinHeapify(0);
		} while (PQ.size() > 0 && min.key == PQ[0].key);
	}
	return allMin;
}

//prints the PQ
void PriorityQueue::PrintPriorityQueue(std::vector<Node> PQ)
{
	if (PQ.size() <= 0)
	{
		std::cout << "PQ has no node to print";
	}
    for (Node var : PQ)
	{
		std::cout << "[" << var.key << " " << var.data << "]   ";
	}
	std::cout << "\n";
}

//returns all the minimum from Heap
void PriorityQueue::AllMinimum(int i, std::vector<Node> &allMin)
{
	if (i < 0 || i >= PQ.size())
		return;
	Node min = PQ[i];
	//storing all the minimum nodes from Heap without extracting it
	allMin.push_back(min);
	if (Left(i) < PQ.size())
	{
		Node left = PQ[Left(i)];
		if (left.key == min.key)
		{
			//recursively find all the nodes connected with root node with same key since they are minimum nodes
			AllMinimum(Left(i), allMin);
		}
	}
	if (Right(i) < PQ.size())
	{
		Node right = PQ[Right(i)];
		if (right.key == min.key)
		{
			//recursively find all the nodes connected with root node with same key since they are minimum nodes
			AllMinimum(Right(i), allMin);
		}
	}
}
