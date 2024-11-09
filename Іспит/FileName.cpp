#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


//���������� �����
//�������� 1
void myGradePoshalusta() {
    cout << "����� ���������: ������������� �� C++\n";
    cout << "������ ������ 12 ����\n";
}

//�������� 2
class Rectangle {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int calculateArea() {
        return width * height;
    }
};

//�������� 3
class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark!\n";
    }
};

//������� �����
//�������� 1
class Car {
private:
    int speed;
public:
    Car() : speed(0) {}
    void accelerate(int increase) {
        speed += increase;
        cout << "�������� �������� ��: " << speed << " ��/���\n";
    }
    void decelerate(int decrease) {
        speed -= decrease;
        if (speed < 0) speed = 0;
        cout << "�������� �������� ��: " << speed << " ��/���\n";
    }
};

//�������� 2
class Student {
private:
    string firstName, lastName, specialization;
    int age, course, desiredGrade;
public:
    Student(string fn, string ln, int a, string sp, int c)
        : firstName(fn), lastName(ln), age(a), specialization(sp), course(c), desiredGrade(0) {}

    void setDesiredGrade(int grade) {
        desiredGrade = grade;
        cout << firstName << " " << lastName << " ���� ������: " << desiredGrade << endl;
    }
};

//������� �����
class Quest {
public:
    string name, description;
    int requiredLevel, currentProgress, maxProgress, reward;

    Quest(string n, string d, int rl, int mp, int rw)
        : name(n), description(d), requiredLevel(rl), currentProgress(0), maxProgress(mp), reward(rw) {}

    bool isQuestCompleted() const {
        return currentProgress >= maxProgress;
    }

    void progressQuest(int progress) {
        currentProgress += progress;
        if (currentProgress > maxProgress) currentProgress = maxProgress;
    }
};

class Character {
private:
    string name;
    int level, experience;
    vector<Quest> activeQuests;

public:
    Character(string n, int lvl, int exp) : name(n), level(lvl), experience(exp) {}

    void acceptQuest(const Quest& quest) {
        if (level >= quest.requiredLevel) {
            activeQuests.push_back(quest);
            cout << "����� \"" << quest.name << "\" ��������\n";
        }
        else {
            cout << "���������� ����� ��� ��������� ����� ������" << endl;
        }
    }

    void completeQuest(const string& questName) {
        for (size_t i = 0; i < activeQuests.size(); ++i) {
            if (activeQuests[i].name == questName && activeQuests[i].isQuestCompleted()) {
                experience += activeQuests[i].reward;
                cout << "����� \"" << activeQuests[i].name << "\" ���������. ��������: " << activeQuests[i].reward << " ������." << endl;
                activeQuests.erase(activeQuests.begin() + i);
                return;
            }
        }
        cout << "����� �� �������� ��� �� �� �� ����������." << endl;
    }

    void showActiveQuests() const {
        if (activeQuests.empty()) {
            cout << "���� �������� ������" << endl;
            return;
        }
        cout << "������ ������:" << endl;
        for (const auto& quest : activeQuests) {
            cout << "- " << quest.name << ": " << quest.currentProgress << "/" << quest.maxProgress << endl;
        }
    }
};

void menu() {
    int choice;
    cout << "1. ������� ����� ��������� �� ������ ������" << endl;
    cout << "2. �������� ���� Rectangle � ��������� �����" << endl;
    cout << "3. �������� ����� Animal �� Dog � ��������� ����� makeSound()" << endl;
    cout << "4. �������� ���� Car � ������ ��������" << endl;
    cout << "5. �������� ���� Student � ������� ������ ������" << endl;
    cout << "6. �������� � ������ Character �� ��������" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        myGradePoshalusta();
        break;
    case 2: {
        Rectangle rect(5, 10);
        cout << "����� ������������: " << rect.calculateArea() << endl;
        break;
    }
    case 3: {
        Dog dog;
        dog.makeSound();
        break;
    }
    case 4: {
        Car car;
        car.accelerate(50);
        car.decelerate(20);
        break;
    }
    case 5: {
        Student student("�����", "���������", 20, "�����������", 2);
        student.setDesiredGrade(12);
        break;
    }
    case 6: {
        Character character("���", 5, 100);
        Quest quest1("������ �����", "��������� ����� ��������", 3, 10, 50);
        character.acceptQuest(quest1);
        character.showActiveQuests();
        character.completeQuest("������ �����");
        break;
    }
    default:
        cout << "������������ ����" << endl;
        break;
    }
}

int main() {
    std::system("chcp 1251");

    menu();

    return 0;
}