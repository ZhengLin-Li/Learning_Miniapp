#ifndef FINAL_HUFFMANCODE_H
#define FINAL_HUFFMANCODE_H

#include"in_outstream.h"
#include <iostream>
#include<fstream>
#include <vector>
#include <cstring>
using namespace std;

typedef char **HuffCode;

typedef struct TreeNode {
    int left = -1, right = -1;
    char ch = '0';
    int parent = -1;    // -1��ʾ�޸��ڵ�
    int weight = 0;
} TreeNode;
void initLeafs(TreeNode *p, int numLeafs,LinkNode* head) {
    // ��pָ���������ǰnumLeafs��Ԫ�ؽ��г�ʼ��
    LinkNode* current=head->next;
    for (int i = 0; i < numLeafs; i++) {
        p[i] = {-1,-1,current->key,-1,current->number};//��ʼ��
        current = current->next;
    }
    cout << "---------------" << endl;
}
void searchMin(const TreeNode *p, int nums, int &min1, int &min2) {
    // ��pָ���nums��Ԫ�ص�������
    // ����Ȩֵ��С�������ڵ�
    // ����֤��parentΪ�գ������ڵ�

    // �����ҵ������е�һ�����ڵ㣬��parentΪ�յĽڵ�
    // ���˸��ڵ���Ϊweight��С�ڵ㣬�����������㷨
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1) {
            min1 = i;
            break;
        }
    }
    // Ѱ��������Ȩֵ��С�ĸ��ڵ���Ϊmin1
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1 && p[i].weight < p[min1].weight) {
            min1 = i;
        }
    }
    // Ѱ�ҵ����и��ڵ���Ȩֵ��С��weight1�Ժ󣬼���Ѱ�ҵڶ���
    // �ҵ������е�һ�����ڵ㣬��Ϊ��ʼȨֵ��С��λ��min2
    // ���뱣֤��min2������min1
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1 && i != min1) {
            min2 = i;
            break;
        }
    }

    // Ѱ�������г�ȥmin1����Ȩֵ��С�ĸ��ڵ�
    for (int i = 0; i < nums; i++) {
        if (p[i].parent == -1 && p[i].weight < p[min2].weight && i != min1) {
            min2 = i;
        }
    }
}
int createHuffman(TreeNode *p, int numLeafs,LinkNode* head) {
    // 1����ʼ��ǰnumLeafs�����ڵ㣬ָ����Ȩֵ
    initLeafs(p, numLeafs,head);

    // �������ڴ洢Ȩֵ��С�����ڵ��λ��
    int minPos1, minPos2;

    // 2��numLeafs�����ڵ���Ҫ����numLeafs-1�κϲ�
    for (int i = 0; i < numLeafs - 1; i++) {
        // 3��Ѱ��Ȩֵ��С��ǰ�����ڵ�
        // Ѱ�ҵķ�Χ��ǰnumLeafs+i���ڵ�
        // �������Ѿ������Ľڵ�
        searchMin(p, numLeafs + i, minPos1, minPos2);
        // 4����numLeafs+1�������¸��ڵ�
        p[numLeafs + i].weight = p[minPos1].weight + p[minPos2].weight;
        p[numLeafs + i].left = minPos1;
        p[numLeafs + i].right = minPos2;
        // ����ǰȨֵ��С�������ڵ��parentָ���´����ĸ��ڵ�
        // ��ʾ�䲻���Ǹ��ڵ㣬���ٲ���ϲ�
        p[minPos1].parent = numLeafs + i;
        p[minPos2].parent = numLeafs + i;
    }
    return numLeafs;
}
void printHuffman(TreeNode *p, int numNodes) {
    // ������еĽڵ㣬���ڵ���Ϣ
    for (int i = 0; i < numNodes; i++) {
        cout << "�±꣺" << i <<"\tȨֵ��" << p[i].weight
        << "\t�ַ���" << p[i].ch << "\t���ڵ㣺" <<
        p[i].parent << "\t���ӽڵ㣺" << p[i].left <<
        "\t���ӽڵ㣺" << p[i].right << endl;
    }
}

void printPreOrder(TreeNode *p, int index) {
    if (p == NULL)
        return;
    cout << index;
    if (p[index].left != -1 ) {
        printPreOrder(p, p[index].left);
    }
    if ( p[index].right != -1) {
        printPreOrder(p, p[index].right);
    }
}


int Huffumancode(TreeNode *p,HuffCode &HC,LinkNode* head) {
    int numberLeafs;
    LinkNode* current = head;//��ǰ�ڵ�
    for(numberLeafs=-1;current!=NULL;current=current->next){
        numberLeafs++;
    }
    createHuffman(p, numberLeafs,head);
    printHuffman(p, numberLeafs * 2 - 1);
    HC = (char **) malloc((numberLeafs) * sizeof(char *));
    //�ݴ����
    char *code;  //�ݴ�����
    code = (char *) malloc(numberLeafs * sizeof(char));//ʹ���˵�0��Ԫ

    code[numberLeafs - 1] = '\0';
    int i;
    for (i = 0; i < numberLeafs; i++) {
        int start = numberLeafs - 1;
        for (int c = i, f = p[c].parent; f != -1; c = p[c].parent, f = p[c].parent) {//��Ҷ��ɨ�赽��
            if (p[f].left == c) {
                code[--start] = '0';
            } else if (p[f].right == c) {
                code[--start] = '1';
            } else {//����ʲôҲ����
                ;
            }
        }

        HC[i] = (char *) malloc(strlen(code) * sizeof(char));//��̬�ط����ڴ����Ź��������������
        strcpy(HC[i], &code[start]);//��ʱ��ŵ�code����ֵ���Ƹ����������������
    }
    for (i = 0; i < numberLeafs; i++) {
        printf("%s\n", HC[i]);
    }
    return (numberLeafs * 2 - 1);
}

#endif //FINAL_HUFFMANCODE_H
