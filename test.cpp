#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <conio.h> // For _getch() on Windows
#include <cassert>
#include "AnimalShelter.h"

using namespace std;


// Prompts the user to enter a string and returns it
string promptString(string message) {
    string input;
    cout << message;
    getline(cin, input);
    return input;
}

// Prompts the user to enter an integer and returns it
int promptInt(string message) {
    int input;
    cout << message;
    cin >> input;
    while (cin.fail()) { // check for invalid input
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> input;
    }
    cin.ignore();
    return input;
}
// Prompts the user to enter a float and returns it
float promptFloat(string prompt) {
    float input;
    cout << prompt;
    cin >> input;
    while (cin.fail()) { // check for invalid input
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> input;
    }
    return input;
}
// Function to print separator lines
void printSeparator() {
    cout << "==================================" << endl;
}

// Function to print main menu
void printMainMenu() {
    printSeparator();
    cout << "ANIMAL SHELTER MANAGMENT SYSTEM" << endl;
    cout << "By eugenerio(Yevhenii Riabokin) || 2 sem ELKA" << endl;
    printSeparator();

    cout << "1. Add animal" << endl;
    cout << "2. Remove animal" << endl;
    cout << "3. Update animal" << endl;
    cout << "4. Add staff" << endl;
    cout << "5. Remove staff" << endl;
    cout << "6. Update staff" << endl;
    cout << "7. Add volunteer" << endl;
    cout << "8. Remove volunteer" << endl;
    cout << "9. Update volunteer" << endl;
    cout << "10. Create adoption" << endl;
    cout << "11. Update adoption status" << endl;
    cout << "12. Finalize adoption" << endl;
    cout << "13. Record donation" << endl;
    cout << "14. View all animals" << endl;
    cout << "15. View all staff members and volunteers" << endl;
    cout << "16. View all adoptions" << endl;
    cout << "17. View all donations" << endl;
    cout << "18. Run all tests" << endl;
    cout << "19. Quit" << endl;
    printSeparator();
    cout << endl;
}


void testCase1() {
    // Test case 1: Add and remove animals
    AnimalShelter shelter;
    Animal animal1(1, "Buddy", "Dog", 3, "Healthy", Animal::AnimalStatus::AVAILABLE);
    Animal animal2(2, "Molly", "Cat", 5, "Healthy", Animal::AnimalStatus::ADOPTED);

    // Add animals
    assert(shelter.addAnimal(animal1));
    assert(shelter.addAnimal(animal2));

    // Remove an animal
    assert(shelter.removeAnimal(1));

    // Attempt to remove an animal that does not exist (incorrect case)
    assert(!shelter.removeAnimal(3));
}

void testCase2() {
    // Test case 2: Add and remove staff
    AnimalShelter shelter;
    Staff staff1(1, "Bob", "Manager", "Monday - Friday");
    Staff staff2(2, "Sarah", "Vet", "Saturday, Sunday");

    // Add staff
    assert(shelter.addStaff(staff1));
    assert(shelter.addStaff(staff2));

    // Remove staff
    assert(shelter.removeStaff(2));

    // Attempt to remove staff that does not exist (incorrect case)
    assert(!shelter.removeStaff(3));
}

void testCase3() {
    // Test case 3: Add and remove volunteers
    AnimalShelter shelter;
    Volunteer volunteer1(1, "Roman", "Monday, Wednesday, Friday");
    Volunteer volunteer2(2, "Jane", "Tuesday, Thursday, Saturday");

    // Add volunteers
    assert(shelter.addVolunteer(volunteer1));
    assert(shelter.addVolunteer(volunteer2));

    // Remove a volunteer
    assert(shelter.removeVolunteer(1));

    // Attempt to remove a volunteer that does not exist (incorrect case)
    assert(!shelter.removeVolunteer(3));
}

