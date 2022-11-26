/*
    Design linked list.
*/
#include <stdio.h>

class Node
{
public:
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    int val;
    Node *next;
};

class MyLinkedList
{
private:
    Node *head;
    Node *tail;

private:
    Node *getAt(int index, int *pos)
    {
        int i = 0;
        *pos = -1;
        Node *node = head;
        while (node != NULL)
        {
            if (index == i)
            {
                *pos = i;
                return node;
            }
            node = node->next;
            i++;
        }

        return NULL;
    }

public:
    MyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int get(int index)
    {
        int pos = -1;
        Node *node = getAt(index, &pos);
        if (node != NULL)
        {
            return node->val;
        }

        return -1;
    }

    void addAtHead(int val)
    {
        Node *node = new Node(val);
        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        Node *prevHead = head;
        head = node;
        head->next = prevHead;
    }

    void addAtTail(int val)
    {
        Node *node = new Node(val);
        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        // printf("current tail:%d\n", tail->val);

        tail->next = node;
        tail = node;
        // printf("new  tail:%d\n", tail->val);
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        int i = 0;
        Node *node = head;
        int len = 0;
        while (node != NULL)
        {
            len++;
            if (index == (i + 1))
            {
                break;
            }
            node = node->next;
        }

        if (node)
        {
            Node *newNode = new Node(val);
            Node *nextNode = node->next;
            node->next = newNode;
            newNode->next = nextNode;
            if (node == tail)
            {
                tail = newNode; // Move tail.
            }
        }
        else if (index == len)
        {
            addAtTail(val);
        }
    }

    void deleteAtIndex(int index)
    {
        Node *node = head;
        Node *prev = NULL;
        int i = 0;
        while (node != NULL)
        {
            if (index == i)
            {
                break;
            }
            prev = node;
            node = node->next;
            i++;
        }

        if (node == NULL)
        {
            return;
        }
        //   |1|
        //   head = 1          -> head = NULL
        //   tail = 1          -> tail = NULL
        //   node = 1;
        //   prev = NULL;
        if (node == head)
        {
            head = head->next;
        }
        if (node == tail)
        {
            tail = prev;
        }

        if (prev != NULL)
        {
            prev->next = node->next;
        }

        delete node;
    }

    void print()
    {
        Node *node = head;
        while (node)
        {
            printf("%d->", node->val);
            node = node->next;
        }

        printf("\n");
    }

    Node *reveseInternal(Node *node)
    {
        // 1->2->3->4->5
        Node *current = node;
        if (current == NULL)
        {
            return NULL;
        }

        // A->B->C->D->E->NULL
        // c:A n:B
        // B->A
        // c:B n:C
        // C->B
        // 
        // E
        Node* next = current->next;
        current->next = NULL;
        while (next != NULL)
        {
            Node* temp = next->next;
            next->next = current;   
            current = next;
            next = temp;
        }

        return current;
    }
    void reverse()
    {
        this->head = reveseInternal(this->head);
    }
};

void testEmpty(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.print();
    printf("____________________________________\n");
}

void addAtHeadDelete(char *message)
{
    printf("%s\n", message);
    printf("________________Adding____________________\n");
    MyLinkedList list;
    list.addAtHead(1);
    list.print();
    printf("_________________Deleting___________________\n");
    list.deleteAtIndex(0);
    list.print();
    printf("____________________________________\n");
}

void testDeleteAtInvalidIndex(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.deleteAtIndex(10);
    list.print();
    printf("____________________________________\n");
}

void testaddMultiple(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);
    list.addAtHead(4);
    list.print();
    printf("____________________________________\n");
}

void testaddMultipleDelete(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);
    list.addAtHead(4);
    list.print();
    printf("________________Delete____________________\n");
    list.deleteAtIndex(0);
    list.deleteAtIndex(0);
    list.print();
    printf("____________________________________\n");
}

void testDeleteAtTail(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);
    list.addAtHead(4);
    list.print();
    printf("________________Delete____________________\n");
    list.deleteAtIndex(2);
    list.deleteAtIndex(2);
    list.print();
    printf("____________________________________\n");
}

void testDeleteAll(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);
    list.addAtHead(4);
    list.print();
    printf("________________Delete____________________\n");
    list.deleteAtIndex(0);
    list.deleteAtIndex(0);
    list.deleteAtIndex(0);
    list.deleteAtIndex(0);
    list.print();
    printf("____________________________________\n");
}

void testGetAt(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);
    list.addAtHead(4);
    list.print();
    printf("________________GetAt____________________\n");
    printf("0 index:%d\n", list.get(0));
    printf("1 index:%d\n", list.get(1));
    printf("2 index:%d\n", list.get(2));
    printf("3 index:%d\n", list.get(3));
    printf("4 index:%d\n", list.get(4));
    printf("____________________________________\n");
}

void testAddTail(char *message)
{
    printf("%s\n", message);
    printf("____________________________________\n");
    MyLinkedList list;
    list.addAtTail(1);
    list.addAtTail(2);
    list.addAtTail(3);
    list.addAtTail(4);
    printf("____________________________________\n");
    list.print();
}

void test1()
{
    MyLinkedList list;
    list.addAtHead(1);
    list.print();
    printf("-------------------\n");
    list.addAtTail(3);
    list.print();
    printf("-------------------\n");
    list.addAtIndex(1, 2);
    list.print();
    printf("-------------------\n");
    printf("at 1:%d\n", list.get(1));
    list.deleteAtIndex(1);
    printf("-------------------\n");
    printf("at 1:%d\n", list.get(1));
}

/*
["MyLinkedList","addAtHead","addAtIndex","get","addAtHead","addAtTail","get","addAtTail",
"get","addAtHead","get","addAtHead"]
[[],[5],[1,2],[1],[6],[2],[3],[1],[5],[2],[2],[6]]
*/
void test2()
{
    MyLinkedList list;
    list.addAtHead(5);
    list.addAtIndex(1, 2);
    printf("get:1:%d\n", list.get(1));
    list.addAtHead(6);
    list.addAtTail(2);
    list.print();
    printf("-------------------------\n");
    printf("get:3:%d\n", list.get(3));
    return;
    list.addAtTail(1);
    list.print();
    printf("-------------------------\n");
    printf("get:5:%d\n", list.get(5));
    list.addAtHead(2);
    printf("get:2:%d\n", list.get(2));
    list.addAtHead(6);
    list.print();
    printf("-----------------------------\n");
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
void reverse()
{
    MyLinkedList list;
    // 5,6,1,8,4,5
    list.addAtHead(5);
    list.addAtTail(6);
    list.addAtTail(1);
    list.addAtTail(8);
    list.addAtTail(4);
    list.addAtTail(5);
    // for (int i = 5; i > 0; i--)
    // {
    //     list.addAtHead(i);
    // }
    list.print();
    printf("----------- Reversed -----------------\n");
    list.reverse();
    list.print();
}

void main()
{
    // testEmpty("Empty list.");
    // addAtHeadDelete("Add at Head and Delete");
    // testDeleteAtInvalidIndex("Deleting at wrong index");
    // testaddMultiple("Add multiple");
    // testaddMultipleDelete("Add multiple, delete some");
    // testDeleteAtTail("Delete at tail");
    // testDeleteAll("Delete all");
    // testGetAt("get at");
    // testAddTail("Add at tail");

    // test1();
    // test2();
    reverse();
}