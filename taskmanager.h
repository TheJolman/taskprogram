#pragma once
#include <vector>
#include "task.h"

class TaskManager
{
private:
    std::vector<Task> taskList;
public:
    void sortTasks();
    std::vector<Task> getTaskList();
    void displayAllTasks();
    void addTask(Task);
    void markCompleted(int);
    void deleteTask(int);

    void saveTasksToFile(const std::string);
    void loadTasksFromFile(const std::string);



};