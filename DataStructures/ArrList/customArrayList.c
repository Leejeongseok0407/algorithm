#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
    plist->numOfData = 0;
    plist->curPosition = -1;
}

void LInsert(List* plist, LData data) {
    //����ó�� ������
    if (plist->numOfData > LIST_LEN) {
        printf("���� �Ұ�");
        return;
    }
    plist->arr[plist->numOfData] = data;
    plist->numOfData++;
}

int LFirst(List* plist, LData* pdata) {
    if (plist->numOfData == 0) {
        return FALSE;
    }
    
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}
int LNext(List* plist, LData* pdata) {
    if (plist->curPosition >= plist->numOfData - 1)
        return FALSE;
    //*pdata�� ����ϴ� �κ��ε� pdata�� ��
    //������ ���� ������ �ٽ� �����Ұ�.
    *pdata = plist->arr[++(plist->curPosition)];
    return TRUE;
};

LData LRemove(List* plist) {
    LData temp = plist->arr[plist->curPosition];
    for (int i = plist->curPosition; i < (plist->numOfData)-1; i++) {
        plist->arr[i] = plist->arr[i + 1];
    }
    plist->numOfData--;
    //������ �κ� ���� �ǵ����� ������ ��ĭ ������ �� �����Ե� �̰� ���� ��� 3���� �����ϰ� 4���� �����ϹǷ� �����δ� ������ ��ĭ ������ �����ϴ°��̵�
    plist->curPosition--; 
    return temp;
};
int LCount(List* plist) {
    return plist->numOfData; 
}