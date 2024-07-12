
#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char SName[25];
    int Sno;
     student *next;
};

struct courses {
    char cname[25];
    int cno;
    student *head;
    courses *next;
};
 courses *start = nullptr;

void inscourse() {
     courses *temp = new  courses();
    cout << "Enter Course Name : ";
    cin >> temp->cname;
    cout << "Enter Course Number : ";
    cin >> temp->cno;
    temp->next = nullptr;
    temp->head = nullptr;
    if (start == nullptr) {
        start = temp;
    } else {
        courses *curr = start;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    cout << "Course Successfully Inserted!" << endl << endl;
}

void enroll() {
    int cno, flag = 0;
    cout << "Enter Course Number: ";
    cin >> cno;
    courses *ptr = start;
    while (ptr != nullptr) {
        if (ptr->cno == cno) {
             student *temp = new student();
            cout << "Enter Student Name: ";
            cin >> temp->SName;
            cout << "Enter Student Seat No.: ";
            cin >> temp->Sno;
            temp->next = nullptr;
            if (ptr->head == nullptr) {
                ptr->head = temp;
            } else {
                 student *scurr = ptr->head;
                while (scurr->next != nullptr) {
                    scurr = scurr->next;
                }
                scurr->next = temp;
            }
            cout << "Student Enrolled Successfully!" << endl << endl;
            flag = 1;
            break;
        } else {
            ptr = ptr->next;
        }
    }
    if (flag != 1) {
        cout << "Course not Found!" << endl;
    }
}

void searchcourse() {
    int cno, flag = 0;
    cout << "Enter Course Number: ";
    cin >> cno;
     courses *ptr = start;
    while (ptr != nullptr) {
        if (ptr->cno == cno) {
            cout << "Course Found!" <<endl;
            cout << "Course Name : " << ptr->cname <<endl;
            flag = 1;
            break;
        } else {
            ptr = ptr->next;
        }
    }
    if (flag != 1) {
        cout << "Course not Found!" << endl;
    }
}

void searchstudent() {
    int sno, flag = 0;
    cout << "Enter Student Seat Number: ";
    cin >> sno;
    courses *ptr = start;
    while (ptr != nullptr) {
        struct student *sptr = ptr->head;
        while (sptr != nullptr) {
            if (sptr->Sno == sno) {
                cout << "Student Enrolled in " << ptr->cno << endl;
                cout << "Student Name : " << sptr->SName << endl;
                flag = 1;
                break;
            }
            sptr = sptr->next;
        }
        if (flag == 1) {
            break;
        }
        ptr = ptr->next;
    }
    if (flag != 1) {
        cout << "Student not Found!" << endl;
    }
}

void deletecourse() {
    int dc, flag = 0;
    cout << "Enter Course No. : ";
    cin >> dc;
    if (start->cno == dc) {
        struct courses *temp = start;
        start = start->next;
        delete temp;
        flag = 1;
        cout << "Course Deleted" << endl;
    } else {
        courses *ptr = start->next;
        courses *prev = start;
        while (ptr != nullptr) {
            if (ptr->cno == dc) {
                prev->next = ptr->next;
                struct student *sptr = ptr->head;
                while (sptr != nullptr) {
                    struct student *temp = sptr;
                    sptr = sptr->next;
                    delete temp;
                }
                delete ptr;
                cout << "Course Deleted" <<endl;
                flag = 1;
                break;
            }
            ptr = ptr->next;
            prev = prev->next;
        }
    }
    if (flag != 1) {
        cout << "Course not Found!" << endl;
    }
}

void deletestu() {
    int ds, flag = 0;
    cout << "Enter Student Seat Number: ";
    cin >> ds;
    struct courses *ptr = start;
    while (ptr != nullptr) {
         student *sptr = ptr->head;
         student *prev = nullptr;
        while (sptr != nullptr) {
            if (sptr->Sno == ds) {
                if (prev == nullptr) {
                    ptr->head = sptr->next;
                } else {
                    prev->next = sptr->next;
                }
                delete sptr;
                cout << "Student Deleted!" << endl;
                flag = 1;
                break;
            }
            prev = sptr;
            sptr = sptr->next;
        }
        if (flag == 1) {
            break;
        }
        ptr = ptr->next;
    }
    if (flag != 1) {
        cout << "Student not Found!" << endl;
    }
}

void printlist() {
     courses *ptr = start;
    while (ptr != nullptr) {
        cout << ptr->cname;
         student *sptr = ptr->head;
        while (sptr != nullptr) {
            cout << " -> " << sptr->SName;
            sptr = sptr->next;
        }
        cout << endl;
        ptr = ptr->next;
    }
}

int menu() {
    int op;
    cout << "1. Insert Course\n";
    cout << "2. Enroll Student\n";
    cout << "3. Search Course\n";
    cout << "4. Search Student\n";
    cout << "5. Delete Course\n";
    cout << "6. Delete Student\n";
    cout << "7. Print List\n";
    cout << "8. Exit\n\n";
    cout << "Select Operation : ";
    cin >> op;
    return op;
}

int main() {
    int choice;
    while (true) {
        choice = menu();
        switch (choice) {
            case 1:
                inscourse();
                break;
            case 2:
                enroll();
                break;
            case 3:
                searchcourse();
                break;
            case 4:
                searchstudent();
                break;
            case 5:
                deletecourse();
                break;
            case 6:
                deletestu();
                break;
            case 7:
                printlist();
                break;
            case 8:
                exit(1);
                break;
            default:
                cout << "Invalid Entry" << endl;
        }
    }
    return 0;
}

