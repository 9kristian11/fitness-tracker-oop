# Fitness Tracker OOP Project

## Description
Fitness Tracker is a C++ console application developed as a school Object-Oriented Programming project.
The purpose of the project is to help users keep track of their workouts, exercises, goals, personal records, and overall fitness progress. The application allows users to create a profile, manage workouts, save their data, and view different statistics.

## Features:
### User Profile Management
* Create and edit a user profile
* Store information such as:
  * Name
  * Gender
  * Age
  * Weight
  * Height
    
### Workout Management
* Add workouts
* Edit workouts
* Delete workouts
* View workout history
  
### Exercise Management
* Add exercises to workouts
* Support for different exercise types:
  * StrengthExercise
  * CardioExercise
    
### Personal Records
* Add personal records (PRs)
* View saved personal records

### Goals
* Create fitness goals
* View current goals

### Statistics
* View monthly workout statistics
* Calculate total training volume

### Search
* Search workouts by date

### Inactivity Reminder
* Check how many days have passed since the last workout
* Display a reminder if the user has been inactive

### Data Persistence
* Save data to a file
* Load saved data when the program starts

## OOP Concepts Used:
### Encapsulation
Class data is stored as private or protected members and accessed through methods.

### Inheritance
The project uses inheritance through the Exercise hierarchy:
Exercise
* StrengthExercise
* CardioExercise

### Polymorphism
Workouts store exercises using Exercise pointers, allowing different exercise types to be handled through a common interface.

### Composition
A User contains:
* Workouts
* Goals
* Personal Records

## Project Structure
* User
* Workout
* Exercise
* StrengthExercise
* CardioExercise
* Goal
* PersonalRecord
* StatisticsManager

## Technologies Used:
* C++
* Object-Oriented Programming
* STL (vector, string)
* File Handling (fstream)

## Author:
Kristian Lyubomirov
10A TUES
