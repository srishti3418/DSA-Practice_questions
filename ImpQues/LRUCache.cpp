#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> ourmap;
class node
{
public:
    node *next;
    node *prev;
    node(int key, int val)
    {
        ourmap[key] = val;
        next = NULL;
        prev = NULL;
    }
};

class LRU
{
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int capacity;
    int size;
    unordered_map<int, node *> store;

public:
    LRU(int cap)
    {
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
        capacity = cap;
        size = 0;
    }
    void insert(int key, int val)
    {
        node *curr = NULL;
        curr = new node(key, val);
        node *temp = head->next;
        head->next = curr;
        curr->prev = head;
        curr->next = temp;
        temp->prev = curr;
        store[key] = curr;
    }

    void put(int key, int val)
    {

        if (store.find(key) == store.end())
        {
            if (size < capacity)
            {
                //insert a new node which is present just after head
                insert(key, val);
                size++;
            }
            else
            {
                //delete a LRU node which is present just before tail
                node *temp = tail->prev;
                tail->prev = temp->prev;
                temp->prev->next = tail;
                store[key] = NULL;
                //insert a new node just after head
                insert(key, val);
            }
        }
        else
        {
            //delete the node having key as the new key
            node *temp = store[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            //insert a new node just after the head
            insert(key, val);
        }
    }
    int get(int key)
    {
        if (store.find(key) == store.end())
            return -1;
        else
        {
            node *temp = store[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            insert(key, ourmap[key]);
            return ourmap[key];
        }
    }
};

int main()
{
    LRU L1(3);
    L1.put(1, 10);
    L1.put(3, 15);
    L1.put(2, 12);
    cout << L1.get(3) << endl;
    L1.put(4, 20);
    cout << L1.get(2) << endl;
    L1.put(4, 25);
}