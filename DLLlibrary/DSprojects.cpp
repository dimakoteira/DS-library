#include <iostream>
#include"clsDbLinkedList.h"
#include"clsMyQueue.h";
using namespace std;

int main()
{
    //testing clsDbLinkedList.h
    {
        clsDbLinkedList<int> myList;
        cout << "--- Testing Insertion Methods ---" << endl;
        myList.InsertAtBeginning(10); // List: 10
        myList.InsertAtBeginning(5);  // List: 5 10
        myList.InsertAtEnd(20);       // List: 5 10 20
        myList.InsertAtEnd(30);       // List: 5 10 20 30

        cout << "Initial List: ";
        myList.printList(); // Expected: 5 10 20 30

        // 2. Testing Insert After (by Index)
        cout << "\nInserting 15 after index 1 (value 10):" << endl;
        myList.InsertAfter(1, 15);
        myList.printList(); // Expected: 5 10 15 20 30

        // 3. Testing Search and Retrieval
        cout << "\n--- Testing Search & Access ---" << endl;
        clsDbLinkedList<int>::Node* found = myList.FindNode(20);
        if (found != nullptr)
            cout << "Node with value 20 found at memory address: " << found << endl;

        cout << "Item at index 2: " << myList.getItem(2) << endl; // Expected: 15
        cout << "Current List Size: " << myList.size() << endl;   // Expected: 5

        // 4. Testing Update
        cout << "\nUpdating index 0 to value 1:" << endl;
        myList.updateItem(0, 1);
        myList.printList(); // Expected: 1 10 15 20 30

        // 5. Testing Reverse
        cout << "\nReversing the list:" << endl;
        myList.reverse();
        myList.printList(); // Expected: 30 20 15 10 1

        // 6. Testing Deletion Methods
        cout << "\n--- Testing Deletion ---" << endl;
        cout << "Deleting first node:" << endl;
        myList.deleteFirst();
        myList.printList(); // Expected: 20 15 10 1

        cout << "Deleting last node:" << endl;
        myList.deleteLast();
        myList.printList(); // Expected: 20 15 10

        cout << "Deleting node with value 15 (using pointer):" << endl;
        clsDbLinkedList<int>::Node* nToDelete = myList.FindNode(15);
        myList.deleteNode(nToDelete);
        myList.printList(); // Expected: 20 10

        // 7. Testing Edge Cases & Clearing
        cout << "\n--- Testing Edge Cases ---" << endl;
        cout << "Is list empty? " << (myList.isEmpty() ? "Yes" : "No") << endl;

        cout << "Clearing the list..." << endl;
        myList.clear();
        cout << "Is list empty after clear? " << (myList.isEmpty() ? "Yes" : "No") << endl;

        // Testing out of bounds access
        if (myList.getItem(10) == NULL) {
            cout << "Caught: Index out of bounds (Returned NULL safely)" << endl;
        }
    }

    //testing queue
    {
        clsMyQueue<int> myQueue;
        cout << "--- Testing Basic Queue Operations (FIFO) ---" << endl;
        myQueue.push(10); // Queue: 10
        myQueue.push(20); // Queue: 10 20
        myQueue.push(30); // Queue: 10 20 30
        myQueue.push(40); // Queue: 10 20 30 40

        cout << "Current Queue: ";
        myQueue.print(); // Expected: 10 20 30 40

        // 2. Testing Front and Back
        cout << "\nFront Element: " << myQueue.front() << endl; // Expected: 10
        cout << "Back Element: " << myQueue.back() << endl;   // Expected: 40

        // 3. Testing Pop Operation (Should remove from front)
        cout << "\nPerforming Pop (Removing Front)..." << endl;
        myQueue.pop();
        cout << "Queue after pop: ";
        myQueue.print(); // Expected: 20 30 40

        // 4. Testing Advanced Operations (Extension of standard Queue)
        cout << "\n--- Testing Extended Operations ---" << endl;

        cout << "Updating index 1 (value 30) to 100:" << endl;
        myQueue.updateItem(1, 100);
        myQueue.print(); // Expected: 20 100 40

        cout << "Inserting 500 after index 0:" << endl;
        myQueue.InsertAfter(0, 500);
        myQueue.print(); // Expected: 20 500 100 40

        // 5. Testing Reverse
        cout << "\nReversing the Queue:" << endl;
        myQueue.reverse();
        myQueue.print(); // Expected: 40 100 500 20

        // 6. Testing Sizes and State
        cout << "\n--- Testing Queue State ---" << endl;
        cout << "Queue Size: " << myQueue.size() << endl;       // Expected: 4
        cout << "Is Queue Empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

        // 7. Testing Clear
        cout << "\nClearing the Queue..." << endl;
        myQueue.clear();
        cout << "Is Queue Empty after clear? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    }
}
