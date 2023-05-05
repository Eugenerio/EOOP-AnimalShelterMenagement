#include "Staff.h"

// Constructor for the Staff class
Staff::Staff(int id, const std::string &name, const std::string &role, const std::string& schedule)
        : id(id), name(name), role(role), schedule(schedule)
{
}

// Updates the staff member's information
void Staff::updateStaffInfo(const std::string &name, const std::string &role, const std::string& schedule)
{
    setName(name);
    setRole(role);
    setSchedule(schedule);
}

// Getter for the ID of the staff member
int Staff::getId() const
{
    return id;
}

// Getter for the name of the staff member
std::string Staff::getName() const
{
    return name;
}

// Getter for the role of the staff member
std::string Staff::getRole() const
{
    return role;
}

// Getter for the schedule of the staff member
std::string Staff::getSchedule() const
{
    return schedule;
}

// Setter for the ID of the staff member
void Staff::setId(int id)
{
    this->id = id;
}

// Setter for the name of the staff member
void Staff::setName(const std::string &name)
{
    this->name = name;
}

// Setter for the role of the staff member
void Staff::setRole(const std::string &role)
{
    this->role = role;
}

// Setter for the schedule of the staff member
void Staff::setSchedule(const std::string& schedule)
{
    this->schedule = schedule;
}

// Overloaded operator to print the details of the staff member
std::ostream &operator<<(std::ostream &os, const Staff &staff)
{
    os << "ID: " << staff.getId() << "\nName: " << staff.getName() << "\nRole: " << staff.getRole() << "\nSchedule: " << staff.getSchedule();
    return os;
}