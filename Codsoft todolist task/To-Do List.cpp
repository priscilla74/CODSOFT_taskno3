#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Task
{
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class Todolist
{
private:
    vector<Task> tasks;

public:
    void addTasks(const string &description)
    {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }
    void viewTasks()
    {
        if (tasks.empty())
        {
            cout << "No tasks found !!" << endl;
        }
        cout << "Tasks: " << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "(Completed) ";

            cout << tasks[i].description << endl;
        }
    }
    void markAscompleted(int tasknum){
        if (tasknum < 1 || tasknum > tasks.size())
            cout << "Invalid task number." << endl;

        tasks[tasknum - 1].completed = true;
        cout << "Task marked as completed: " << tasks[tasknum - 1].description << endl;
    }
    void deleteTasks(int tasknum)
    {
        if (tasknum < 1 || tasknum > tasks.size())
            cout << "Invalid task number." << endl;

        cout << "Task deleted: " << tasks[tasknum - 1].description << endl;
        tasks.erase(tasks.begin() + tasknum - 1);
    }
};
int main()
{
    Todolist todolist;
    int choice;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string description;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, description);
            todolist.addTasks(description);
            break;
        }
        case 2:
        {
            todolist.viewTasks();
            break;
        }
        case 3:
        {
            int tasknum;
            cout << "Which task do you want to complete? Enter the corresponding index: ";
            cin >> tasknum;
            todolist.markAscompleted(tasknum);
            break;
        }
        case 4:
        {
            int tasknum;
            cout << "Which task would you like to delete? Enter the corresponding index: ";
            cin >> tasknum;
            todolist.deleteTasks(tasknum);
            break;
        }
        case 5:
            cout << "You have come out of the list." << endl;
            return 0;

        default:
            cout << "Enter a valid task number." << endl;
            break;
        }
    }
    return 0;
}
