// A_E.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "PriorityQueue.h"
#include <iostream>
#include <string>
using namespace std;


struct Patient {
	string name;
	int priority;
	
	bool operator < (Patient  p1)
	{
		return p1.priority > priority;
	}
	bool operator <= (Patient  p1)
	{
		return p1.priority >= priority;
	}
	bool operator > (Patient  p1)
	{
		return p1.priority < priority;
	}
	bool operator >= (Patient  p1)
	{
		return p1.priority <= priority;
	}
	bool operator == (Patient  p1)
	{
		return p1.priority == priority;
	}
};


int main()
{
	
	string x = "2";
	int y = 0;


	/*Patient p1 = { "Bethany",5 };
	Patient p2 = { "Rachel",3 };
	Patient p3 = { "Mike",5 };
	Patient p4 = { "John",2 };
	Patient p5 = { "Mary",1 };
	Patient p6 = { "Jane",1 };
	Patient p7 = { "Tom",3 };
	Patient p8 = { "Kim",4 };
	Patient p9 = { "Tim",1 };
	Patient p10 = { "Shaun",2};*/

	Patient p1 = { "Tom",3 };
	Patient p2 = { "Mary",4 };
	Patient p3 = { "Fred",3 };
	Patient p4 = { "Sarah",1 };
	Patient p5 = { "Ann",5 };
	Patient p6 = { "Mike",4 };
	Patient pUser { x , y };

	PQType<Patient> pQueue(100); // have to enter a max int

	pQueue.Enqueue(p1);
	pQueue.Enqueue(p2);
	pQueue.Enqueue(p3);
	pQueue.Enqueue(p4);
	pQueue.Enqueue(p5);
	pQueue.Enqueue(p6);
	/*pQueue.Enqueue(p7);
	pQueue.Enqueue(p8);
	pQueue.Enqueue(p9);
	pQueue.Enqueue(p10);*/
	
	//pQueue.Print();

	int option = 0;
	do
	{
		cout << "\n\n\t\t ******** A & E *********\n\n"
				<< "\t\t1. Add Patient to queue.\n"
				<< "\t\t2. Call Patient to appointment\n"
				<< "\t\t3. Display all patients\n"
				<< "\t\t4. Exit\n\n";

		cin >> option;
		cout << "You have chosen option: " << option << endl;

		switch (option) {
		case 1:

			cout << "\nPlease enter the patients name: \n";
			cin >> x;
			
			cout << "\nPlease enter the patients A & E priority:\n";
			cin >> y;
			
			pUser.name = x;
			pUser.priority = y;

			pQueue.Enqueue(pUser); // adds the new user to the priority queue

			break;
		case 2:
			pQueue.Dequeue(pUser); //Removes top item from the queue
			break;

		case 3:
			pQueue.Print(); // prints contents of entire queue.
			break;

		case 4:
			break; // exits program

		default:
			cout << "Invalid Option. Please choose again.\n";
			break;
		}
	} while (option != 4);
}

