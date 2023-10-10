#include "task.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
Task::Task() //default
{
    taskName = "";
    daysToComplete = 0;
    status = false;
    dateCreated;
    dateDue;
}
Task::Task(std::string taskName, int daysToComplete)
{
    this->taskName = taskName;
    this->daysToComplete = daysToComplete;
    this->status = false;
    dateCreated;
    dateDue;
}
void Task::displayDetails()
{
    std::string stat;
    if (status)
        stat = "completed";
    else 
        stat = "incomplete";
    std::cout << "\tTask Name: " << taskName << "\n";
    std::cout << "\tDue Date: " << dateDue << "\n";
    std::cout << "\tDays to Complete: " << daysToComplete << "\n";
    std::cout << "\tStatus: " << stat << "\n";
    
}
void Task::markCompleted()
{
    status = true;
}

Task& Task::operator&=(const Task&other)
{
    if (this == &other)
    {
        return *this;
    }
    taskName = other.taskName;
    daysToComplete = other.daysToComplete;
    status = other.status;
    return *this;
}

std::string Task::serialize() const
{
    return taskName + "," + std::to_string(daysToComplete) + "," + std::to_string(status);
}
Task Task::deserialize(const std::string &serializedData)
{
    Task task;
    std::istringstream ss(serializedData);
    std::getline(ss, task.taskName, ',');
    std::string daysStr, statusStr;
    std::getline(ss, daysStr, ',');
    task.daysToComplete = std::stoi(daysStr);
    std::getline(ss, statusStr, ',');
    // std::istringstream("1") >> task.status;
    task.status = std::stoi(statusStr);
    return task;
}