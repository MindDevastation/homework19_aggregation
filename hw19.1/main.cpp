/*
  Допишіть код програми, щоб вона без помилок виводила повідомлення про те,
  що працівники продовжуть працювати навіть після того, як відділ де вони працювали раніше, розформовано.
  Підказка: Використовуйте std::vector для зберігання працівників у відділі.
 На додаткову оцінку можна реалізувати переведення працівника з одного відділа в інший.
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
    // решту методів допишіть самостійно
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
    // Створюємо Працівників поза областю видимості класу Department
    Worker* w1 = new Worker("Антін");
    Worker* w2 = new Worker("Івасик");
    Worker* w3 = new Worker("Євген");
    Worker* w4 = new Worker("Їржик");

    std::cout << w1->getName() << " працює!\n";
    std::cout << w2->getName() << " працює!\n";
    std::cout << w3->getName() << " працює!\n";
    std::cout << w4->getName() << " працює!\n";
    std::cout << std::endl;

    {
        // Створюємо Відділ і передаємо Працівників як параметри конструктора
        Department department; // створюємо пустий Відділ
        department.add(w1);
        department.add(w2);
        department.add(w3);
        department.add(w4);

        std::cout << "List of employees: " << std::endl;
        for (int i = 0; i < department.vectorLength(); i++) {
            department.show(i);
        }
        std::cout << std::endl;

    } // department виходить з області видимості і знищується тут

    std::cout << w1->getName() << " досі працює!\n";
    std::cout << w2->getName() << " досі працює!\n";
    std::cout << w3->getName() << " досі працює!\n";
    std::cout << w4->getName() << " досі працює!\n";
    delete w1;
    delete w2;
    delete w3;
    delete w4;
    return 0;
}