void testCase4() {
    // Test case 4: Add and finalize adoptions
    AnimalShelter shelter;
    Animal animal(1, "Charlie", "Mixed Breed", 2, "Healthy", Animal::AVAILABLE);
    shelter.addAnimal(animal);
    Adoption adoption(1, "25 years old", &animal, "John Doe");

    // Create adoption
    assert(shelter.createAdoption(adoption));

    // Finalize adoption
    assert(shelter.finalizeAdoption(adoption.getId()));
}

void testCase5() {
    // Test case 5: Record and search donations
    AnimalShelter shelter;
    Donation donation1(1, "Philanthropist", "Money $", "2022-12-01", 1000);
    Donation donation2(2, "Animal lover", "pack of Cat food", "2022-12-02", 2);

    // Record donations
    assert(shelter.recordDonation(donation1));
    assert(shelter.recordDonation(donation2));

    // Search for a donation
    Donation *foundDonation = shelter.searchDonation(1);
    assert(foundDonation != nullptr);
}

void testCase6(){
//    Just print the animal shelter
    AnimalShelter shelter;
    // Add animals
    Animal animal1(1, "Charlie", "Mixed Breed", 2, "Healthy", Animal::AVAILABLE);
    shelter.addAnimal(animal1);

    Animal animal2(2, "Buddy", "Labrador Retriever", 3, "Vaccinated", Animal::AVAILABLE);
    shelter.addAnimal(animal2);

// Add donations
    Donation donation1(1, "Philanthropist", "Money $", "2022-12-01", 1000);
    Donation donation2(2, "Animal lover", "pack of Cat food", "2022-12-02", 2);

    shelter.recordDonation(donation1);
    shelter.recordDonation(donation2);

// Add adoptions
    Adoption adoption1(1, "25 years old", &animal1, "John Doe");
    shelter.createAdoption(adoption1);

    Adoption adoption2(2, "30 years old", &animal2, "Jane Smith");
    shelter.createAdoption(adoption2);

// Add volunteers
    Volunteer volunteer1(1, "Roman", "Monday, Wednesday, Friday");
    shelter.addVolunteer(volunteer1);

    Volunteer volunteer2(2, "Jane", "Tuesday, Thursday, Saturday");
    shelter.addVolunteer(volunteer2);

// Add staff members
    Staff staff1(1, "Bob", "Manager", "Monday - Friday");
    shelter.addStaff(staff1);

    Staff staff2(2, "Sarah", "Vet", "Saturday, Sunday");
    shelter.addStaff(staff2);

    cout << "ANIMAL SHELTER"<< endl;
    cout<< shelter << endl;
}

