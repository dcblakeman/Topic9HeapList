//Dan Blakeman
//CIS 2207-502
//04-04-2022
//Implement a to-do list using the class HeapPriorityQueue
#include "ArrayMaxHeap.cpp"
#include<string>
#include<iostream>
using namespace std;

int main()
{
	//To-do List:
	const string items[5];
	const int ARRAY_SIZE = 5;
	ArrayMaxHeap<string>* newHeap = new ArrayMaxHeap<string>(items, ARRAY_SIZE);
	newHeap->add("Send a birthday card to Aunt Mabel.");
	newHeap->add("Start the research paper for world history.");
	newHeap->add("Finish reading Chapter 13 of Walls and Mirrors.");
	newHeap->add("Make plans for Saturday night.");
	cout << newHeap->peekTop();
	return 0;
}