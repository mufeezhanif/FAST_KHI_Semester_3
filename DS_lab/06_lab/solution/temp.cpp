void push(int data)
{

    // Create new node temp and allocate memory
    struct Node *temp;
    temp = new Node();

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data = data;

    // Put top pointer reference into temp link
    temp->link = top;

    // Make temp as top of Stack
    top = temp;
}
