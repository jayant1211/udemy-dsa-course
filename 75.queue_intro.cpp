//works on principle of fifo
//has two ends - front and end
//insertion is done from end
//deletion is done from front


/**
 * QUEUE ADT
 * 
 * Data : 
 * 1. space for storing elements
 * 2. front - for deletion
 * 3. rear pointer - insertion
 * 
 * Operations:
 * 1.enqueue(x)
 * 2.dequeue()
 * 3.isEmpty()
 * 4.isFull()
 * 5.first()
 * 6.last()
 * 
 * Can be implemented using 2 physical data structures:
 * Arrays and Linked List       
*/


/**
 * USING SINGLE POINTER
 * array of fixed size
 * one pointer - rear only
 * 
 * process - initiate rear=-1, enqueue(x);rear++;
 * 
 * Insertion - O(1)
 * 
 * Disadvantage - 
 * cannot delete elements efficiently - delete first element -> shift all elements to left for filling holes - O(n)
 * 
*/

/**
 * USING TWO POINTERS
 * array of fixed size
 * two pointers - front and rear
 * 
 * process - rear=front=-1; if(enqueue(x)) rear++; if(dequeue()) front++; delete that element.
 * 
 * Insertion - O(1)
 * Deletion - O(1)
 * 
 * 
 * queue is empty -> front == rear (front is pointting prior to first element)
 * queue is full -> rear == size-1
 * Disadvantage - 
 * 
*/


