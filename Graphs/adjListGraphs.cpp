// #include <iostream>
// using namespace std;

// struct edge;

// struct vertex {
//     int data;
//     vertex* next;
//     edge* head;
// };

// struct edge {
//     vertex* v;
//     edge* next;
// };

// vertex* start = nullptr;

// void invertex(int ver) {
//     vertex* temp = new vertex;
//     temp->data = ver;
//     temp->head = nullptr;
//     temp->next = nullptr;

//     if (start == nullptr) {
//         start = temp;
//     } else {
//         vertex* curr = start;
//         while (curr->next != nullptr) {
//             curr = curr->next;
//         }
//         curr->next = temp;
//     }
// }

// vertex* searchvertex(int ver) {
//     vertex* ptr = start;
//     while (ptr != nullptr) {
//         if (ptr->data == ver) {
//             return ptr;
//         } else {
//             ptr = ptr->next;
//         }
//     }
//     cout << "No such vertex in the graph" << endl;
//     return nullptr; 
// }

// void inedge(vertex* ver, vertex* edg) {
//     edge* temp = new edge;
//     temp->v = edg;
//     temp->next = nullptr;

//     if (ver->head == nullptr) {
//         ver->head = temp;
//     } else {
//         edge* ptr2 = ver->head;
//         while (ptr2->next != nullptr) {
//             ptr2 = ptr2->next;
//         }
//         ptr2->next = temp;
//     }
// }

// void diredges() {
//     int bit;
//     vertex* ptr = start;
//     vertex* ptr2 = start;
//     while (ptr != nullptr) {
//         while (ptr2 != nullptr) {
//             cout << "Edge between " << ptr->data << " and " << ptr2->data << " : ";
//             cin >> bit;
//             if (bit == 1) {
//                 inedge(ptr, ptr2);
//             }
//             ptr2 = ptr2->next;
//         }
//         ptr = ptr->next;
//         ptr2 = start;
//     }
// }



// void outdegree() {
//     int count;
//     vertex* ptr = start;
//     edge* eptr = ptr->head;
//     cout << endl;
//     while (ptr != nullptr) {
//         while (eptr != nullptr) {
//             eptr = eptr->next;
//             count++;
//         }
//         cout << "Degree/OutDegree of " << ptr->data << " : " << count << endl;
//         ptr = ptr->next;
//         if (ptr != nullptr) {
//             eptr = ptr->head;
//         }
//         count = 0;
//     }
//     cout << endl;
// }

// void indegree() {
//     cout << endl;
//     int count;
//     vertex* vptr = start;
//     vertex* ptr = start;
//     edge* eptr = ptr->head;
//     while (vptr != nullptr) {
//         while (ptr != nullptr) {
//             while (eptr != nullptr) {
//                 if (eptr->v->data == vptr->data) {
//                     count++;
//                 }
//                 eptr = eptr->next;
//             }
//             ptr = ptr->next;
//             if (ptr != nullptr) {
//                 eptr = ptr->head;
//             }
//         }
//         cout << "Indegree of " << vptr->data << " : " << count << endl;
//         count = 0;
//         vptr = vptr->next;
//         ptr = start;
//         eptr = ptr->head;
//     }
// }

// void path(int len) {
//     int v1, v2;
//     cout << "First Vertex : ";
//     cin >> v1;
//     cout << "Second Vertex : ";
//     cin >> v2;

//     vertex* ptr = searchvertex(v1);
//     vertex* ptr2 = searchvertex(v2);
//     int arr[len];

//     int flag[len];

//     for (int i = 0; i < len; i++) {
//         flag[i] = 0;
//     }
// }

// void printlist() {
//     vertex* ptr = start;
//     edge* eptr = ptr->head;
//     cout << endl;
//     while (ptr != nullptr) {
//         cout << ptr->data;
//         while (eptr != nullptr) {
//             cout << " -> " << eptr->v->data;
//             eptr = eptr->next;
//         }
//         cout << endl;
//         ptr = ptr->next;
//         if (ptr != nullptr) {
//             eptr = ptr->head;
//         }
//     }
// }

// int main() {
//     int type, len, vertex;
//     cout << "1. Directed Graph\n2. Undirected Graph \n";
//     cout << "Select type of Graph : ";
//     cin >> type;

//     cout << "Enter Number of Vertices: ";
//     cin >> len;

//     for (int m = 0; m < len; m++) {
//         cout << "Enter Vertex : ";
//         cin >> vertex;
//         invertex(vertex);
//     }

//     diredges();

//     printlist();

