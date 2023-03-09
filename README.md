# Airline Reservation System

In this project, i have implemented the Airline Reservation Sytem using linked lists. It has the following features :
- Reserve a ticket for a particular passenger
- Cancel the ticket for a particular passenger
- Check if the ticket exists of a passenger
- Displaying all the tickets of all the Airlines
- Exiting the program
 ---
### Implementation Logic
Make 2 classes named - PassengerNode and AirlineNode. PassengerNode is the normal linked list Node Class but the AirlineNode is a little different from the usual linked list Node Class. In AirlineNode there are 3 elements - prev, next and data.
The prev element is of the type PassengerNode* and data is of the type AirlineNode*. Prev acts like head of the passenger linked list. Hence for each Airline we can store as many number of passengers by adding the names to the linked lists whose head is prev.
 
I am planning toimprovise this code by adding new features and making the outputs look better!