#include "Volunteer.h"

// Constructor for the Volunteer class
Volunteer::Volunteer(int id, const std::string &name, const std::string& schedule)
        : Staff(id, name, "Volunteer", schedule) {}

// Updates the volunteer's information
void Volunteer::updateVolunteerInfo(const std::string &name, const std::string& schedule) {
    setName(name);
    setSchedule(schedule);
}

// Assigns a new task to the volunteer
void Volunteer::assignTask(const std::string &task) {
    assignedTasks.clear();
    assignedTasks.push_back(task);
}

// Removes a task from the volunteer's assigned tasks
void Volunteer::removeTask(const std::string &task) {
    assignedTasks.remove(task);
}

// Getters
std::list<std::string> Volunteer::getAssignedTasks() const {
    return assignedTasks;
}

int Volunteer::getId() const {
    return id;
}

std::string Volunteer::getName() const {
    return name;
}

// Setter
void Volunteer::setAssignedTasks(const std::list<std::string> &assignedTasks) {
    this->assignedTasks = assignedTasks;
}

// Overloaded stream insertion operator for the Volunteer class
std::ostream &operator<<(std::ostream &os, const Volunteer &volunteer) {
    os << static_cast<const Staff&>(volunteer) << "\nAssigned Tasks: ";
    for (const auto& task : volunteer.assignedTasks) {
        os << task << "; ";
    }
    return os;
}
