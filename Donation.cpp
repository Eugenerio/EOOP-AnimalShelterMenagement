#include "Donation.h"

// Constructor
Donation::Donation(int id, const std::string &donorName, const std::string &description, const std::string &date, double amount)
        : id(id), donorName(donorName), description(description), date(date), amount(amount) {}

// Getter methods
int Donation::getId() const {
    return id;
}

std::string Donation::getDonorName() const {
    return donorName;
}

std::string Donation::getDescription() const {
    return description;
}

std::string Donation::getDate() const {
    return date;
}

double Donation::getAmount() const {
    return amount;
}

// Setter methods
void Donation::setId(int id) {
    this->id = id;
}

void Donation::setDonorName(const std::string &donorName) {
    this->donorName = donorName;
}

void Donation::setDescription(const std::string &description) {
    this->description = description;
}

void Donation::setDate(const std::string &date) {
    this->date = date;
}

void Donation::setAmount(double amount) {
    this->amount = amount;
}

// Overloaded operator to print Donation object
std::ostream &operator<<(std::ostream &os, const Donation &donation) {
    os << "Donation ID: " << donation.id << std::endl;
    os << "Donor Name: " << donation.donorName << std::endl;
    os << "Description: " << donation.description << std::endl;
    os << "Date: " << donation.date << std::endl;
    os << "Amount: " << donation.amount << std::endl;
    return os;
}
