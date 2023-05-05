#pragma once

#include <iostream>
#include <string>

class Donation {

    friend std::ostream &operator<<(std::ostream &os, const Donation &donation);

private:
    int id;  // Unique identifier for each donation
    std::string donorName;  // Name of the donor
    std::string description;  // Description of the donated item(s)
    std::string date;  // Date of the donation
    double amount;

public:
    // Constructor for the Donation class
    Donation(int id, const std::string &donorName, const std::string &description, const std::string &date, double amount);

    // Getters
    int getId() const;
    std::string getDonorName() const;
    std::string getDescription() const;
    std::string getDate() const;
    double getAmount() const;

    // Setters
    void setId(int id);
    void setDonorName(const std::string &donorName);
    void setDescription(const std::string &description);
    void setDate(const std::string &date);
    void setAmount(double amount);
};

std::ostream &operator<<(std::ostream &os, const Donation &donation);

