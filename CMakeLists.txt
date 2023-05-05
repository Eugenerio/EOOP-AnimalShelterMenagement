cmake_minimum_required(VERSION 3.23)
project(new_lab_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(new_lab_project
        Adoption.h
        Animal.h
        AnimalShelter.h
        Donation.h
        Staff.h
        test.cpp
        Volunteer.h Animal.cpp Adoption.cpp Donation.cpp Staff.cpp Volunteer.cpp AnimalShelter.cpp)
