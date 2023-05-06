#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
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
    std::cout << "Test case 1: Add and remove animals" << std::endl;
    AnimalShelter shelter;
    Animal animal1(1, "Buddy", "Dog", 3, "Healthy", Animal::AnimalStatus::AVAILABLE);
    Animal animal2(2, "Molly", "Cat", 5, "Healthy", Animal::AnimalStatus::ADOPTED);

    // Add animals
    shelter.addAnimal(animal1);
    shelter.addAnimal(animal2);

    // Print the updated list of animals
    std::cout << "Animals added:" << std::endl << std::endl;
    shelter.printAnimals(std::cout);

    // Remove an animal
    shelter.removeAnimal(1);

    // Print the updated list of animals
    std::cout << "Animals after removal:" << std::endl;
    shelter.printAnimals(std::cout);

    // Attempt to remove an animal that does not exist (incorrect case)
    std::cout << "Attempt to remove non-existent animal:" << std::endl;
    if (!shelter.removeAnimal(3)) {
        std::cout << "Animal not found, cannot remove." << std::endl;
    }
}

void testCase2() {
    // Test case 2: Add and remove staff
    std::cout << "Test case 2: Add and remove staff" << std::endl;
    AnimalShelter shelter;
    Staff staff1(1, "Bob", "Manager", "Monday - Friday");
    shelter.addStaff(staff1);

    Staff staff2(2, "Sarah", "Vet", "Saturday, Sunday");
    shelter.addStaff(staff2);

    // Print the updated list of staff
    std::cout << "Staff added:" << std::endl;
    shelter.printStaff(std::cout);

    // Remove staff
    shelter.removeStaff(2);

    // Print the updated list of staff
    std::cout << "Staff after removal:" << std::endl;
    shelter.printStaff(std::cout);

    // Attempt to remove staff that does not exist (incorrect case)
    std::cout << "Attempt to remove non-existent staff:" << std::endl;
    if (!shelter.removeStaff(3)) {
        std::cout << "Staff not found, cannot remove." << std::endl;
    }
}

void testCase3() {
    // Test case 3: Add and remove volunteers
    std::cout << "Test case 3: Add and remove volunteers" << std::endl;
    AnimalShelter shelter;
    Volunteer volunteer1(1, "Roman", "Monday, Wednesday, Friday");
    shelter.addVolunteer(volunteer1);
    list<string> tasks1 {"Feed the animals", "Clean the kennels", "Walk the dogs"};
    volunteer1.setAssignedTasks(tasks1);
    list<string> tasks2{"Conduct a survey on a particular topic.",
                        "Organize a charity event for a cause.",
                        "Create social media content for a non-profit organization."};


    Volunteer volunteer2(2, "Jane", "Tuesday, Thursday, Saturday");
    shelter.addVolunteer(volunteer2);
    volunteer2.setAssignedTasks(tasks2);

    // Print the updated list of volunteers
    std::cout << "Volunteers added:" << std::endl;
    shelter.printVolunteers(std::cout);

    // Remove a volunteer
    shelter.removeVolunteer(1);

    // Print the updated list of volunteers
    std::cout << "Volunteers after removal:" << std::endl;
    shelter.printVolunteers(std::cout);

    // Attempt to remove a volunteer that does not exist (incorrect case)
    std::cout << "Attempt to remove non-existent volunteer:" << std::endl;
    if (!shelter.removeVolunteer(3)) {
        std::cout << "Volunteer not found, cannot remove." << std::endl;
    }
}

