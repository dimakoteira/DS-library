📚 Data Structures C++ Library
A robust, template-based C++ library providing fundamental data structures implemented from scratch. This project showcases deep proficiency in Object-Oriented Programming (OOP), Manual Memory Management, and Generic Programming.

Note: This library offers dual implementations for linear structures (Linked-List based vs. Array based), allowing for performance comparisons in memory allocation and access time.

🚀 Key Features
Generic Programming: Full support for templates (template <typename T>).

Memory Efficiency: Strict manual memory management with proper destructors and clear() methods to prevent memory leaks.

Modular Architecture: High reusability by building complex structures (Queues/Stacks) on top of base containers (Arrays/Lists).

🛠 Included Structures
1. Dynamic Array (clsDynamicArray.h)
A custom implementation of a resizable array.

Operations: resize, InsertAtEnd, InsertAtBeginning, InsertBefore/After, deleteItemAt, reverse, and find.

Focus: Direct memory allocation using new[] and delete[].

2. Doubly Linked List (clsDbLinkedList.h)
A bidirectional list allowing efficient traversal and node manipulation.

Operations: InsertAtBeginning/End, DeleteNode, Reverse, and Find.

Advanced: Includes index-based access (getItem, updateItem) with exception handling.

3. Queue Implementations (FIFO)
clsMyQueue.h: Implemented using Doubly Linked List logic.

clsQueueArr.h: Implemented using the Dynamic Array (Composition-based).

Showcases how to wrap a raw array into a Queue structure.

4. Stack Implementation (LIFO)
clsMyStack.h: Inherits from clsMyQueue to demonstrate Inheritance and Code Reuse in OOP.

💻 How to Use
Simply include the required header from the ../includes/ folder.

C++
#include "../includes/clsQueueArr.h"

int main() {
    clsQueueArr<int> myQueue;
    
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    
    myQueue.pop(); // Deletes 10
    myQueue.print(); // Output: 20 30
    
    return 0;
}
🧠 Skills Demonstrated
Pointer Manipulation: Handling complex pointers for linked lists.

Memory Management: Managing dynamic arrays and avoiding leaks.

Composition vs. Inheritance: Using the right OOP pattern for each structure.

Unit Testing: Rigorous testing of edge cases (Empty structures, Out-of-range access).
👤 Author
Dima Koteira Information Engineering Student at University of Homs
[linkedIn profile](https://www.linkedin.com/public-profile/settings/?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_self_edit_contact_info%3Bj6PqA2HMQqyqgU1PoQVl7w%3D%3D)
