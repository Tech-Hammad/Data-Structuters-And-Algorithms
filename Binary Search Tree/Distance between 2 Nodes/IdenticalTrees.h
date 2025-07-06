bool isIdentical(Node* node1, Node* node2)
{
    if (node1 == nullptr && node2 == nullptr) 
    {
        return true;
    }

    if (node1 == nullptr || node2 == nullptr) 
    {
        return false;
    }
    
    
    return ((node1->data == node2->data) && isIdentical(node1->leftChild, node2->leftChild)
        && isIdentical(node1->rightChild, node2->rightChild));
}