void waitForSpacebar() {
    while (_getch() != ' ') {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
int main(){
    AnimalShelter shelter;
    int choice;

    do {
        system("cls");
        printMainMenu();
        choice = promptInt("Enter your choice (1-15): ");
        switch (choice) {
            case 1: // Add animal
            {
                int id = promptInt("Enter the animal's ID: ");
                string name = promptString("Enter the animal's name: ");
                string breed = promptString("Enter the animal's breed: ");
                int age = promptInt("Enter the animal's age: ");
                string healthStatus = promptString("Enter animal's health status: ");
                Animal animal(id, name, breed, age, healthStatus, Animal::AnimalStatus::AVAILABLE);
                bool success = shelter.addAnimal(animal);
                if (success) {
                    cout << "Animal was added successfully." << endl;
                } else {
                    cout << "Failed to add the animal. An animal with the same ID already exists! " << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 2: //Remove animal
            {
                int id = promptInt("Enter the animal's ID: ");
                bool success = shelter.removeAnimal(id);
                if (success) {
                    cout << "Animal was removed successfully." << endl;
                } else {
                    cout << "Failed to remove the animal. Animal not found! " << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 3: // Update animal
            {
                int id = promptInt("Enter the animal's ID: ");
                Animal *animal = shelter.searchAnimal(id);
                if (animal == nullptr) {
                    cout << "Failed to update the animal. Animal not found!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
                string name = promptString("Enter the animal's new name: ");
                string breed = promptString("Enter the animal's new breed: ");
                int age = promptInt("Enter the animal's new age: ");
                string healthStatus = promptString("Enter animal's new health status: ");
                animal->setName(name);
                animal->setBreed(breed);
                animal->setAge(age);
                animal->setHealthStatus(healthStatus);
                cout << "Animal updated successfully." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 4: //Add staff
            {
                int id = promptInt("Enter the staff member's ID: ");
                string name = promptString("Enter the staff member's name: ");
                string role = promptString("Enter the staff member's role: ");
                string schedule = promptString("Enter staff member's schedule: ");
                Staff staff(id, name, role, schedule);
                bool success = shelter.addStaff(staff);
                if (success) {
                    cout << "Staff member was added successfully." << endl;
                } else {
                    cout << "Failed to add the staff memeber. A member with the same ID already exists! " << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 5: //Remove Staff
            {
                int id = promptInt("Enter the staff member's ID: ");
                bool success = shelter.removeStaff(id);
                if (success) {
                    cout << "Staff member was removed successfully." << endl;
                } else {
                    cout << "Failed to remove the staff member. Member not found! " << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 6: //Update staff
            {
                int id = promptInt("Enter the staff member's ID: ");
                Staff* staff = shelter.searchVolunteerOrStaff(id);
                if(staff == nullptr){
                    cout<<"Failed to update the staff member. Staff member not found!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
                string name = promptString("Enter the staff member's new name: ");
                string role = promptString("Enter the staff member's new role: ");
                string schedule = promptString("Enter staff member's new schedule: ");
                staff->setName(name);
                staff->setRole(role);
                staff->setSchedule(schedule);
                cout << "Staff member updated successfully." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 7: //Add Volunteer
            {
                int id = promptInt("Enter the volunteer's ID: ");
                string name = promptString("Enter the volunteer's name: ");
                string schedule = promptString("Enter volunteer's schedule: ");
                string task = promptString("Assign a task to the volunteer: ");
                Volunteer* volunteer = new Volunteer(id, name, schedule);
                volunteer->assignTask(task);
                bool success = shelter.addVolunteer(*volunteer);
                if(success){
                    cout << "Volunteer added successfully." << endl;
                }else{
                    cout<<"Failed to add the volunteer. A volunteer with the same ID already exists!"<<endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 8: //Remove volunteer
            {
                int id = promptInt("Enter the volunteer's ID: ");
                bool success = shelter.removeVolunteer(id);
                if(success){
                    cout << "Volunteer removed successfully." << endl;
                }else{
                    cout<<"Failed to remove the volunteer. A volunteer with the same ID does not exist!"<<endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 9: //Update volunteer
            {
                int id = promptInt("Enter the volunteer's ID: ");
                Volunteer* volunteer = dynamic_cast<Volunteer*>(shelter.searchVolunteerOrStaff(id));
                if (volunteer == nullptr) {
                    cout << "Failed to update the volunteer. Volunteer not found!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
                string name = promptString("Enter the volunteer's new name: ");
                string schedule = promptString("Enter volunteer's new schedule: ");
                string taskString = promptString("Assign a new task to the volunteer: ");
                list<string> task = { taskString };
                volunteer->setName(name);
                volunteer->setSchedule(schedule);
                volunteer->setAssignedTasks(task);
                cout << "Volunteer updated successfully." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 10: // Create adoption
            {
                int animalId = promptInt("Enter the ID of the animal being adopted: ");
                Animal* animal = shelter.searchAnimal(animalId);
                if (animal == nullptr) {
                    cout << "Failed to create adoption record. Animal not found!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
                int adopterId = promptInt("Enter the ID of the adopter: ");
                string adopterName = promptString("Enter the name of the adopter: ");
                string adopterInfo = promptString("Enter additional information about the adopter: ");
                Adoption adoption(adopterId, adopterInfo, animal, adopterName);
                shelter.createAdoption(adoption);
                animal->setAdoptionStatus(Animal::ADOPTED);
                cout << "Adoption record created successfully." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 11: // Update adoption status
            {
                int adoptionId = promptInt("Enter the ID of the adoption record: ");
                Adoption* adoption = shelter.searchAdoption(adoptionId);
                if (adoption == nullptr) {
                    cout << "Failed to update adoption status. Adoption record not found!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
                int statusOption = promptInt("Enter the new adoption status:\n1 - Pending\n2 - Approved\n3 - Rejected\n");
                Adoption::AdoptionStatus status;
                switch (statusOption) {
                    case 1:
                        status = Adoption::AdoptionStatus::PENDING;
                        break;
                    case 2:
                        status = Adoption::AdoptionStatus::APPROVED;
                        break;
                    case 3:
                        status = Adoption::AdoptionStatus::REJECTED;
                        break;
                    default:
                        cout << "Invalid option. Adoption status not updated!" << endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        break;
                }
                adoption->setStatus(status); // getAnimal()->setAdoptionStatus(static_cast<Animal::AnimalStatus>(status));
                adoption->getAnimal()->setAdoptionStatus(static_cast<Animal::AnimalStatus>(status));
                cout << "Adoption status updated successfully." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 12: // Finalize adoption
            {
                int adoptionId = promptInt("Enter the ID of the adoption record: ");
                Adoption* adoption = shelter.searchAdoption(adoptionId);
                if (adoption == nullptr) {
                    cout << "Failed to finalize adoption. Adoption record not found!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
                if (adoption->getAnimal()->getAdoptionStatus() != Animal::AnimalStatus::ADOPTED) {
                    cout << "Failed to finalize adoption. Animal is not marked as adopted." << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
                adoption->finalizeAdoption();
                cout << "Adoption finalized successfully." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 13: //Record donation
            {
                int id = promptInt("Enter the donation's ID: ");
                string donorName = promptString("Enter the donor's name: ");
                string discription = promptString("Enter the donation description: ");
                string date = promptString("Enter the donation date: ");
                float amount = promptFloat("Enter the amount donated: ");
                Donation donation(id, donorName, discription, date, amount);
                bool success = shelter.recordDonation(donation);
                if (success) {
                    cout << "Donation was added successfully." << endl;
                } else {
                    cout << "Failed to add the donation. A donation with the same ID already exists! " << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 14: //View all animals
            {
                shelter.printAnimals(cout);
                printSeparator();
                cout << "Press 'Space' to go to the menu" << endl;
                printSeparator();
                waitForSpacebar();
                break;
            }
            case 15: //View all staff and volunteers
            {
                shelter.printVolunteers(cout);
                printSeparator();
                shelter.printStaff(cout);
                printSeparator();
                cout << "Press 'Space' to go to the menu" << endl;
                printSeparator();
                waitForSpacebar();
                break;
            }
            case 16: //View all adoptions
            {
                shelter.printAdoptions(cout);
                printSeparator();
                cout << "Press 'Space' to go to the menu" << endl;
                printSeparator();
                waitForSpacebar();
                break;
            }
            case 17: //View all donations
            {
                shelter.printDonations(cout);
                printSeparator();
                cout << "Press 'Space' to go to the menu" << endl;
                printSeparator();
                waitForSpacebar();
                break;
            }
            case 18: //Run all tests
            {
                printSeparator();
                testCase1();
                cout << "Test#1 passed" << endl;
                printSeparator();
                testCase2();
                cout << "Test#2  passed" << endl;
                printSeparator();
                testCase3();
                cout << "Test#3 passed" << endl;
                printSeparator();
                testCase4();
                cout << "Test#4 passed" << endl;
                printSeparator();
                testCase5();
                cout << "Test#5 passed" << endl;
                printSeparator();
                testCase6();
                printSeparator();
                cout << "End of the tests" << endl;
                printSeparator();
                cout << "Press 'Space' to go to the menu" << endl;
                printSeparator();
                waitForSpacebar();
                break;
            }
            case 19: // quit
            {
                cout << "Exiting program." << endl;
                return 0;
            }
            default:
            {
                cout<<"Invalid choice. Please enter a number between 1 and 19"<< endl;
                printSeparator();
                cout << "Press 'Space' to go to the menu" << endl;
                printSeparator();
                waitForSpacebar();
                break;
            }
        }
    }while(true);

    return 0;
}

