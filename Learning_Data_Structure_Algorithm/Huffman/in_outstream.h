//
// Created by Zhenglin Li on 2020/12/4.
//

#ifndef FINAL_IN_OUTSTREAM_H
#define FINAL_IN_OUTSTREAM_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include <cstring>


using namespace std;

//����ڵ㶨��
typedef struct LNode {
    char key{};//�ַ�
    int number{};//Ȩֵ
    LNode *next = nullptr;
}LinkNode;

//����һ���½��
LinkNode* CreateNode() {
    LinkNode* newNode = (LNode *) malloc(sizeof(LNode));
    if (newNode != nullptr) {
        newNode->key = '0';
        newNode->number = 0;
        newNode->next = nullptr;
    }
    return newNode;
}

//��ȡ�ļ�����Ϣ����������ͷָ��
LinkNode* in_outstream() {
    char c;
    bool flag;
    LinkNode* head = nullptr;//ͷָ��
    LinkNode* current = head;//��ǰ���
    ifstream in_stream;//Դ�ļ�
    ofstream out_stream;//ofstream�๹�캯�������Ϊ0����ʧ��
    in_stream.open(R"(D:\code is here\Final\compress.txt)");
    //��Դ�ļ�����
    if (in_stream.fail()) {
        cout << "opening compress.txt failure";
        exit(1);
    }
    out_stream.open(R"(D:\code is here\Final\CharsAndNums.txt)");
    //������ļ�����
    if (out_stream.fail()) {
        cout << "opening CharsAndNums.txt failure";
        exit(1);
    }
    //�����ļ������ζ�ȡÿ���ַ�
    while (in_stream.get(c)) {
        cout << c;
        flag = true;//��־c��������������
        //���������ж�c�Ƿ��Ѿ�������������
        for (current = head; current != nullptr; current = current->next) {
            //c�Ѿ����ڣ�c��Ӧ��Ƶ����1
            if (current->key == c) {
                current->number++;
                flag = false;//flag��Ϊfalse
                break;//����forѭ��
            }
        }
        //����������c�����ڣ��򴴽��½ڵ�
        if (flag) {
            LinkNode* newnode = CreateNode();
            newnode->key = c;
            newnode->number++;
            newnode->next = head;
            head = newnode;//����ͷָ������ǰ�ƶ������������Ҫһ��ͷָ��
        }
    }
    LinkNode* head1 = CreateNode();//����һ��ͷָ����ǰ��
    head1->next = head;
    cout << "The result:" << endl;//����̨���
    //���������ļ�
    out_stream << "�ַ�" << "\tƵ��" << endl;
    //���������ֱ����������̨���ļ���
    for (current = head; current != nullptr; current = current->next) {
        cout << current->key << ' ' << current->number << '\n';
        out_stream.put(current->key);
        out_stream << "\t" << current->number << endl;
    }

    //�ر���
    in_stream.close();
    out_stream.close();
    return head1;//���ش����Ȩֵ���ַ�������ͷָ��
}

#endif //FINAL_IN_OUTSTREAM_H
