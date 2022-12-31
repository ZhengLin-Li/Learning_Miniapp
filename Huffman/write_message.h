#ifndef FINAL_WRITE_MESSAGE_H
#define FINAL_WRITE_MESSAGE_H

#include <cstdio>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include <cstring>

#define maxmum 100000//��������������ֵ

int printPreOrder(TreeNode *p, int index, char putASCII[], int i) {

    if (p == NULL)
        return -1;
    //  cout << index;
    if (p[index].left != -1) {
        i = printPreOrder(p, p[index].left, putASCII, i);
    }
    if (p[index].right != -1) {
        i = printPreOrder(p, p[index].right, putASCII, i);
    } else {
        putASCII[i++] = p[index].ch;
    }
    return i;

}

int print10(TreeNode *p, int index, char array[], int i) {

    if (p == NULL)
        return -1;
    if (p[index].left != -1) {
        array[i++] = '1';
        i = print10(p, p[index].left, array, i);
    }
    if (p[index].right != -1) {
        i = print10(p, p[index].right, array, i);
    } else
        array[i++] = '0';
    return i;
}

int code_return(HuffCode &HC, LinkNode *head, char c) {
    LinkNode *current = head->next;
    for (int i = 0; current != nullptr; i++, current = current->next) {
        if (c == current->key) {
            return i;
        }
    }
}

void write_message(int m, TreeNode *p, LinkNode *head, HuffCode &HC) {
    char s[maxmum] = {'\0'};
    char c;
    LinkNode *current = head;
    char array[maxmum] = {'\0'};
    ofstream write_out;//�����Ϣ�ļ�
    ofstream write1_out;//���ѹ���ļ�
    ifstream in_out;
    //������ļ�����
    write_out.open(R"(D:\code is here\Final\config.txt)");
    write1_out.open(R"(D:\code is here\Final\Only0And1.txt)");
    in_out.open(R"(D:\code is here\Final\compress.txt)");
    if (write_out.fail()) {
        cout << "opening config.txt failure";
        exit(1);
    }
    if (!write1_out) {
        cout << "opening Only0And1.txt failure";
        exit(1);
    }
    if (in_out.fail()) {
        cout << "opening compress.txt failure";
        exit(1);
    }
    write_out << m;
    // cout<<m<<endl;
    int i = m;
    int j = 0;//���������preoder��i
    current = head->next;
    print10(p, m - 1, array, j);
    cout << "��ӡ�����������10ֵ����Ӧ�������±�" << endl;
    for (i = 0; i < m; i++) {
        write_out << array[i];
        cout << array[i] << " " << i << endl;//��ӡ�����������10ֵ������Ӧ�������±꣬������
    }
    //��ӡ��ASCII�ַ��������ļ�ĩ��,δ��������************************
    int k = 0;
    char putASCII[50000] = {0};
    printPreOrder(p, m - 1, putASCII, k);
    cout << "��ӡ��ASCII����˳��" << endl;
    for (k = 0; putASCII[k] != '\0'; k++) {
        printf("%d---%c",putASCII[k],putASCII[k]);
        write_out.put(putASCII[k]);
    }
    write_out.close();
    while (in_out.get(c)) {
        int k;
        k = code_return(HC, head, c);
        cout << endl << "outputting HC[k]" << HC[k] << endl;
        write1_out << HC[k];
    }
    in_out.close();
    write1_out.close();
}

#endif //FINAL_WRITE_MESSAGE_H
