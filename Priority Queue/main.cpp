#include<iostream>
#include<string>
#include <time.h>
#include"PriorityQueue.h"
#include"SmoothSort.h"
using namespace std;

int main()
{
	//******************************************************************************************************
	//******************************************************************************************************
	////////Starting proiority queue based on MIN HEAP Questions
	std::cout << std::string(10, '*');
	std::cout << "A Min - Heap Based Priority Queue";
	std::cout << std::string(10, '*') << std::endl;
	std::cout << std::endl;
	PriorityQueue object;
	vector<Node> temp;
	srand(time(NULL));


	//Question 1
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 1" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	for (int i = 1; i <= 100; i++)
	{
		Node temp((101 - i), i);
		object.HeapInsert(temp);
	}
	std::cout << std::string(50, '*') << std::endl;
	std::cout << "INPUT:" << std::endl;
	object.PrintPriorityQueue(object.PQ);
	std::cout << "\nApplied Extra-all-min operation to PQ" << std::endl;
	std::cout << "OUTPUT:" << std::endl;
	object.PrintPriorityQueue(object.ExtractAllMin());
	std::cout << "\nInserted the data [1 0] to PQ" << std::endl;
	{
		Node temp(1, 0);
		object.HeapInsert(temp);
	}
	std::cout << "\nOUTPUT(PQ after Insertion):" << std::endl;
	object.PrintPriorityQueue(object.PQ);
	std::cout << "\nApplied Extra-all-min operation to PQ" << std::endl;
	std::cout << "OUTPUT:" << std::endl;
	object.PrintPriorityQueue(object.ExtractAllMin());

	object.clear();

	//Question 2
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 2" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;

	for (int i = 1; i <= 1000; i++)
	{
		Node temp((1001 - i), i);
		object.HeapInsert(temp);
	}
	std::cout << std::string(50, '*') << std::endl;
	std::cout << "INPUT:" << std::endl;
	object.PrintPriorityQueue(object.PQ);
	std::cout << "\nApplied AllMinimium operation to PQ" << std::endl;
	std::cout << "OUTPUT:" << std::endl;
	object.AllMinimum(0, temp);
	object.PrintPriorityQueue(temp);
	temp.clear();
	std::cout << "\nInserting data items [1,1] to [1,30] in PQ" << std::endl;
	for (int i = 1; i <= 30; i++)
	{
		Node temp(1, i);
		object.HeapInsert(temp);
	}
	std::cout << "\nApplied Extra-all-min operation to PQ" << std::endl;
	std::cout << "OUTPUT:" << std::endl;
	object.PrintPriorityQueue(object.ExtractAllMin());
	std::cout << "\nApplied AllMinimium operation to PQ" << std::endl;
	std::cout << "OUTPUT:" << std::endl;
	object.AllMinimum(0, temp);
	object.PrintPriorityQueue(temp);
	temp.clear();

	object.clear();

	//Question 3
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 3" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;

	std::cout << "\nInserting 500 randomly generated data items in PQ" << std::endl;
	for (int i = 1; i <= 500; i++)
	{
		Node temp;
		temp.key = rand() % 991 + 10;
		temp.data = rand() % 991 + 10;
		object.HeapInsert(temp);
	}
	std::cout << "INPUT:" << std::endl;
	object.PrintPriorityQueue(object.PQ);
	std::cout << "\nApplied Extra-all-min operation 5 times to PQ" << std::endl;
	for (int i = 1; i <= 5; i++)
	{
		std::cout << "\nApplied Extra-all-min operation " << i << "th times to PQ" << std::endl;
		std::cout << "OUTPUT:" << std::endl;
		object.PrintPriorityQueue(object.ExtractAllMin());
		std::cout << "\n";
	}
	int randomlySelectedNode = rand() % 500;
	std::cout << "\nApplied decrease key operation to " << randomlySelectedNode << "th Node PQ" << std::endl;
	Node decreasedNode(5, object.PQ[randomlySelectedNode].data);
	object.DecreaseKey(randomlySelectedNode, decreasedNode);
	std::cout << "Decreased node:[" << decreasedNode.key << ", " << decreasedNode.data << "]";
	std::cout << "\nApplied AllMinimium operation to PQ" << std::endl;
	std::cout << "OUTPUT:" << std::endl;
	object.AllMinimum(0, temp);
	object.PrintPriorityQueue(temp);
	temp.clear();

	object.clear();

	//Question 4
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 4" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;

	std::cout << "\nInserting data items in PQ" << std::endl;
	for (int i = 1; i <= 500; i++)
	{
		Node temp;
		temp.key = rand() % 991 + 10;
		temp.data = rand() % 991 + 10;
		object.HeapInsert(temp);
	}
	std::cout << "INPUT:" << std::endl;
	object.PrintPriorityQueue(object.PQ);
	std::cout << "\nApplied decrease key operation 10 times to PQ" << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		int randomlySelectedNode = rand() % 500;
		std::cout << "\nApplied " << i << "th times decrease key operation to " << randomlySelectedNode << "th Node PQ" << std::endl;
		Node decreasedNode(rand() % 10, object.PQ[randomlySelectedNode].data);
		std::cout << "Decreased node:[" << decreasedNode.key << ", " << decreasedNode.data << "]";
		object.DecreaseKey(randomlySelectedNode, decreasedNode);
		std::cout << "\n";
	}
	std::cout << "\nApplied Extra-all-min operation 10 times to PQ" << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		std::cout << "\nApplied Extra-all-min operation " << i << "th times to PQ" << std::endl;
		std::cout << "OUTPUT:" << std::endl;
		object.PrintPriorityQueue(object.ExtractAllMin());
		std::cout << "\n";
	}

	object.clear();

	//Question 5
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 5" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;

	for (int i = 1; i <= 100; i++)
	{
		std::cout << "\n";
		std::cout << "Operation: " << i << std::endl;
		int opertaion = rand() % 4;
		switch (opertaion)
		{
		case 0:
		{
			//HeapInsert
			int key = rand();
			int data = rand();
			std::cout << "Inserting data items [" << key << "," << data << "] in PQ" << std::endl;
			Node tempNode(key, data);
			object.HeapInsert(tempNode);
			std::cout << "\n";
		}
		break;
		case 1:
		{
			if (object.PQ.size() > 0)
			{
				//DecreaseKey
				int randomlySelectedNode = rand() % object.PQ.size();
				std::cout << "Decreasing key to " << object.PQ[0].key - 1 << " for " << randomlySelectedNode << "th Node PQ" << std::endl;
				//(object.PQ[0].key - 1)=>getting key value of minimum node(using root node since it has minimum key value) and use it by decreseing it by 1
				Node decreasedNode(object.PQ[0].key - 1, object.PQ[randomlySelectedNode].data);
				std::cout << "Decreased node:[" << decreasedNode.key << ", " << decreasedNode.data << "]";
				object.DecreaseKey(randomlySelectedNode, decreasedNode);
			}
			else
			{
				std::cout << "Decrease key operation" << std::endl;
				std::cout << "Heap Underflow" << std::endl;
			}
			std::cout << "\n";
		}
		break;
		case 2:
		{
			//ExtractAllMinimum
			std::cout << "Applying Extract All Minimum operation to PQ" << std::endl;
			std::cout << "OUTPUT:" << std::endl;
			object.PrintPriorityQueue(object.ExtractAllMin());
			std::cout << "\n";
		}
		break;
		case 3:
		{
			//AllMinimum
			std::cout << "Applying AllMinimium operation to PQ" << std::endl;
			object.AllMinimum(0, temp);
			if (temp.size() > 0)
			{
				std::cout << "OUTPUT:" << std::endl;
				object.PrintPriorityQueue(temp);
			}
			else
			{
				std::cout<<"Heap Underflow";
			}
			temp.clear();
			std::cout << "\n";
		}
		break;
		default:
			break;
		}
		if (i % 20 == 0)
		{
			std::cout << "\n*********Status of PQ after " << i << "th operation*********" << std::endl;
			object.PrintPriorityQueue(object.PQ);
			std::cout << "\n";
		}
	}
	object.clear();

	////////Ending proiority queue based on MIN HEAP
	//******************************************************************************************************
	//******************************************************************************************************


	//******************************************************************************************************
	//******************************************************************************************************
	//Starting Smooth Sort Questions

	SmoothSort s;
	srand(time(NULL));

	//Question 6
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 6" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	for (int i = 1000; i >= 1; i--)
	{
		s.push(i);
	}
	std::cout << "INPUT:" << std::endl;
	s.printInput();
	std::cout << "\nApplying smooth sort" << std::endl;
	s.SmoothSorting();
	std::cout << "\nOUTPUT:" << std::endl;
	s.printComparison();
	s.printOutput();
	std::cout << "\n";

	s.A.clear();

	//Question 7
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 7" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	for (int i = 1; i <= 2000; i++)
	{
		s.push(i);
	}
	std::cout << "INPUT:" << std::endl;
	s.printInput();
	{
		int radomlySelectedNumbers[20];
		for (int i = 0; i < 20; i++)
		{
			radomlySelectedNumbers[i] = rand() % 2000;
		}
		for (int i = 0; i < 20; i += 2)
		{
			int j = i + 1;
			std::cout << "\nSwapping values of randomely selected "<< radomlySelectedNumbers[i] +1 <<"th and "<< radomlySelectedNumbers[j]+1 <<"th nodes" << std::endl;
			std::swap(s.A[radomlySelectedNumbers[i]], s.A[radomlySelectedNumbers[j]]);
		}
	}
	std::cout << "\nInput after swapping position of randomly  selected 20 different values" << std::endl;
	std::cout << "INPUT:" << std::endl;
	s.printInput();
	std::cout << "\nApplying smooth sort" << std::endl;
	s.SmoothSorting();
	std::cout << "\nOUTPUT:" << std::endl;
	s.printComparison();
	s.printOutput();
	std::cout << "\n";

	s.A.clear();

	//Question 8
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 8" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	for (int i = 1; i <= 2000; i++)
	{
		s.push(i);
	}
	std::cout << "INPUT:" << std::endl;
	s.printInput();
	{
		int radomlySelectedNumbers[60];
		for (int i = 0; i < 60; i++)
		{
			radomlySelectedNumbers[i] = rand() % 2000;
		}
		for (int i = 0; i < 60; i += 3)
		{
			std::cout << "\nPermuting three randomly selected nodes "<< radomlySelectedNumbers[i]+1 <<", "<< radomlySelectedNumbers[i+1]+1 <<" and "<<radomlySelectedNumbers[i+2]+1<<std::endl;
			int j = i + 1;
			std::swap(s.A[radomlySelectedNumbers[i]], s.A[radomlySelectedNumbers[j]]);
			j++;
			std::swap(s.A[radomlySelectedNumbers[i]], s.A[radomlySelectedNumbers[j]]);
		}
	}
	std::cout << "\nInput after permuting randomly selected 60 different values in chuncks of 3" << std::endl;
	std::cout << "INPUT:" << std::endl;
	s.printInput();
	std::cout << "\nApplying smooth sort" << std::endl;
	s.SmoothSorting();
	std::cout << "\nOUTPUT:" << std::endl;
	s.printComparison();
	s.printOutput();
	std::cout << "\n";

	s.A.clear();

	//Question 9
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 9" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	for (int i = 1; i <= 3193; i++)
	{
		s.push((rand() % 10000 + 1));
	}
	std::cout << "INPUT:" << std::endl;
	s.printInput();
	std::cout << "\nApplying smooth sort" << std::endl;
	s.SmoothSorting();
	std::cout << "\nOUTPUT:" << std::endl;
	s.printComparison();
	s.printOutput();
	std::cout << "\n";

	s.A.clear();

	//Question 10
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(20, ' ');
	std::cout << "Question 10" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	for (int i = 1; i <= 5166; i++)
	{
		s.push((rand() % 10000 + 1));
	}
	std::cout << "INPUT:" << std::endl;
	s.printInput();
	std::cout << "\nApplying smooth sort" << std::endl;
	s.SmoothSorting();
	std::cout << "\nOUTPUT:" << std::endl;
	s.printComparison();
	s.printOutput();
	std::cout << "\n";

	s.A.clear();

	//Ennding Smooth Sort
	//******************************************************************************************************
	//******************************************************************************************************

	return 0;
}
