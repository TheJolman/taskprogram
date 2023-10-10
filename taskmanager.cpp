#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "task.h"
#include "taskmanager.h"

void TaskManager::sortTasks()
{
    std::cout << "Sort tasks how?\n1: By completion\n2: By urgency\n3: By name(alphabetical)\nEnter a number: ";
    int num;
    std::string inputString;
    while (true)
        {
            std::getline(std::cin, inputString);
            std::stringstream ss(inputString);
            if (ss >> num)
            {
                if (num <= 3 && num >=1)
                    break;
            }
            else 
                std::cout << "Invalid input. Try again:\n";
        }

    switch(num)
    {
        case 1:
            //sort based on completed tasks. Move uncompleted tasks to top and completed to bottom
            for(int i = 0; i < taskList.size()-1; i++)
            {
                int j = 0;
                if (taskList[i+1].getStatus() == false)
                {    //swap this value with one earlier in the list
                    Task temp;
                    temp = taskList[i+1];
                    taskList[i+1] = taskList[j];
                    taskList[j] = temp;
                    j++;
                }
            }
            break;
        case 2:
            //sort based on urgency. Tasks with the fewest days to complete at the top, tasks that have been completed at the bottom
            for (int i = 0; i < taskList.size() - 1; i++)
            {
                for (int j = 1; j < taskList.size(); j++)
                {
                    if (taskList[j].getDaysToComplete() < taskList[i].getDaysToComplete())
                    {
                        Task temp;
                        temp = taskList[i];
                        taskList[i] = taskList[j];
                        taskList[j] = temp;
                    }
                }
            }
            break;
        case 3:
            //sort alphabetically (task name).
            for (int i = 0; i < taskList.size() - 1; i++)
            {
                for (int j = 1; j < taskList.size(); j++)
                {
                    if (taskList[j].getTaskName() < taskList[i].getTaskName())
                    {
                        Task temp;
                        temp = taskList[i];
                        taskList[i] = taskList[j];
                        taskList[j] = temp;
                    }
                }
            } 
            break;
        default:
            std::cout << "Invalid argument\n";
            break;
    }
    std::cout << "Tasks sorted.\n";
}

std::vector<Task> TaskManager::getTaskList()
{
    return taskList;
}

void TaskManager::displayAllTasks()
{
    std::cout << "------------------------------\n";
    for (int i = 0; i < taskList.size(); i++)
    {
        std::cout << "Task " << i+1 << ":\n";
        taskList[i].displayDetails();
        std::cout << "------------------------------\n";

    }    
}

void TaskManager::addTask(Task task)
{
    taskList.push_back(task);
}

void TaskManager::markCompleted(int i)
{
    taskList[i].markCompleted();
}

void TaskManager::saveTasksToFile(const std::string filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const Task& task : taskList)
            file << task.serialize() << '\n';
        file.close();
    }
}

void TaskManager::loadTasksFromFile(const std::string filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        taskList.clear();
        std::string line;
        while (std::getline(file, line))
        {
            Task task = Task::deserialize(line);
            taskList.push_back(task);
        }
        file.close();
    }
}

void TaskManager::deleteTask(int position)
{
    taskList.erase(taskList.begin()+(position));
}