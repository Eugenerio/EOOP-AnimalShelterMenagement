#include "Adoption.h"
#include "Animal.h"
// Implementation of the Adoption class

// Constructor for the Adoption class
Adoption::Adoption(int id, const string &adopterInfo, Animal *animal, const string &adopterName) {
    this->id = id;
    this->adopterInfo = adopterInfo;
    this->animal = animal;
    this->status = AdoptionStatus::PENDING;
    this->animalId = animal->getId();
    this->adopter = adopterName;
}

// Destructor for the Adoption class
Adoption::~Adoption() {
    // Set the animal's adoption status to AVAILABLE when the adoption is destroyed
    if (this->animal != nullptr) {
        this->animal->updateAdoptionStatus(Animal::AnimalStatus::AVAILABLE);
    }
}

// Updates the status of the adoption
void Adoption::updateAdoptionStatus(AdoptionStatus status) {
    this->status = status;
    if (status == AdoptionStatus::APPROVED) {
        // If the adoption is approved, update the animal's status to ADOPTED
        this->animal->updateAdoptionStatus(Animal::AnimalStatus::ADOPTED);
    }
}

// Finalizes the adoption process
bool Adoption::finalizeAdoption() {
    if (this->status == AdoptionStatus::APPROVED) {
        // If the adoption is approved, set the status to finalized
        setStatusFinalised(AdoptionStatus::APPROVED);
        return true;
    } else {
        // If the adoption is not approved, set the status to rejected
        setStatusFinalised(AdoptionStatus::REJECTED);
        return false;
    }
}

// Helper function to set the status of the adoption to finalized
void Adoption::setStatusFinalised(const AdoptionStatus &status) {
    this->status = status;
}

// Getters for the adoption's properties
int Adoption::getId() const {
    return this->id;
}

string Adoption::getAdopterInfo() const {
    return this->adopterInfo;
}

Animal*  Adoption::getAnimal() const {
    return this->animal;
}

Adoption::AdoptionStatus Adoption::getStatus() const {
    return this->status;
}

int Adoption::getAnimalId() const {
    return this->animalId;
}

string Adoption::getAdopter() const {
    return this->adopter;
}

// Setters for the adoption's properties
void Adoption::setId(int id) {
    this->id = id;
}

void Adoption::setAdopterInfo(const string &adopterInfo) {
    this->adopterInfo = adopterInfo;
}

void Adoption::setAnimal(Animal *animal) {
    this->animal = animal;
    this->animalId = animal->getId();
}

void Adoption::setStatus(AdoptionStatus status) {
    this->status = status;
}

ostream &operator<<(ostream &os, const Adoption &adoption) {
    os << "Adoption " << adoption.getId() << " - ";
    if (adoption.getStatus() == Adoption::AdoptionStatus::PENDING) {
        os << "Pending approval";
    } else if (adoption.getStatus() == Adoption::AdoptionStatus::APPROVED) {
        os << "Approved";
    } else {
        os << "Rejected";
    }
    os << endl << "Adopter: " << adoption.getAdopter() << endl << "Adopter information: " << adoption.getAdopterInfo() << endl;
    os << "Animal information: " << endl << *(adoption.getAnimal());
    return os;
}
