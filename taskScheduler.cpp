#include<iostream>
using namespace std;

class queue {
private:
    string* arr;
    int front, back, num_ele;

public:
    queue(int n) {
        arr = new string[n];
        front = -1;
        back = -1;
        num_ele = n;
    }

    ~queue() {
        delete[] arr;
    }

    void push(string x) {
        if (back == num_ele - 1) {
            cout << "Tasks are packed for today" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1) {
            front++;
        }
    }

    void pop() {
        if (front == -1 || front > back) {
            cout << "No elements in queue" << endl;
            return;
        }
        front++;
    }

    string peek() {
        if (front == -1 || front > back) {
            return "No elements in queue\n";
        }
        return arr[front];
    }

    bool empty() {
        if (front == -1 || front > back) {
            return true;
        }
        return false;
    }
};

int main() {
    int num;
    cout << "Enter the number of tasks to schedule" << endl;
    cin >> num;
    queue tasks(num);
    bool contain = true;
    int key, key2;
    string x;
    cin.ignore(); 
    while (contain) {
        cout << "Enter 0 for menu and -1 to exit and display scheduled tasks\n";
        cin >> key;
        cin.ignore(); 
        if (key == 0) {
            cout << "Press:\n1 to add tasks\n2 to remove recent task\n3 to check the recent task added" << endl;
            cin >> key2;
            cin.ignore(); 
            switch (key2) {
                case 1:
                    cout << "Enter the task" << endl;
                    getline(cin, x);
                    tasks.push(x);
                    break;
                case 2:
                    tasks.pop();
                    cout << "Recent task removed\n";
                    break;
                case 3:
                    cout << "Recent task added is:\n" << tasks.peek() << endl;
                    break;
            }
        } else if (key == -1) {
            contain = false;
        } else {
            cout << "Invalid input" << endl;
            continue;
        }
    }
}
