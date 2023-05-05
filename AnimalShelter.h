#pragma once
#include "Animal.h"
#include "Staff.h"
#include "Volunteer.h"
#include "Adoption.h"
#include "Donation.h"
#include <iostream>
#include <list>
#include <vector>

class AnimalShelter {
private:
    // List of animals in the shelter
    std::list<Animal> animals;
    std::list<Staff> staffMembers; // List of staff members working at the shelter
    std::list<Volunteer> volunteers; // List of volunteers helping at the shelter
    std::list<Adoption> adoptions; // List of adoption records
    std::list<Donation> donations; // List of donation records
    std::vector<std::string> adopters; // List of adopters// Helper function to search for a staff member or volunteer
public:
// Add and remove methods for animals, staff, volunteers, adoptions, donations, and adopters
    bool addAnimal(const Animal& animal);
    bool removeAnimal(int id);
    bool updateAnimal(int id, const std::string& name, const std::string& breed, int age, const std::string& healthStatus);
    bool addStaff(const Staff& staff);
    bool removeStaff(int id);
    bool updateStaff(int id, const std::string& name, const std::string& role, const std::string& schedule);
    bool addVolunteer(const Volunteer& volunteer);
    bool removeVolunteer(int id);
    bool updateVolunteer(int id, const std::string& name, const std::string& schedule);
    bool createAdoption(const Adoption& adoption);
    bool updateAdoptionStatus(int id, Adoption::AdoptionStatus status);
    bool finalizeAdoption(int id);
    bool recordDonation(const Donation& donation);
    bool addAdopter(const std::string& adopter);
    bool removeAdopter(const std::string& adopter);
    // Search methods for animals, adoptions, and donations
    Animal* searchAnimal(int id);
    Adoption* searchAdoption(int id);
    Donation* searchDonation(int id);

// Print methods for animals, staff, volunteers, adoptions, and donations
    void printAnimals(std::ostream& os) const;
    void printStaff(std::ostream& os) const;
    void printVolunteers(std::ostream& os) const;
    void printAdoptions(std::ostream& os) const;
    void printDonations(std::ostream& os) const;

// Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const AnimalShelter& animalShelter);

    string statusToString(Adoption::AdoptionStatus status);


    Staff* searchVolunteerOrStaff(int id);
};
