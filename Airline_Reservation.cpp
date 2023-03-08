#include <iostream>
#include <string>
using namespace std;


class passengerNode{
private:
    passengerNode* next;
    string data;
    passengerNode(string d){
        data = d;
        next = NULL;
    }
    friend class AirlineReservationNode;
};


class AirlineNode{
private:
    passengerNode* prev;
    AirlineNode* next;
    string data;
    AirlineNode(string d){
        data = d;
        prev = NULL;
        next = NULL;
    }
    friend class AirlineReservationNode;
};


class AirlineReservationNode{
private: 
    AirlineNode* head;
    string passengerName;
    
public:
    AirlineReservationNode();
    AirlineNode* searchFlight(string s);
    AirlineNode* searchPassenger (string s);
    void ticketReservation(string s1,string s2);
    void cancelTicket(string s);
    void checkTicket(string s);
    void displayTicket();
};


AirlineReservationNode:: AirlineReservationNode(){
    head = NULL;
    int choice;
    while (true){
        cout << "====  Welcome to Airline Ticket Resevation  ====\n" << endl;
        cout << "Enter your choice" << endl;
        cout << "1. For Ticket Reservation" << endl;
        cout << "2. For cancelling ticket" << endl;
        cout << "3. For checking ticket" << endl;
        cout << "4. For display ticket" << endl;
        cout << "5. For ending the program\n" << endl;
        cin >> choice;
        if(choice == 1){
            string s1,s2;
            cout << "Enter the flight name: ";
            cin.ignore();
            getline(cin,s1);
            cout << "Enter the passenger name: ";
            getline(cin,s2);
            ticketReservation(s1,s2);
            cout << "\n";
        }
        else if(choice == 2){
            string s;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin,s);
            cancelTicket(s);
            cout << "\n";
        }
        else if(choice == 3){
            string s;
            cout << "Enter the passenger name whose ticket you want to check: ";
            cin.ignore();
            getline(cin,s);
            checkTicket(s);
        }
        else if(choice == 4){
            cout << "\n----Displaying all the tickets----\n" << endl;
            displayTicket();
            cout << "\n";
        }
        else if(choice == 5){
            cout << "\n\n----------Thankyou for using the Airline Reservation System----------\n\n" << endl;
            break;
        }
        else
            cout << "Please enter a correct number\n" << endl;
    }
}


AirlineNode* AirlineReservationNode:: searchPassenger (string s){
    if(head == NULL)
        return NULL;
    else{
        AirlineNode* temp = head;
        while(temp!=NULL){
            passengerNode* temp1 = temp -> prev;
            while(temp1!=NULL){
                if(temp1->data == s)
                    return temp;
                temp1 = temp1 -> next;
            }
            temp = temp -> next;
        }
        return NULL;
    }
}


AirlineNode* AirlineReservationNode:: searchFlight (string s){
    if(head == NULL)
        return NULL;
    else{
        AirlineNode* temp = head;
        while(temp!=NULL){
            if(temp->data == s)
                return temp;
            temp = temp -> next;
        }
        return NULL;
    }
}


void AirlineReservationNode:: ticketReservation (string s1,string s2){
    // If the linked list is empty
    if (head == NULL){
        AirlineNode* new_node1 = new AirlineNode(s1);
        passengerNode* new_node2 = new passengerNode(s2);
        head = new_node1;
        new_node1 -> prev = new_node2;
    }
    else{
        AirlineNode* temp = searchFlight(s1);
        if(temp == NULL){
            // Airline not present, adding in the end
            AirlineNode* temp1 = head;
            AirlineNode* new_node1 = new AirlineNode(s1);
            passengerNode* new_node2 = new passengerNode(s2);
            while(temp1->next!=NULL){
                temp1 = temp1 -> next;
            }
            temp1 -> next = new_node1;
            new_node1 -> prev = new_node2;
        }
        else{
            // Airline is already present, adding the passenger link
            passengerNode* new_node = new passengerNode(s2);
            passengerNode* temp1 =  temp -> prev;
            if (temp -> prev == NULL){ // If the passengers ticket was cancelled and the airline is there but no passenger's
                temp->prev = new_node;
            }
            else{
                while (temp1 -> next != NULL){
                    temp1 = temp1 -> next;
                }
                temp1 -> next = new_node;
            }
        }
    }
}


void AirlineReservationNode::cancelTicket(string s){
    AirlineNode* temp = searchPassenger(s);
    if(temp == NULL)
        cout << "There is no ticket to cancel" << endl;
    else{
        passengerNode* prev1 = NULL;
        passengerNode* curr = temp -> prev;
        // If the passenger whose ticket we want to cancel is at the head node itself
        if((temp->prev)!=NULL && (temp->prev) -> data == s){
            temp->prev = curr -> next;
            delete curr;
        }
        // passenger is not at the head node, can be anywhere except the head node
        else{
            while((curr!=NULL) && (curr -> data != s)){
                prev1 = curr; 
                curr = curr -> next;
            }
            prev1 -> next = curr -> next;
            delete curr;
        }
        cout << "Cancelled the ticket of " << s << endl;
    }
    
}


void AirlineReservationNode:: checkTicket(string s){
    AirlineNode* temp = searchPassenger(s); // This function checks if a passenger is present or not
    if(temp != NULL)
        cout << "The passenger " << s << "'s ticket exists" << endl;
    else
        cout << "The passenger " << s << "'s ticket doesn't exist" << endl;
}


void AirlineReservationNode::displayTicket (){
    // If the linked list is empty
    if(head == NULL){
        cout << "There are no tickets that are reserved" << endl;
    }

    AirlineNode* temp = head;
    int count = 0;
    while(temp!=NULL){
        passengerNode* temp1 = temp->prev;
        while(temp1!=NULL){
            count++;
            cout << count << ") " << temp -> data << endl;
            cout << "   " << temp1 -> data << endl;
            cout << "\n";
            temp1 = temp1 -> next;
        }
        temp = temp -> next;
    }
    // If the Airline Node is stored but doesn't contain passengers (incase you stored then cancelled the tickets, this may happend)
    if (count == 0)
        cout << "There are no tickets to display" << endl;
}


int main(){
    AirlineReservationNode obj;
    return 0;
}