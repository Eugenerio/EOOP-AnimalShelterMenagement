#pragma once

#include "Staff.h"
#include <iostream>
#include <list>
#include <string>

class Volunteer : public Staff {
    friend std::ostream &operator<<(std::ostream &os, const Volunteer &volunteer);

private:
    std::list<std::string> assignedTasks;  // List of tasks assigned to the volunteer

public:
    // Constructor for the Volunteer class
    Volunteer(int id, const std::string &name, const std::string& schedule);

    // Updates the volunteer's information
    void updateVolunteerInfo(const std::string &name, const std::string& schedule);

    // Assigns a new task to the volunteer
    void assignTask(const std::string &task);

    // Removes a task from the volunteer's assigned tasks
    void removeTask(const std::string &task);

    // Getters
    std::list<std::string> getAssignedTasks() const;
    int getId() const override;
    std::string getName() const override;

    // Setter
    void setAssignedTasks(const std::list<std::string> &assignedTasks);
};

std::ostream &operator<<(std::ostream &os, const Volunteer &volunteer);
