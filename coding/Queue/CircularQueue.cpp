/*
    Design your implementation of the circular queue. The circular queue is a linear data
    structure in which the operations are performed based on FIFO (First In First Out) principle,
    and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
*/

/*
    Strategy:
        Keep array of 1000
        Have head and tail
        EnQueue:
            add it to tail and move tail
        DeQueue:
            get current head
            move Head
        Front
            give head
        Rear
            give tail
        isEmpty
            head and tail -1
        isFull
            tail-head = size

    // implementation
        // size:
        // curSize : keep track of current size which can be used in empty and full
        //      curSize : 0 (empty) : size(full)
        // head,tail - with -1
        // enqueue
            size:3
            head=tail=0 curSize=1
            head=0 tail=1 curSize=2
            head=0 tail=2 curSize=3
            isFull ()=> true

            head=1 tail=2 (dequeue) cursize=2
                // if tail/head reaches end and and not full then
                // tail will reset to 0
            head=1 tail=0 (enqueue) cursize=3

        // dequeue
            head=1
            head=2

        // Front
            [head]
        // Rear
            [tail]

*/

#include <stdio.h>
class MyCircularQueue
{
    int *data;
    int head, tail;
    int size, curSize;

public:
    MyCircularQueue(int k)
    {
        this->data = new int[k];
        this->head = -1;
        this->tail = -1;
        this->size = k;
        this->curSize = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (head == -1)
        {
            head++;
        }

        tail++;
        if (tail == this->size)
        {
            tail = 0; // we have reached with space means make tail to 0
        }
        this->data[tail] = value;
        this->curSize++;
        return true;
    }

    bool deQueue()
    {
        if (this->isEmpty())
        {
            return false;
        }

        head++;
        if (head == this->size)
        {
            head = 0;
        }
        this->curSize--;
        return true;
    }

    int Front()
    {
        if (this->isEmpty())
        {
            return -1;
        }
        return data[head];
    }

    int Rear()
    {
        if (this->isEmpty())
        {
            return -1;
        }
        return data[tail];
    }

    bool isEmpty()
    {
        return this->curSize == 0 ? true : false;
    }

    bool isFull()
    {
        return this->curSize == this->size ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
void assert(bool actual, bool expected, char *msg)
{
    if (actual != expected)
    {
        printf("[failed]: %s expected:%d actual:%d\n", msg, expected, actual);
    }
    else
    {
        printf("[success] %s\n", msg);
    }
}
void assert(int actual, int expected, char *msg)
{
    if (actual != expected)
    {
        printf("[failed]: %s expected:%d actual:%d\n", msg, expected, actual);
    }
    else
    {
        printf("[success] %s\n", msg);
    }
}

void testForMultiple()
{
    MyCircularQueue queue(3);
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);

    queue.deQueue();
    queue.deQueue();

    queue.enQueue(4);
    assert(queue.Front(),3,"3 should be front");
}
void testRear()
{
    MyCircularQueue queue(3);
    assert(queue.Rear(),-1, "No elements exists");
    queue.enQueue(10);
    assert(queue.Rear(),10, "10 exists at front");
}

void testFront()
{
    MyCircularQueue queue(3);
    assert(queue.Front(),-1, "No elements exists");
    queue.enQueue(10);
    assert(queue.Front(),10, "10 exists at front");
}

void testQueueEmpty()
{
    MyCircularQueue queue(3);
    queue.enQueue(1);
    queue.deQueue();
    assert(queue.isEmpty(), true, "Queue should be empty");
}
void testQueueFull()
{
    MyCircularQueue queue(3);
    queue.enQueue(1);
    queue.enQueue(1);
    queue.enQueue(1);

    assert(queue.isFull(), true, "Queue should be full");
}

void simpleTest()
{
    MyCircularQueue queue(3);
    assert(queue.isEmpty(), true, "should empty on simple");
    assert(queue.deQueue(), false, "first dequeu should be false");
    assert(queue.enQueue(1), true, "1 is enqued.");
    assert(queue.Front(), 1, "1 should be front.");
    assert(queue.Rear(), 1, "1 should be rear.");
}

void main()
{
    simpleTest();
    testQueueFull();
    testQueueEmpty();
    testFront();
    testRear();
    testForMultiple();
}