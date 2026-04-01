#include <iostream>
#include"../includes/clsDbLinkedList.h"
#include"../includes/clsMyQueue.h";
#include"../includes/clsMyStack.h";
#include"../includes/clsDynamicArray.h"
#include"../includes/clsQueueArr.h"
using namespace std;

void printSeparator(string testName) {
    cout << "\n========== " << testName << " ==========\n";
}

void testDbLinkedList()
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

void testQueue()
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

void testStack()
{
    clsMyStack<int> myStack;
    cout << "--- Testing Basic Stack Operations (LIFO) ---" << endl;
    myStack.push(10); // Stack: 10
    myStack.push(20); // Stack: 20 10
    myStack.push(30); // Stack: 30 20 10
    myStack.push(40); // Stack: 40 30 20 10
    cout << "Current Stack: ";
    myStack.print(); // Expected: 40 30 20 10
    // Testing Top and Bottom
    cout << "\nTop Element: " << myStack.top() << endl;     // Expected: 40
    cout << "Bottom Element: " << myStack.bottom() << endl; // Expected: 10
    // Testing Pop Operation (Should remove from top)
    cout << "\nPerforming Pop (Removing Top)..." << endl;
    myStack.pop();
    cout << "Stack after pop: ";
    myStack.print(); // Expected: 30 20 10

    //insertAfter and update
    cout << "\n--- Testing Extended Operations ---" << endl;
    cout << "Updating index 1 (value 20) to 100:" << endl;
    myStack.updateItem(1, 100);
    myStack.print(); // Expected: 30 100 10
    cout << "Inserting 500 after index 0:" << endl;
    myStack.InsertAfter(0, 500);
    myStack.print(); // Expected: 30 500 100 10
    // Testing Reverse
    cout << "\nReversing the Stack:" << endl;
    myStack.reverse();
    myStack.print(); // Expected: 10 100 500 30
    // Testing Sizes and State
    cout << "\n--- Testing Stack State ---" << endl;
    cout << "Stack Size: " << myStack.size() << endl;       // Expected: 4
    cout << "Is Stack Empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    // Testing Clear
    cout << "\nClearing the Stack..." << endl;
    myStack.clear();
    cout << "Is Stack Empty after clear? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

}

