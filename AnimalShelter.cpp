#include "AnimalShelter.h"
#include <algorithm>
using namespace std;


// Helper function to search for a staff member or volunteer
Staff* AnimalShelter::searchVolunteerOrStaff(int id) {
    // Search for staff member with given id
    for (auto& staff : staffMembers) {
        if (staff.getId() == id) {
            return &staff;
        }
    }

    // Search for volunteer with given id
    for (auto& volunteer : volunteers) {
        if (volunteer.getId() == id) {
            return &volunteer;
        }
    }

    return nullptr;
}

// Add a new animal to the shelter
bool AnimalShelter::addAnimal(const Animal &animal) {
    // Check if an animal with the same ID already exists
    if (find_if(animals.begin(), animals.end(), [&](const Animal& a) { return a.getId() == animal.getId(); }) != animals.end()) {
        return false;
    }

    // Add animal to list
    animals.push_back(animal);
    return true;
}

// Remove an animal from the shelter
bool AnimalShelter::removeAnimal(int id) {
    // Search for the animal with given id
    auto it = find_if(animals.begin(), animals.end(), [&](const Animal& a) { return a.getId() == id; });
    if (it != animals.end()) {
        animals.erase(it);
        return true;
    }
    return false;
}

// Update an existing animal's information
bool AnimalShelter::updateAnimal(int id, const string& name, const string& breed, int age, const string& healthStatus) {
    // Search for the animal by ID
    Animal* animal = searchAnimal(id);
    if (animal == nullptr) {
        return false;
    }

    // Update the animal's information
    animal->setName(name);
    animal->setBreed(breed);
    animal->setAge(age);
    animal->setHealthStatus(healthStatus);
    return true;
}

// Add a new staff member to the shelter
bool AnimalShelter::addStaff(const Staff& staff) {
    // Check if staff member already exists
    if (searchVolunteerOrStaff(staff.getId()) != nullptr) {
        return false;
    }

    // Add staff member to list
    staffMembers.push_back(staff);
    return true;
}

// Remove an existing staff member from the shelter
bool AnimalShelter::removeStaff(int id) {
// Search for the staff member by ID
    auto staffIter = staffMembers.begin();
    while (staffIter != staffMembers.end()) {
        if (staffIter->getId() == id) {
            staffMembers.erase(staffIter);
            return true;
        }
        ++staffIter;
    }
    return false;
}

// Update an existing staff member's information
bool AnimalShelter::updateStaff(int id, const string& name, const string& role, const string& schedule) {
// Search for the staff member by ID
    Staff* staff = searchVolunteerOrStaff(id);
    if (staff == nullptr) {
        return false;
    }
// Update the staff member's information
    staff->setName(name);
    staff->setRole(role);
    staff->setSchedule(schedule);
    return true;
}

// Add a new volunteer to the shelter
bool AnimalShelter::addVolunteer(const Volunteer& volunteer) {
// Check if volunteer already exists
    if (searchVolunteerOrStaff(volunteer.getId()) != nullptr) {
        return false;
    }
// Add volunteer to list
    volunteers.push_back(volunteer);
    return true;
}

// Remove an existing volunteer from the shelter
bool AnimalShelter::removeVolunteer(int id) {
// Search for the volunteer by ID
    auto volunteerIter = volunteers.begin();
    while (volunteerIter != volunteers.end()) {
        if (volunteerIter->getId() == id) {
            volunteers.erase(volunteerIter);
            return true;
        }
        ++volunteerIter;
    }
    return false;
}

// Update a volunteer's information
bool AnimalShelter::updateVolunteer(int id, const string &name, const string& schedule) {
    for (auto &volunteer : volunteers) {
        if (volunteer.getId() == id) {
            volunteer.setName(name);
            volunteer.setSchedule(schedule);
            return true;
        }
    }
    return false;
}

string AnimalShelter::statusToString(Adoption::AdoptionStatus status) {
    switch(status){
        case Adoption::AdoptionStatus::PENDING:
            return "pending";
        case Adoption::AdoptionStatus::APPROVED:
            return "approved";
        case Adoption::AdoptionStatus::REJECTED:
            return "rejected";
        default:
            return "unknown";
    }
}


bool AnimalShelter::addAdopter(const string& adopter) {
    if (find(adopters.begin(), adopters.end(), adopter) != adopters.end()) {
        return false; // adopter already exists
    }
    adopters.push_back(adopter);
    return true;
}

Adoption* AnimalShelter::searchAdoption(int id) {
    for (auto& adoption : adoptions) {
        if (adoption.getId() == id) {
            return &adoption;
        }
    }
    return nullptr; // adoption not found
}

