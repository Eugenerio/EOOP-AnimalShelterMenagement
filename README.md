# EOOP-AnimalShelterMenagement
A small c++ project for uni.
# Animal Shelter Management System
This project is a software system designed to manage various aspects of an animal shelter, including animals, staff, volunteers, adoptions, and donations. The system provides users with the ability to add, remove, and update information about animals, staff members, volunteers, adopters, and donations. It also includes search and display functionalities for easier data management.

# Class and Data Structures Overview
The Animal Shelter Management System is built with the following classes:

AnimalShelter: This class serves as the main interface for the management system. It contains methods for adding, removing, and updating animals, staff, volunteers, adoptions, and donations. It also provides search functionality for animals, adoptions, and donations, as well as methods for managing adopters.

Animal: This class represents an individual animal within the shelter. It includes information such as ID, name, species, age, health status, and adoption status. Methods in this class allow for updating the animal's information, checking its availability for adoption, and setting the animal's attributes using setters.

Staff: This class represents a staff member within the shelter. It includes information such as ID, name, role, and schedule. Methods in this class allow for updating staff information, managing their schedules and responsibilities, and setting the staff member's attributes using setters.

Volunteer: This class represents a volunteer at the shelter, inheriting from the Staff class. It includes ID, name, availability, and assigned tasks. Methods in this class allow for updating volunteer information, managing their schedules and responsibilities, and setting the volunteer's attributes using setters.

Adoption: This class represents an adoption process, including the adopter's information, the animal being adopted, and the status of the adoption. Methods in this class handle updating the adoption status, finalizing the adoption process, and setting the adoption attributes using setters.

Donation: This class represents a monetary or material donation to the shelter. It includes information such as the donor's name, donation amount or item description, and date of donation. Methods in this class handle recording and tracking donations and setting the donation attributes using setters.

# Restrictions, Limits, Assumptions
There are several restrictions, limits, and assumptions that should be kept in mind when using the Animal Shelter Management System:

Animal IDs, Adoption IDs, Donation IDs, and Staff IDs are unique positive integers.
Animal age and Staff schedule are non-negative integers.
An animal’s adoption status is boolean (true if the animal is adopted, false if not).
Adopter information should be provided in the form of a string.
Volunteer tasks are represented as strings in an ordered list.
Adoption statuses and health statuses are represented as strings.
