#include "iostream"
#include <string>
using namespace std;

class Person
{
    //1��ȫ�ֺ��������Ԫ   ����ʵ��
    friend void printPerson(Person & p)
    {
        cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
    }


    //ȫ�ֺ��������Ԫ  ����ʵ��
    friend void printPerson2(Person & p);

public:

    Person(char* name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }


private:
    char* m_Name;
    int m_Age;

};

void printPerson2(Person & p)
{
    cout << "����ʵ�� ---- ������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
}

//1��ȫ�ֺ���������ʵ��
void test01()
{
    Person p("Tom", 20);
    printPerson(p);
}


//2��ȫ�ֺ���������ʵ��
void test02()
{
    Person p("Jerry", 30);
    printPerson2(p);
}

int main() {

    //test01();

    test02();

    return 0;
}