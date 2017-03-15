*************************************************************************************
==================================Node.h=============================================
*************************************************************************************
int data, int key
It is two parameters which node contains. Node consists these two values as its data. 
Node(int, int)
Constructor which constructs that node when it gets parameter with declaration of that node.
*************************************************************************************
==============================PriorityQueue.h==========================================
*************************************************************************************std::vector<Node> PQ
Vector which we used to contain Priority Queue’s data.
int Parent(int)
It returns the index of parent node for given index.
int Left(int)
It returns the index of left node for given index.
int Right(int)
It returns the index of right node for given index.
void clear()
It clears the data from PQ.
void DecreaseKey(int, Node)
It will take index of the Node from PQ which is going to be decreased and Node with decreased key which will replace that node.
void MinHeapify(int)
It will take an index of the node from which it will start heapify. It will the nodes like key of the Parent node will be always lesser than its child’s recursively.
void HeapInsert(Node)
It will take an node and insert that node into PQ.
std::vector<Node> ExtractAllMin()
It will extract all the nodes with the minimum key and return the list of extracted nodes. It will first picks the root node which always be node with minimum key value then it will start searching connected nodes with same key value on its left and right nodes reclusively till it gets no nodes.
void PrintPriorityQueue(std::vector<Node>)
it prints given priority queue on console.
void AllMinimum(int i, std::vector<Node> &allMin)
It copy the nodes with minimum value from the root node to allMin vector, and then start searching connected nodes with same key value on its left and right nodes reclusively till it gets no nodes.
*************************************************************************************
==============================PriorityQueue.cpp========================================
*************************************************************************************
It contains implementation of all the function I have mentioned in header file. It includes PriorityQueue.h for that.

*************************************************************************************
==============================SmoothSort.h============================================
*************************************************************************************

std::vector<int> A
It is vector which is used to store the data which we are going to sort.
void push(int)
It is used to push the data in vector. 
void printInput()
It prints the input vector.
void printOutput()
It prints the output vector. To satisfy the requirement, It prints every 20th element of the vector as mentioned in the requirements.
bool IsSorted(int a, int b)
It checks two number that whether a<b, if it is true, than it returns true since it is sorted, otherwise number will be considered as unsorted.
void Sift()
It is applied to an element without larger sons is a skip. If it applied to an element m(r1) that is exceeded by its largest son m(r2), it consists of a swap of these two values, followed by an application of sift to m(r2).
void Trinkle()
It is used to make dubious stretch trusty including its root in the sequence of ascending roots. It will restore the root sorted forest from two semi trinkled tree.
void SemiTrinkle()
After making dubious stretch trusty, semi-trinkle is used to include its root in the sequence of ascending roots by exchanging their roots if necessary and call trinkle to restore the root-sorted forest.
void printComparison()
It will print the number of total comparison is done while sorting the given array or vector. We are printing this number of total comparison to satisfy the requirements.
void SmoothSorting()
SmoothSorting is the function which we used to sort the values of given vector, in our case it is A. We will call this function which apparently call other function like trinkle, semi trinkle , sift to sort the vector.
*************************************************************************************
============================== SmoothSort.cpp=========================================
*************************************************************************************
It contains implementation of all the function I have mentioned in header file. It includes PriorityQueue.h for that.
*************************************************************************************
=================================== main.cpp==========================================
*************************************************************************************
It includes header files PriorityQueue.h, SmoothSort.h and use implementation of this header file functions. It use those functions to create output of each question. It will print Input and output of each question as per the requirement mentioned in assignment.

**REFERENCES**
- https://www.cs.utexas.edu/users/EWD/transcriptions/EWD07xx/EWD796a.html

