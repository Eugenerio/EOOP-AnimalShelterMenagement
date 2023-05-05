#pragma once

#include <iostream>
#include <string>
#include "Animal.h"

class Animal;

using namespace std;

class Adoption {
    friend ostream &operator<<(ostream &os, const Adoption &adoption);
    friend class Animal;

public:
// Enumeration representing the status of an adoption
    enum class AdoptionStatus {
        PENDING, // Adoption request is pending approval
        APPROVED, // Adoption request has been approved
        REJECTED // Adoption request has been rejected
    };

// Constructor for the Adoption class
    Adoption(int id, const string &adopterInfo, Animal *animal, const string &adopterName);

// Destructor for the Adoption class
    ~Adoption();

// Updates the status of the adoption
    void updateAdoptionStatus(AdoptionStatus status);

// Finalizes the adoption process
    bool finalizeAdoption();

// Getters for the adoption's properties
    int getId() const; // Returns the ID of the adoption
    string getAdopterInfo() const; // Returns information about the adopter
    Animal* getAnimal() const; // Returns a pointer to the animal being adopted
    AdoptionStatus getStatus() const; // Returns the status of the adoption
    int getAnimalId() const; // Returns the ID of the animal being adopted
    string getAdopter() const; // Returns the name of the adopter

// Setters for the adoption's properties
    void setId(int id); // Sets the ID of the adoption
    void setAdopterInfo(const string &adopterInfo); // Sets information about the adopter
    void setAnimal(Animal *animal); // Sets the animal being adopted
    void setStatus(AdoptionStatus status); // Sets the status of the adoption

// Equality operator for the Adoption class
    bool operator==(const Adoption &other) const {
        return this->id == other.id;
    }

private:
    int id; // Unique identifier for each adoption
    string adopterInfo; // Information about the adopter
    Animal *animal; // Pointer to the animal being adopted
    AdoptionStatus status; // Status of the adoption (e.g., pending, finalized)
    int animalId; // ID of the animal being adopted
    string adopter; // Name of the adopter
    // Helper function to set the status of the adoption to finalized
    void setStatusFinalised(const AdoptionStatus &status);
};