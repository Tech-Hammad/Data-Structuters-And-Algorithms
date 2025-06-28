#include <iostream>
#include <string>
#include "myDLL.h"
using namespace std;

class Book
{
public:
	string title;
	myDLL ReservationList;

	Book(string t)
	{
		title = t;
	}

	void addStudent(const string& name, int priority)
	{
		Student s(name, priority);

		Node* temp = ReservationList.getHead();

		while (temp && temp->data.priority <= priority)
		{
			temp = temp->next;
		}

		if (!temp)
		{
			ReservationList.insertAtTail(s);
		}
		else if (temp == ReservationList.getHead())
		{
			ReservationList.insertAtHead(s);
		}
		else 
		{ 
			// insert before temp
			Node* nn = new Node;
			nn->data = s;
			nn->prev = temp->prev;
			nn->next = temp;
			temp->prev->next = nn;
			temp->prev = nn;
		}
		cout << s.name << " added to " << title << " with priority " << priority << endl;
	}


	void removeStudent(const string& name) 
	{
		Node* temp = ReservationList.getHead();
		while (temp) 
		{
			if (temp->data.name == name)
			{
				ReservationList.deleteValue(temp->data);
				cout << name << " removed from reservation list of " << title << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Student not found.\n";
	}


	void updatePriority(const string& name, int newPriority)
	{
		Node* temp = ReservationList.getHead();
		while (temp) 
		{
			if (temp->data.name == name) 
			{
				ReservationList.deleteValue(temp->data);
				addStudent(name, newPriority);
				cout << "Priority updated.\n";
				return;
			}
			temp = temp->next;
		}
		cout << "Student not found.\n";
	}

	void removeFromFront()
	{
		if (ReservationList.isEmpty())
		{
			cout << "Reservation list is empty.\n";
		}
		else
		{
			Student removed = ReservationList.deleteFromHead();
			cout << removed.name << " removed from front (book returned).\n";
		}
	}

	void displayList()
	{
		cout << "Reservation list for book: " << title << endl;
		ReservationList.displayFromHead();
	}

	int CountStudents()
	{
		int count = 0;
		Node* temp = ReservationList.getHead();

		while (temp)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
};

int main()
{
	Book book1("Data Structures and Algorithms");
	Book book2("Operating Systems");

	book1.addStudent("Alice", 2);
	book1.addStudent("Bob", 1);
	book1.addStudent("Charlie", 3);

	book2.addStudent("David", 1);
	book2.addStudent("Eve", 2);

	cout << endl;
	book1.displayList();
	book2.displayList();

	cout << "\nNumber of students in " << book1.title << ": " << book1.CountStudents() << endl;

	// Update priority
	cout << "\nUpdating Charlie's priority to 1:" << endl;
	book1.updatePriority("Charlie", 1);
	book1.displayList();

	// Remove student
	cout << "\nRemoving Alice from " << book1.title << " list:" << endl;
	book1.removeStudent("Alice");
	book1.displayList();

	// Book returned
	cout << "\nBook returned, remove front student:" << endl;
	book1.removeFromFront();
	book1.displayList();
	
	return 0;
}