bool AnimalShelter::createAdoption(const Adoption& adoption) {
    // Check if the animal exists
    Animal* animal = searchAnimal(adoption.getAnimalId());
    if (!animal) {
        return false;
    }

    // Check if the adopter exists
    if (!addAdopter(adoption.getAdopter())) {
        return false;
    }

    // Check if the animal is available for adoption
    if (animal->getAdoptionStatus() != Animal::AnimalStatus::AVAILABLE) {
        return false;
    }

    // Set the adoption status of the animal to "pending"
    animal->setAdoptionStatus(Animal::AnimalStatus::PENDING_ADOPTION);

    // Add the adoption record to the list of adoptions
    adoptions.push_back(adoption);

    return true;
}


bool AnimalShelter::updateAdoptionStatus(int id, Adoption::AdoptionStatus status) {
    // Check if adoption record exists
    Adoption *adoption = searchAdoption(id);
    if (adoption == nullptr) {
        cout << "Error: Adoption record with ID " << id << " does not exist." << endl;
        return false;
    }
    // Update status and print message
    adoption->setStatus(status);
    cout << "Adoption record with ID " << id << " updated to " << statusToString(status) << "." << endl;
    return true;
}

bool AnimalShelter::finalizeAdoption(int id) {
// Find the adoption record
    auto it = std::find_if(adoptions.begin(), adoptions.end(),
                           [&](const Adoption &adoption) { return adoption.getId() == id; });
    if (it == adoptions.end()) {
        return false;
    }
    Adoption &adoption = *it;
    // Find the animal
    Animal *animal = searchAnimal(adoption.getAnimalId());
    if (animal == nullptr) {
        return false;
    }

// Update the adoption status of the animal
    animal->setAdoptionStatus(Animal::AnimalStatus::AVAILABLE);

// Remove the adoption record from the list of adoptions
    adoptions.erase(it);

    cout << "Adoption with ID " << id << " finalized." << endl;
    return true;
}

    bool AnimalShelter::recordDonation(const Donation &donation) {
    // Check if the donation amount is positive
    if (donation.getAmount() <= 0) {
        return false;
    }

    // Add the donation record to the list of donations
    donations.push_back(donation);

    return true;
}



bool AnimalShelter::removeAdopter(const string& adopter) {
    bool removed = false;
    // Remove the adopter from the list of adopters
    auto adopterIter = find(adopters.begin(), adopters.end(), adopter);
    if (adopterIter != adopters.end()) {
        adopters.erase(adopterIter);
        removed = true;
    }

    // Remove the adopter from the adoptions
    for (auto iter = adoptions.begin(); iter != adoptions.end(); ) {
        if (iter->getAdopter() == adopter) {
            iter = adoptions.erase(iter);
            removed = true;
        } else {
            ++iter;
        }
    }

    return removed;
}

Animal* AnimalShelter::searchAnimal(int id) {
    for (Animal& animal : animals) {
        if (animal.getId() == id) {
            return &animal;
        }
    }
    return nullptr; // if animal with given id not found
}



Donation* AnimalShelter::searchDonation(int id) {
    for (Donation& donation : donations) {
        if (donation.getId() == id) {
            return &donation;
        }
    }
    return nullptr; // if donation with given id not found
}

void AnimalShelter::printAnimals(std::ostream& os) const {
    for (const auto& animal : animals) {
        os << "Animal ID: " << animal.getId() << endl;
        os << "Name: " << animal.getName() << endl;
        os << "Breed: " << animal.getBreed() << endl;
        os << "Age: " << animal.getAge() << endl;
        os << "Health status: " << animal.getHealthStatus() << endl;
        os << "Adoption status: "
           << (animal.getAdoptionStatus() == Animal::AnimalStatus::AVAILABLE ? "Available" : "Adopted") << endl;
   }
}



void AnimalShelter::printStaff(ostream& os) const {
    os << "Staff in the shelter:" << endl;
    for (const Staff& staff : staffMembers) {
        os << staff << endl;
    }
}

void AnimalShelter::printVolunteers(ostream& os) const {
    os << "Volunteers in the shelter:" << endl;
    for (const Volunteer& volunteer : volunteers) {
        os << volunteer << endl;
    }
}

void AnimalShelter::printAdoptions(ostream& os) const {
    os << "Adoptions made from the shelter:" << endl;
    for (const Adoption &adoption : adoptions) {
        os << adoption << endl;
    }
}

void AnimalShelter::printDonations(ostream& os) const {
    os << "Donations made to the shelter:" << endl;
    for (const Donation& donation : donations) {
        os << donation << endl;
    }
}

ostream &operator<<(ostream &os, const AnimalShelter &animalShelter) {
    os << "ANIMALS" << endl;
    animalShelter.printAnimals(os);
    os << endl << "STAFF" << endl;
    animalShelter.printStaff(os);
    os<< endl << "VOLUNTEERS" << endl;
    animalShelter.printVolunteers(os);
    os<< endl << "ADOPTIONS" << endl;
    animalShelter.printAdoptions(os);
    os<< endl << "DONATIONS" << endl;
    animalShelter.printDonations(os);

    return os;
}

