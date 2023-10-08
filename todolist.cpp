#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "[" << (i + 1) << "] ";
            if (tasks[i].completed) {
                cout << "[Completed] ";
            }
            cout << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    ToDoList todo;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Quit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                string description;
                getline(cin, description);
                todo.addTask(description);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                cout << "Enter the task index to mark as completed: ";
                int index;
                cin >> index;
                todo.markTaskCompleted(index);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