void testCase4() {
// Test case 4: Add and finalize adoptions
    std::cout << "\n Test case 4: Add and finalize adoptions" << std::endl;
    AnimalShelter shelter;
    Animal animal(1, "Charlie", "Mixed Breed", 2, "Healthy", Animal::AVAILABLE);
    shelter.addAnimal(animal);
    Adoption adoption(1, "25 years old", &animal, "John Doe");
    bool adoptionCreated = shelter.createAdoption(adoption);

    if (adoptionCreated) {
        std::cout << "Adoption record added successfully!" << std::endl;
    } else {
        std::cout << "Failed to add adoption record" << std::endl;
    }

    bool adoptionFinalized = shelter.finalizeAdoption(adoption.getId());

    if (adoptionFinalized) {
        std::cout << "Adoption finalized successfully!" << std::endl;
    } else {
        std::cout << "Failed to finalize adoption" << std::endl;
    }

//    The list after running testCase4() would be an empty list because the adoption
//    has been finalized and the animal is no longer available for adoption. The AnimalShelter's
//    list of available animals will not contain the animal that was adopted.
}

void testCase5() {
// Test case 5: Record and search donations
    std::cout << "\n Test case 5: Record and search donations" << std::endl;
    AnimalShelter shelter;
    Donation donation1(1, "Philanthropist", "Money $", "2022-12-01", 1000);
    Donation donation2(2, "Animal lover", "pack of Cat food", "2022-12-02", 2);
    // Record donations
    shelter.recordDonation(donation1);
    shelter.recordDonation(donation2);

// Print the updated list of donations
    std::cout << "Donations recorded:" << std::endl;
    shelter.printDonations(std::cout);

// Search for a donation
    Donation *foundDonation = shelter.searchDonation(1);
    if (foundDonation) {
        std::cout << "Found donation:" << std::endl;
        std::cout << *foundDonation << std::endl;
    } else {
        std::cout << "Donation not found." << std::endl;
    }
//    // Search for donations by donor name
//    std::cout << "Search for donations by donor name:" << std::endl;
//    std::vector<Donation> donationsByDonor = shelter.searchDonationsByDonor("Philanthropist");
//    std::cout << "Donations by Philanthropist:" << std::endl;
//    for (const auto& donation : donationsByDonor) {
//        std::cout << donation.toString() << std::endl;
//    }
//
//// Search for donations by donation type
//    std::cout << "Search for donations by donation type:" << std::endl;
//    std::vector<Donation> donationsByType = shelter.searchDonationsByType("Money $");
//    std::cout << "Donations of type Money $:" << std::endl;
//    for (const auto& donation : donationsByType) {
//        std::cout << donation.toString() << std::endl;
//    }

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

//void print_menu() {
//    cout << "===== MENU =====" << endl;
//    cout << "1. Add a new animal" << endl;
//    cout << "2. Remove an animal" << endl;
//    cout << "3. Update animal information" << endl;
//    cout << "4. Print the list of animals" << endl;
//    cout << "5. Add a new staff member" << endl;
//    cout << "6. Remove a staff member" << endl;
//    cout << "7. Update staff information" << endl;
//    cout << "8. Add a new volunteer" << endl;
//    cout << "9. Remove a volunteer" << endl;
//    cout << "10. Update volunteer information" << endl;
//    cout << "11. Add a new adopter" << endl;
//    cout << "12. Remove an adopter" << endl;
//    cout << "13. Print the list of adopters" << endl;
//    cout << "14. Update adoption status" << endl;
//    cout << "15. Quit" << endl;
//    cout << "================" << endl;
//}


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
                    break;
                }
                if (adoption->getAnimal()->getAdoptionStatus() != Animal::AnimalStatus::ADOPTED) {
                    cout << "Failed to finalize adoption. Animal is not marked as adopted." << endl;
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
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 15: //View all staff and volunteers
            {
                shelter.printVolunteers(cout);
                printSeparator();
                shelter.printStaff(cout);
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 16: //View all adoptions
            {
                shelter.printAdoptions(cout);
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 17: //View all donations
            {
                shelter.printDonations(cout);
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
            case 18: //Run all tests
            {
                testCase1();
                testCase2();
                testCase3();
                testCase4();
                testCase5();
                testCase6();
                std::this_thread::sleep_for(std::chrono::seconds(2));
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
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            }
        }
    }while(true);

    return 0;
}