void testDynamicArray()
{
    //dynamic array testing
    {
        cout << "\t\t\t==============================================" << endl;
        cout << "\t\t\t\t\t Dynamic Array" << endl;
        cout << "\t\t\t==============================================" << endl;
        // ─── Constructor & Print ───────────────────────────────
        printSeparator("Constructor");
        clsDynamicArray<int> arr(5);
        cout << "Created array of size 5\n";
        cout << "Size: " << arr.size() << "\n";         // expected: 5
        cout << "isEmpty: " << arr.isEmpty() << "\n";   // expected: 0 (false)
        arr.print(); // expected: 0 0 0 0 0

        // ─── setItem ──────────────────────────────────────────
        printSeparator("setItem");
        arr.setItem(0, 10);
        arr.setItem(1, 20);
        arr.setItem(2, 30);
        arr.setItem(3, 40);
        arr.setItem(4, 50);
        arr.print(); // expected: 10 20 30 40 50

        cout << "setItem out of range: " << arr.setItem(10, 99) << "\n"; // expected: 0 (false)
        cout << "setItem negative index: " << arr.setItem(-1, 99) << "\n"; // expected: 0 (false)

        // ─── getItem ──────────────────────────────────────────
        printSeparator("getItem");
        cout << "Item at index 0: " << arr.getItem(0) << "\n"; // expected: 10
        cout << "Item at index 2: " << arr.getItem(2) << "\n"; // expected: 30
        cout << "Item at index 4: " << arr.getItem(4) << "\n"; // expected: 50
        try {
            arr.getItem(10); // should throw
        }
        catch (out_of_range& e) {
            cout << "getItem out of range caught: " << e.what() << "\n";
        }

        // ─── find ─────────────────────────────────────────────
        printSeparator("find");
        cout << "Find 30: index " << arr.find(30) << "\n";  // expected: 2
        cout << "Find 99: index " << arr.find(99) << "\n";  // expected: -1

        // ─── resize (grow) ────────────────────────────────────
        printSeparator("resize - grow to 7");
        arr.resize(7);
        arr.print(); // expected: 10 20 30 40 50 0 0
        cout << "Size: " << arr.size() << "\n"; // expected: 7

        // ─── resize (shrink) ──────────────────────────────────
        printSeparator("resize - shrink to 3");
        arr.resize(3);
        arr.print(); // expected: 10 20 30
        cout << "Size: " << arr.size() << "\n"; // expected: 3

        // ─── reverse ──────────────────────────────────────────
        printSeparator("reverse");
        arr.print(); // before: 10 20 30
        arr.reverse();
        arr.print(); // expected: 30 20 10

        // ─── InsertAtEnd ──────────────────────────────────────
        printSeparator("InsertAtEnd");
        arr.InsertAtEnd(99);
        arr.print(); // expected: 30 20 10 99

        // ─── InsertAtBeginning ────────────────────────────────
        printSeparator("InsertAtBeginning");
        arr.InsertAtBeginning(1);
        arr.print(); // expected: 1 30 20 10 99

        // ─── InsertItemAt ─────────────────────────────────────
        printSeparator("InsertItemAt");
        arr.InsertItemAt(2, 55);
        arr.print(); // expected: 1 30 55 20 10 99
        cout << "InsertItemAt out of range: " << arr.InsertItemAt(100, 77) << "\n"; // expected: 0

        // ─── InsertBefore ─────────────────────────────────────
        printSeparator("InsertBefore");
        arr.InsertBefore(2, 44);
        arr.print(); // expected: 1 30 44 55 20 10 99

        // ─── InsertAfter ──────────────────────────────────────
        printSeparator("InsertAfter");
        arr.InsertAfter(2, 77);
        arr.print(); // expected: 1 30 44 77 55 20 10 99

        // ─── deleteItemAt ─────────────────────────────────────
        printSeparator("deleteItemAt");
        arr.deleteItemAt(3); // delete 77
        arr.print(); // expected: 1 30 44 55 20 10 99
        cout << "deleteItemAt out of range: " << arr.deleteItemAt(100) << "\n"; // expected: 0

        // ─── deleteFirstItem ──────────────────────────────────
        printSeparator("deleteFirstItem");
        arr.deleteFirstItem();
        arr.print(); // expected: 30 44 55 20 10 99

        // ─── deleteLastItem ───────────────────────────────────
        printSeparator("deleteLastItem");
        arr.deleteLastItem();
        arr.print(); // expected: 30 44 55 20 10

        // ─── deleteItemByValue ────────────────────────────────
        printSeparator("deleteItemByValue");
        cout << "Delete value 55: " << arr.deleteItemByValue(55) << "\n"; // expected: 1
        arr.print(); // expected: 30 44 20 10
        cout << "Delete value 999 (not found): " << arr.deleteItemByValue(999) << "\n"; // expected: 0

        // ─── deleteItemByValue ────────────────────────────────
        printSeparator("update item by index");
        cout << "update value at index 2: " << arr.updateItem(2, 90);
        arr.print();
        cout << "value at index 2 updated to 90" << endl;

        // ─── isEmpty ──────────────────────────────────────────
        printSeparator("isEmpty");
        cout << "isEmpty (should be false): " << arr.isEmpty() << "\n"; // expected: 0

        // ─── clear ────────────────────────────────────────────
        printSeparator("clear");
        arr.clear();
        cout << "Size after clear: " << arr.size() << "\n";     // expected: 0
        cout << "isEmpty after clear: " << arr.isEmpty() << "\n"; // expected: 1

        // ─── Empty array edge cases ───────────────────────────
        printSeparator("Edge case - size 0 constructor");
        clsDynamicArray<int> emptyArr(0);
        cout << "Size: " << emptyArr.size() << "\n";         // expected: 0
        cout << "isEmpty: " << emptyArr.isEmpty() << "\n";   // expected: 1
        emptyArr.print();                                     // expected: (empty line)

        // ─── Template test with double ────────────────────────
        printSeparator("Template test - double");
        clsDynamicArray<double> dArr(3);
        dArr.setItem(0, 1.5);
        dArr.setItem(1, 2.7);
        dArr.setItem(2, 3.9);
        dArr.print(); // expected: 1.5 2.7 3.9

        // ─── Template test with string ────────────────────────
        printSeparator("Template test - string");
        clsDynamicArray<string> sArr(3);
        sArr.setItem(0, "Hello");
        sArr.setItem(1, "World");
        sArr.setItem(2, "C++");
        sArr.print(); // expected: Hello World C++

        cout << "\n========== All Tests Done ==========\n";
    }

}

