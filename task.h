#pragma once
#include <string>
#include <iostream>
#include "date.h"
class Task
{
private:
    std::string taskName;
    int daysToComplete;
    bool status;
    Date dateCreated, dateDue;
public:
    void setTaskName(std::string taskName)
    { this->taskName = taskName; }
    void setDaysToComplete(int daysToComplete)
    { this->daysToComplete = daysToComplete; }
    Task();
    Task(std::string, int);
    void displayDetails();
    void markCompleted();
    Task& operator&=(const Task&);
    bool getStatus() const
    { return status; }
    int getDaysToComplete() const
    { return daysToComplete; }
    std::string getTaskName() const
    { return taskName; }
    void setDateDue()
    { std::cin >> dateDue;
      std::cin.ignore(); }


    std::string serialize() const;
    static Task deserialize(const std::string &);


};