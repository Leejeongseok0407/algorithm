#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

//�ʱ�ȭ ���ִ� �Լ�
void ListInit(List* plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;

}

//tail�� ����
void LInsert(List* plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    plist->numOfData++;
}

//head�� ����
void LInsertFront(List* plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    plist->numOfData++;
}

//ó�� ������ ���
//flase�� ��µɰ��� ������(���)�� ���� ���
//true�� �ְ� ���� �ε����� cur�� before�� �־���
int LFirst(List* plist, Data* pdata) {
    if (plist->tail == NULL)
        return FALSE;

    plist->cur = plist->tail->next;
    plist->before = plist->tail;

    *pdata = plist->cur->data;
    return TRUE;
}

//���� �ε����� ������ ���
int LNext(List* plist, Data* pdata) {
    if (plist->tail == NULL)
        return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

//�����͸� ������
//���� �����Ͱ� ������ ����ų ��� �����ؼ� ¥����.
Data LRemove(List* plist) {

    Data DataTemp = plist->cur->data;
    Node *NodeTemp = plist->cur;
    
    if (NodeTemp == plist->tail) {
        if (plist->tail == plist->tail->next) {
            plist->tail = NULL;
        }
        else {
            plist->tail == plist->before;
        }
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(NodeTemp);
    plist->numOfData--;
    return DataTemp;
}

int LCount(List* plist) {
    return plist->numOfData;
}
