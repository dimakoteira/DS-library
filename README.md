Data Structures Library (C++)
A robust, template-based C++ library providing fundamental data structures implemented from scratch using Object-Oriented Programming (OOP) principles. This project was developed as part of my deep dive into Memory Management and Algorithm Optimization.

🚀 Features
Generic Programming: All structures use templates <T> to support any data type.

Memory Efficiency: Manual memory management with proper allocation and deallocation (destructors/clear methods).

OOP Design: Clean encapsulation and modularity.

🛠 Included Libraries
1. Doubly Linked List (clsDbLinkedList.h)
A bidirectional list that allows traversal in both directions.

Key Operations: InsertAtBeginning, InsertAtEnd, InsertAfter, DeleteNode, Reverse, and Find.

Advanced: Includes index-based access (getItem, updateItem) and error handling.

2. Queue (clsMyQueue.h)
A FIFO (First-In-First-Out) container implemented using the Doubly Linked List.

Key Operations: push (enqueue), pop (dequeue), front, back, and isEmpty.

3. Stack (clsMyStack.h)
A LIFO (Last-In-First-Out) container (Implemented using the same core DLL logic by inherenting clsMyQueue).

Key Operations: push, pop, top, and size.

💻 How to Use
Simply include the header files in your project:

C++
#include "includes/clsDbLinkedList.h"
#include "includes/clsMyQueue.h"
#include "includes/clsMyStack.h"

int main() {
    clsMyQueue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.pop(); 
    Q.print(); 
    return 0;
}

Pointer Manipulation

Dynamic Memory Management

Data Structure Implementation (FIFO/LIFO)

👤 Author
Dima Koteira Information Engineering Student at University of Homs
[linkedIn profile](https://www.linkedin.com/public-profile/settings/?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_self_edit_contact_info%3Bj6PqA2HMQqyqgU1PoQVl7w%3D%3D)
