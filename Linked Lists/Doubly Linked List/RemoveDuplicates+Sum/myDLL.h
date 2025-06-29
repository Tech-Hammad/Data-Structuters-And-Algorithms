int myDLL::sumNodes()
{
	return sumNodes(head);
}

int myDLL::sumNodes(Node* head)
{
	int sum = 0;
	Node* current = head;

	while (current != nullptr)
	{
		sum = sum + current->data;
		current = current->next;
	}
	return sum;
}

void myDLL::removeDuplicates()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}

	Node* current = head;

	while (current != nullptr)
	{
		Node* nextNode = current->next;

		while (nextNode != nullptr)
		{
			if (nextNode->data == current->data)
			{
				Node* temp = nextNode;
				nextNode = nextNode->next;

				if (temp->prev != nullptr)
				{
					temp->prev->next = temp->next;
				}
				if (temp->next != nullptr)
				{
					temp->next->prev = temp->prev;
				}

				delete temp;
			}
			else
			{
				nextNode = nextNode->next;  // Only move nextNode forward if not deleting
			}
		}
		current = current->next;
	}
}
