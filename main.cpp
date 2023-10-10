#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>
#include "task.h"
#include "taskmanager.h"
#include "date.h"
void displayMenu();
void inputValidation(int &, int, int);
void inputValDateDue(Task &);
int main()
{
using namespace std;
    int userChoice;
    TaskManager taskmanager;
    string taskName;
    Task task;
    int daysUntilDue;
    
    taskmanager.loadTasksFromFile("saveData.txt");
    do
    {
        taskmanager.displayAllTasks();
        displayMenu();
        inputValidation(userChoice, 0, INT_MAX);
        string inputString;
        switch (userChoice)
        {
            case 1: 
                cout << "Enter task name: ";
                getline(cin, taskName);
                cout << "Enter date due (mm/dd/yy): ";
                // inputValidation(daysUntilDue, 0, INT_MAX);
                // task.setDaysToComplete(daysUntilDue);
                task.setDateDue();
                task.setTaskName(taskName);
                taskmanager.addTask(task);
                break;
            case 2: 
                int position;
                cout << "Enter the number of the task you would like to mark complete: ";
                inputValidation(position, 0, taskmanager.getTaskList().size());
                taskmanager.markCompleted(position-1);
                break;
            case 3: 
                taskmanager.sortTasks();
                break;
            case 4:
                cout << "Enter the number of the task you would like to delete: ";
                inputValidation(position, 0, taskmanager.getTaskList().size());
                taskmanager.deleteTask(position-1);
                break;
            case 5:
                taskmanager.saveTasksToFile("saveData.txt"); 
                break;
            defualt:
                break;
        }
        
    } while (userChoice >= 1 && userChoice<= 4);
    

    return 0;
}

void displayMenu()
{
using namespace std;
    cout << "Please select an option:\n";
    cout << "1: Add a task\n";
    cout << "2: Mark a task as completed\n";
    cout << "3: Sort task list\n";
    cout << "4: Delete a task\n";
    cout << "5: Exit the program and save data\n";
}
void inputValidation(int &val, int lowerBound, int upperBound)
{
    using namespace std;
    string inputString;
    while (true)
    {
        getline(cin, inputString);
        stringstream ss(inputString);
        if (ss >> val)
        {
            if (val > lowerBound && val < upperBound);
                break;
        }
        else 
            cout << "Invalid input. Try again:\n";
    }
}
// void inputValDateDue(Task &task)
// {
//     bool yearFlag = false;
//     bool monthFlag = false;
//     bool dayFlag = false;
//     while(true)
//     {
//         task.setDateDue();
//         if ()

//     }    
// }