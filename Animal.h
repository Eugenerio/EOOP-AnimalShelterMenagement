#pragma once

#include <iostream>
#include <string>
#include "Adoption.h"

using namespace std;


class Adoption;

class Animal {
    friend ostream& operator<<(ostream& os, const Animal& animal);
    friend class Adoption;
public:
    enum AnimalStatus {
        AVAILABLE,
        ADOPTED,
        PENDING_ADOPTION // corresponds to AdoptionStatus::PENDING
    };
    // Constructor for the Animal class
    Animal(int id, const string& name, const string& breed, int age, const string& healthStatus, AnimalStatus status);

// Getters
    int getId() const;
    string getName() const;
    string getBreed() const;
    int getAge() const;
    string getHealthStatus() const;
    AnimalStatus getAdoptionStatus() const;


// Setters
    void setId(int id);
    void setName(const string& name);
    void setBreed(const string& breed);
    void setAge(int age);
    void setHealthStatus(const string& healthStatus);
    void setAdoptionStatus(AnimalStatus status);


// Checks if the animal is available for adoption
    bool isAvailableForAdoption() const;

// Updates the animal's information
    void updateAnimalInfo(const string &name, const string &breed, int age);

// Updates the animal's adoption status
    void updateAdoptionStatus(AnimalStatus status);

    bool operator==(const Animal& other) const {
        return this->id == other.id;
    }
private:
    int id; // Unique identifier for each animal
    string name; // Name of the animal
    string breed; // Breed of the animal
    int age; // Age of the animal
    string healthStatus; // Health status of the animal
    AnimalStatus status; // Status of the animal (e.g., available, adopted)
};
