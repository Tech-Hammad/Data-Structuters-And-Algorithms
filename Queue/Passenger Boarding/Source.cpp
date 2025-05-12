// This Code Inputs the Unique ID
#include <iostream>
#include <string>
#include "myQueue.h"
using namespace std;

class Passenger
{
private:
	int Id;
	string name;
public:
	Passenger():Id(0)
	{
		name = "";
	}

	Passenger(int id, string n):Id(id)
	{
		name = n;
	}

    Passenger(const Passenger& other)
    {
        Id = other.Id;
        name = other.name;
    }

	void setId(int id)
	{
		Id = id;
	}
	void setName(string n)
	{
		name = n;
	}
	int getId() const
	{
		return Id;
	}
	string getName()
	{
		return name;
	}

	void display() const
	{
		cout << "#" << Id << "  " << name << "\n";
	}
};

bool isUniqueId(myQueue<Passenger>& queue, int newId)
{
    myQueue<Passenger> temp(queue.getCapacity());
    bool found = true;

    while (!queue.isEmpty()) 
    {
        Passenger p = queue.Dequeue();
        if (p.getId() == newId) 
        {
            found = false;
        }
        temp.Enqueue(p);
    }

    while (!temp.isEmpty()) 
    {
        queue.Enqueue(temp.Dequeue());
    }

    return found; 
}


int main()
{
	myQueue<Passenger>queue(10);

    int choice;
    int id;
    string name;

    cout << "Airport Passenger Boarding Management System\n";
    cout << "--------------------------------------------\n";

    do 
    {
        cout << "\n-----------Menu-----------\n";
        cout << "1. Enqueue Passenger (Add to queue)\n";
        cout << "2. Dequeue Passenger (Board passenger)\n";
        cout << "3. Display Queue\n";
        cout << "4. Rear Most Recent Passenger\n";
        cout << "5. Count Passengers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
        {
            cout << "Enter passenger Boarding ID: ";
            cin >> id;
            if (!isUniqueId(queue, id))
            {
                cout << "Passenger ID must be unique.\n";
                break;
            }
            cout << "Enter passenger name: ";
            cin.ignore(); 
            getline(cin, name);

            queue.Enqueue(Passenger(id, name));
            break;
        }
        case 2:
        {
            if (!queue.isEmpty())
            {
                Passenger p = queue.Dequeue();
                cout << "Boarding Passenger: ";
                p.display();
            }
            else
            {
                cout << "Queue is Empty.\n";
            }
            break;
        }
        case 3:
        {
            cout << "=====Current Boarding Queue=====\n";
            queue.display();
            break;
        }
        case 4:
        {
            if (!queue.isEmpty())
            {
                cout << "Last Added Passenger:- ";
                Passenger p = queue.Rear();
                p.display();
            }
            else
            {
                cout << "No Passenger in the Queue.\n";
            }
            break;
        }
        case 5:
        {
            cout << "Number of Passenger Waiting to Board: " << queue.getCurrentSize() << "\n";
            break;
        }
        case 6:
        {
            cout << "Exiting system.\n";
            break;
        }
        default:
        {
            cout << "Invalid choice.\n";
        }

        }
    } while (choice != 6);

	return 0;
}