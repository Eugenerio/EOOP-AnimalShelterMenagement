#include "Animal.h"

// Constructor for the Animal class
Animal::Animal(int id, const string& name, const string& breed, int age, const string& healthStatus, AnimalStatus status)
        : id(id), name(name), breed(breed), age(age), healthStatus(healthStatus), status(status) {}

// Getters
int Animal::getId() const {
    return id;
}


string Animal::getName() const {
    return name;
}

string Animal::getBreed() const {
    return breed;
}

int Animal::getAge() const {
    return age;
}

string Animal::getHealthStatus() const {
    return healthStatus;
}

Animal::AnimalStatus Animal::getAdoptionStatus() const {
    return status;
}

// Setters
void Animal::setId(int id) {
    this->id = id;
}

void Animal::setName(const string& name) {
    this->name = name;
}

void Animal::setBreed(const string& breed) {
    this->breed = breed;
}

void Animal::setAge(int age) {
    this->age = age;
}

void Animal::setHealthStatus(const string& healthStatus) {
    this->healthStatus = healthStatus;
}

void Animal::setAdoptionStatus(Animal::AnimalStatus status) {
    this->status = status;
}


// Checks if the animal is available for adoption
bool Animal::isAvailableForAdoption() const {
    return status == AnimalStatus::AVAILABLE;
}

// Updates the animal's information
void Animal::updateAnimalInfo(const string &name, const string &breed, int age) {
    setName(name);
    setBreed(breed);
    setAge(age);
}

// Updates the animal's adoption status
void Animal::updateAdoptionStatus(Animal::AnimalStatus status) {
    setAdoptionStatus(status);
}

ostream& operator<<(ostream& os, const Animal& animal) {
    os << "Animal ID: " << animal.getId() << endl;
    os << "Name: " << animal.getName() << endl;
    os << "Breed: " << animal.getBreed() << endl;
    os << "Age: " << animal.getAge() << endl;
    os << "Health status: " << animal.getHealthStatus() << endl;
    os << "Adoption status: " << (animal.getAdoptionStatus() == Animal::AnimalStatus::AVAILABLE ? "Available" : "Adopted") << endl;
    return os;
}











