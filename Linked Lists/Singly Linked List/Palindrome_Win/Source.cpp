#include <iostream>
#include "myLL.h"

int main()
{
    myLL ticket;
    ticket.insertAtTail(9);
    ticket.insertAtTail(1);
    ticket.insertAtTail(1);
    ticket.insertAtTail(9);
    //ticket.insertAtTail(4);

    ticket.display();

    int result = checkIfWon(ticket);

    cout << "Prize: Rs. " << result << endl;

    return 0;
}
