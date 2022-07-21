#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
// pass
struct  LinkList
{
    int valuee;
    LinkList* next;
    LinkList(int x) : valuee(x), next(nullptr) {}
};
class MyLinkedList {
private:
    int len;
    LinkList *head,*tail;
public:
    
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    
    int get(int index) {
        if(index>len-1) return -1;
        
        LinkList* curr = head;
        while(index>0 && curr!=nullptr)
        {
            curr = curr->next;
            index--;
        }
        return curr->valuee;
    }
    
    void addAtHead(int val) {
        LinkList* newHead = new LinkList(val);
        newHead->next = head;
        if(head == nullptr){
            tail = newHead;
        }
        head = newHead;
        len++;
    }
    
    void addAtTail(int val) {
        LinkList* newTail = new LinkList(val);
        tail = newTail;
        if(head == nullptr){
            head = newTail;
            
            len++;
            return;
        }
        tail->next = newTail;
        len++;
    }
    
    void addAtIndex(int index, int val) 
    {
        LinkList* temp = new LinkList(val);
        if(index>len) return;
        
        else if(index==0)
        {
            temp->next = head;
            head = temp;
            len++;
        }
        
        else 
        {
        LinkList* curr = head;
        while(index>1 && curr!=nullptr)
        {
            curr=curr->next;
            index--;
        }
        
        temp->next = curr->next;
        curr->next = temp;
        len++;
      }
    }
    
    void deleteAtIndex(int index) {
        if(index>=len) return;
        
        else if(index==0)
        {
            LinkList* temp = head;
            head = head->next;
            delete(temp);
            len--;
        }
        
        else
        {
            LinkList* curr = head;
            while(index>1 && curr!=NULL)
            {
                curr = curr->next;
                index--;
            }
            LinkList* temp;
            temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
            len--;
        }
    }
};