//     // invertex(3);

//     indegree();

//     outdegree();

    
//     path(1);

//     return 0;
// }







#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

struct edge;

struct vertex {
    int data;
    vertex* next;
    edge* head;
    bool visited; 
};

struct edge {
    vertex* v;
    edge* next;
};

vertex* start = nullptr;

void invertex(int ver) {
    vertex* temp = new vertex;
    temp->data = ver;
    temp->head = nullptr;
    temp->next = nullptr;
    temp->visited = false; 
    if (start == nullptr) {
        start = temp;
    } else {
        vertex* curr = start;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

vertex* searchvertex(int ver) {
    vertex* ptr = start;
    while (ptr != nullptr) {
        if (ptr->data == ver) {
            return ptr;
        } else {
            ptr = ptr->next;
        }
    }
    cout << "No such vertex in the graph" << endl;
    return nullptr; 
}

void inedge(vertex* ver, vertex* edg) {
    edge* temp = new edge;
    temp->v = edg;
    temp->next = nullptr;

    if (ver->head == nullptr) {
        ver->head = temp;
    } else {
        edge* ptr2 = ver->head;
        while (ptr2->next != nullptr) {
            ptr2 = ptr2->next;
        }
        ptr2->next = temp;
    }
}

void diredges() {
    int bit;
    vertex* ptr = start;
    vertex* ptr2 = start;
    while (ptr != nullptr) {
        while (ptr2 != nullptr) {
            cout << "Edge between " << ptr->data << " and " << ptr2->data << " : ";
            cin >> bit;
            if (bit == 1) {
                inedge(ptr, ptr2);
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
        ptr2 = start;
    }
}

void outdegree() {
    int count;
    vertex* ptr = start;
    edge* eptr;
    cout << endl;
    while (ptr != nullptr) {
        eptr = ptr->head; 
        while (eptr != nullptr) {
            eptr = eptr->next;
            count++;
        }
        cout << "Degree/OutDegree of " << ptr->data << " : " << count << endl;
        ptr = ptr->next;
        count = 0;
    }
    cout << endl;
}

void indegree() {
    cout << endl;
    int count;
    vertex* vptr = start;
    vertex* ptr;
    edge* eptr;
    while (vptr != nullptr) {
        ptr = start;
        count = 0;
        while (ptr != nullptr) {
            eptr = ptr->head;
            while (eptr != nullptr) {
                if (eptr->v->data == vptr->data) {
                    count++;
                }
                eptr = eptr->next;
            }
            ptr = ptr->next;
        }
        cout << "Indegree of " << vptr->data << " : " << count << endl;
        vptr = vptr->next;
    }
}

void BFS(vertex* start) {
    queue<vertex*> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start->data);
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        vertex* current = q.front();
        q.pop();
        cout << current->data << " ";
        edge* eptr = current->head;
        while (eptr != nullptr) {
            if (visited.find(eptr->v->data) == visited.end()) {
                q.push(eptr->v);
                visited.insert(eptr->v->data);
            }
            eptr = eptr->next;
        }
    }
    cout << endl;
}

void DFS(vertex* start) {
    stack<vertex*> stk;
    unordered_set<int> visited;
    stk.push(start);
    cout << "DFS Traversal: ";
    while (!stk.empty()) {
        vertex* current = stk.top();
        stk.pop();
        if (!visited.count(current->data)) {
            cout << current->data << " ";
            visited.insert(current->data);
            edge* eptr = current->head;
            while (eptr != nullptr) {
                if (!visited.count(eptr->v->data)) {
                    stk.push(eptr->v);
                }
                eptr = eptr->next;
            }
        }
    }
    cout << endl;
}

void printlist() {
    vertex* ptr = start;
    edge* eptr;
    cout << endl;
    while (ptr != nullptr) {
        cout << ptr->data;
        eptr = ptr->head; 
        while (eptr != nullptr) {
            cout << " -> " << eptr->v->data;
            eptr = eptr->next;
        }
        cout << endl;
        ptr = ptr->next;
    }
}

int main() {
    int type, len, vertex;
    cout << "1. Directed Graph\n2. Undirected Graph \n";
    cout << "Select type of Graph : ";
    cin >> type;

    cout << "Enter Number of Vertices: ";
    cin >> len;

    for (int m = 0; m < len; m++) {
        cout << "Enter Vertex : ";
        cin >> vertex;
        invertex(vertex);
    }

    diredges();

    printlist();

    indegree();

    outdegree();

    BFS(start);

    DFS(start);

    return 0;
}