void testQueueBasedArr()
{
    // Queue based on Dynamic Array testing

    cout << "\t\t\t==============================================" << endl;
    cout << "\t\t\t\t queue based on dynamic aray" << endl;
    cout << "\t\t\t==============================================" << endl;
    // ─── Push & Basic Info ───────────────────────────────
    printSeparator("Push & Size");
    clsQueueArr<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);

    cout << "Queue after pushing 10, 20, 30, 40:\n";
    myQueue.print(); // expected: 10 20 30 40
    cout << "Size: " << myQueue.size() << "\n";      // expected: 4
    cout << "isEmpty: " << myQueue.isEmpty() << "\n"; // expected: 0 (false)

    // ─── Front & Back ─────────────────────────────────────
    printSeparator("Front & Back");
    cout << "Front item: " << myQueue.front() << "\n"; // expected: 10
    cout << "Back item: " << myQueue.back() << "\n";   // expected: 40

    // ─── Pop Operations ───────────────────────────────────
    printSeparator("Pop (Delete First)");
    myQueue.pop();
    cout << "Queue after pop:\n";
    myQueue.print(); // expected: 20 30 40
    cout << "New Front: " << myQueue.front() << "\n"; // expected: 20

    // ─── Get & Update Item ────────────────────────────────
    printSeparator("Get & Update by Index");
    cout << "Item at index 1: " << myQueue.getItem(1) << "\n"; // expected: 30
    myQueue.updateItem(1, 99);
    cout << "After updating index 1 to 99:\n";
    myQueue.print(); // expected: 20 99 40

    // ─── Advanced Insertions ──────────────────────────────
    printSeparator("Insert After / Front / Back");
    myQueue.InsertAfter(0, 25); // Insert 25 after index 0 (20)
    cout << "After InsertAfter(0, 25):\n";
    myQueue.print(); // expected: 20 25 99 40

    myQueue.InsertAtFront(5);
    cout << "After InsertAtFront(5):\n";
    myQueue.print(); // expected: 5 20 25 99 40

    myQueue.InsertAtBack(100);
    cout << "After InsertAtBack(100):\n";
    myQueue.print(); // expected: 5 20 25 99 40 100

    // ─── Reverse ──────────────────────────────────────────
    printSeparator("Reverse Queue");
    myQueue.reverse();
    cout << "Queue after reverse:\n";
    myQueue.print(); // expected: 100 40 99 25 20 5

    // ─── Clear & Empty State ──────────────────────────────
    printSeparator("Clear & Empty State");
    myQueue.clear();
    cout << "Size after clear: " << myQueue.size() << "\n";      // expected: 0
    cout << "isEmpty after clear: " << myQueue.isEmpty() << "\n"; // expected: 1
    myQueue.print(); // expected: (empty line)

    // ─── Template Test with Strings ───────────────────────
    printSeparator("Template test - String Queue");
    clsQueueArr<string> sQueue;
    sQueue.push("Dima");
    sQueue.push("Programming");
    sQueue.push("C++");

    cout << "String Queue:\n";
    sQueue.print(); // expected: Dima Programming C++
    cout << "Front: " << sQueue.front() << "\n"; // expected: Dima

    sQueue.pop();
    cout << "After pop:\n";
    sQueue.print(); // expected: Programming C++

    cout << "\n========== All Queue Tests Done ==========\n";


}
    int main()
{
    //testing clsDbLinkedList.h
    // testDbLinkedList();
    
    //testing queue
    //testQueue();

    //testing stack
    //testStack();

    //testing dynamic array
    //testDynamicArray();
    
    //test queue based array
   // testQueueBasedArr();
}
