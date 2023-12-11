# Deliver Now
A project made during my "Object Orriented Programming" class using C++, Qt, file read-write opperations,
OOP principles and the Observer design pattern.

## What can it do?
This application stores data about couriers(name, list of assigned streets and a location) and packages(recipient, 
address, location and delivery status) in text files that automatically get updated on any addition to the databases.
When launched, the app will open one window for each courier, containing a list of undelivered packages on their
assigned street or in their range depending on their location, aswell as a "courier company" window displaying every
package (delivered packages are displayed with a green background). The "courier company" can add a new package by
inputting its information(delivery status is automatically false), and the addition will be shown to every affected
courier thanks to the Observer design pattern. In the couriers windows you will also find a combo box with all the 
streets present in the database. Selecting one of these streets will allow couriers to see only packages for the
selected street. 

## Run main.cpp to get started (you need to have Qt installed)
