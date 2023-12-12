/*
  �������� ��� ��������, ��� ���� ��� ������� �������� ����������� ��� ��,
  �� ���������� ���������� ��������� ����� ���� ����, �� ���� �� ���� ��������� �����, ������������.
  ϳ������: �������������� std::vector ��� ��������� ���������� � ����.
 �� ��������� ������ ����� ���������� ����������� ���������� � ������ ����� � �����.
*/
#include <iostream>
#include <vector>
class Worker
{
protected:
    std::string name;
public:
    Worker(std::string n) : name(n) {}

    std::string getName() { return name; }
    // ����� ������ �������� ���������
};
class Department
{
    std::vector <std::string> employee;
public:
    Department(){
        std::cout << "Department was created!" << std::endl;
        std::cout << std::endl;
    }
    ~Department() {
        std::cout << "Department was destroyed!" << std::endl;
        std::cout << std::endl;
    }
    void add(Worker* work) {
        Worker worker(*work);
        employee.push_back(worker.getName());
    }

    void show(int id) {
        std::cout << employee.at(id) << std::endl;
    }

    int vectorLength() { return employee.size(); }
};
int main()
{
    system("chcp 1251");
    // ��������� ���������� ���� ������� �������� ����� Department
    Worker* w1 = new Worker("����");
    Worker* w2 = new Worker("������");
    Worker* w3 = new Worker("�����");
    Worker* w4 = new Worker("�����");

    std::cout << w1->getName() << " ������!\n";
    std::cout << w2->getName() << " ������!\n";
    std::cout << w3->getName() << " ������!\n";
    std::cout << w4->getName() << " ������!\n";
    std::cout << std::endl;

    {
        // ��������� ³��� � �������� ���������� �� ��������� ������������
        Department department; // ��������� ������ ³���
        department.add(w1);
        department.add(w2);
        department.add(w3);
        department.add(w4);

        std::cout << "List of employees: " << std::endl;
        for (int i = 0; i < department.vectorLength(); i++) {
            department.show(i);
        }
        std::cout << std::endl;

    } // department �������� � ������ �������� � ��������� ���

    std::cout << w1->getName() << " ��� ������!\n";
    std::cout << w2->getName() << " ��� ������!\n";
    std::cout << w3->getName() << " ��� ������!\n";
    std::cout << w4->getName() << " ��� ������!\n";
    delete w1;
    delete w2;
    delete w3;
    delete w4;
    return 0;
}