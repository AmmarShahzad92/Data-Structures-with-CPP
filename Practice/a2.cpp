#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

// Patient struct to represent each patient in the ER
struct Patient {
    string id;
    bool isCritical;
    bool isEmergency;
    int arrivalOrder;
};

// Custom comparator for the priority queue
struct PatientComparator {
    bool operator()(const Patient& p1, const Patient& p2) {
        // Emergency patients have highest priority
        if (p1.isEmergency != p2.isEmergency) {
            return p1.isEmergency < p2.isEmergency;
        }
        // Critical patients have higher priority than non-critical
        if (p1.isCritical != p2.isCritical) {
            return p1.isCritical < p2.isCritical;
        }
        // For patients with same priority, first-come-first-served
        return p1.arrivalOrder > p2.arrivalOrder;
    }
};

// Global variables
priority_queue<Patient, deque<Patient>, PatientComparator> patientQueue;
unordered_map<string, Patient> patientMap;
int arrivalCounter = 0;

// Function to add a patient to the ER queue
void addPatient(string type, string id) {
    bool isCritical = (type == "critical");
    Patient newPatient = {id, isCritical, false, arrivalCounter++};
    
    patientQueue.push(newPatient);
    patientMap[id] = newPatient;
    
    cout << "Patient " << id << " added to the queue." << endl;
}

// Function to declare an emergency for a patient
void declareEmergency(string id) {
    if (patientMap.find(id) == patientMap.end()) {
        cout << "Patient " << id << " not found." << endl;
        return;
    }
    
    // Remove all patients from the priority queue
    deque<Patient> tempDeque;
    while (!patientQueue.empty()) {
        Patient p = patientQueue.top();
        patientQueue.pop();
        tempDeque.push_back(p);
    }
    
    // Update the patient's emergency status and re-add all patients to the queue
    for (auto& p : tempDeque) {
        if (p.id == id) {
            p.isEmergency = true;
            patientMap[id].isEmergency = true;
        }
        patientQueue.push(p);
    }
    
    cout << "Emergency declared: " << id << " moved to the front" << endl;
}

// Function to treat the next patient in queue
void treatPatient() {
    if (patientQueue.empty()) {
        cout << "No patients in the queue." << endl;
        return;
    }
    
    Patient patient = patientQueue.top();
    patientQueue.pop();
    patientMap.erase(patient.id);
    
    cout << "Treating patient " << patient.id << endl;
}

// Function to display the current queue
void showQueue() {
    if (patientQueue.empty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    
    // Copy the priority queue to a temporary queue to display the order
    priority_queue<Patient, deque<Patient>, PatientComparator> tempQueue = patientQueue;
    list<string> patientOrder;
    
    while (!tempQueue.empty()) {
        patientOrder.push_back(tempQueue.top().id);
        tempQueue.pop();
    }
    
    cout << "Queue: ";
    bool first = true;
    for (const auto& id : patientOrder) {
        if (!first) {
            cout << ", ";
        }
        cout << id;
        first = false;
    }
    cout << endl;
}

// Function to parse the command input
string parseInput(string& input, string& arg1, string& arg2) {
    string command;
    size_t pos = input.find('(');
    if (pos != string::npos) {
        command = input.substr(0, pos);
        size_t end = input.find(')');
        if (end != string::npos) {
            string args = input.substr(pos + 1, end - pos - 1);
            size_t comma = args.find(',');
            if (comma != string::npos) {
                arg1 = args.substr(0, comma);
                arg2 = args.substr(comma + 1);
                // Trim spaces
                while (!arg2.empty() && arg2[0] == ' ') arg2.erase(0, 1);
            } else {
                arg1 = args;
                arg2 = "";
            }
        }
    } else {
        command = input;
    }
    return command;
}

int main() {
    string input, command, arg1, arg2;
    
    while (true) {
        cout << "\nEnter command (or 'exit' to quit): ";
        getline(cin, input);
        
        command = parseInput(input, arg1, arg2);
        
        if (command == "addPatient") {
            addPatient(arg1, arg2);
        }
        else if (command == "declareEmergency") {
            declareEmergency(arg1);
        }
        else if (command == "treatPatient") {
            treatPatient();
        }
        else if (command == "showQueue") {
            showQueue();
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command. Try again." << endl;
        }
    }
    
    return 0;
}
