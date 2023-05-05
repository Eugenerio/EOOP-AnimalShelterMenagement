#pragma once

#include <iostream>
#include <string>

class Staff {
    friend std::ostream &operator<<(std::ostream &os, const Staff &staff);

protected:
    std::string name;
    int id;
    std::string role;
    std::string schedule;

public:
    // Constructor for the Staff class
    Staff(int id, const std::string &name, const std::string &role, const std::string& schedule);

    // Updates the staff member's information
    void updateStaffInfo(const std::string &name, const std::string &role, const std::string& schedule);

    // Getters
    virtual int getId() const;
    virtual std::string getName() const;
    std::string getRole() const;
    std::string getSchedule() const;

    // Setters
    void setId(int id);
    void setName(const std::string &name);
    void setRole(const std::string &role);
    void setSchedule(const std::string& schedule);
};

std::ostream &operator<<(std::ostream &os, const Staff &staff);

