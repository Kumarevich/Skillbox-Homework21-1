#include <iostream>
#include <fstream>
#include <vector>

struct payment
{
    std::string name = "";
    std::string surname = "";
    int money = 0;
    std::string date = "";
};

void read()
{
    std::vector<payment> people;
    std::ifstream statement("..\\Statement.txt");
    int count = 0;
    if (statement.is_open()) {
        while (!statement.eof()) {
            payment temp;
            statement >> temp.name >> temp.surname >> temp.money >> temp.date;
            if (!temp.name.empty()){
                people.push_back(temp);
                count++;
            }
        }
        for (int i = 0; i < count; ++i) {
            std::cout << people[i].name << " " << people[i].surname << " " << people[i].money << " " << people[i].date << std::endl;
        }
        statement.close();
    } else {
        std::cout << "File open error!";
    }
}

void add()
{
    std::cout << "Input new line: ";
    payment temp;
    std::cin >> temp.name >> temp.surname >> temp.money >> temp.date;
    std::ofstream statement("..\\Statement.txt", std::ios::app);
    statement << temp.name << " " << temp.surname << " " << temp.money << " " << temp.date << std::endl;
}

int main() {
    std::cout << "Action: ";
    std::string action;
    std::cin >> action;
    if (action == "read") read();
    else add();
    return 0;
}
