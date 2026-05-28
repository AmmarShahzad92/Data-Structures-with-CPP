#include <iostream>
#include <cstring>
using namespace std;

const int MAX_PATIENTS = 100;

struct Patient {
    char id[10];
    char type[15]; // "critical" or "non-critical"
};

Patient* queue[MAX_PATIENTS]; // array of patient pointers
int front = 0;
int rear = 0;

// Helper: create patient
Patient* createPatient(const char* id, const char* type) {
    Patient* p = new Patient;
    strcpy(p->id, id);
    strcpy(p->type, type);
    return p;
}

// Helper: find index of a patient
int findPatientIndex(const char* id) {
    for (int i = front; i < rear; ++i) {
        if (strcmp(queue[i]->id, id) == 0)
            return i;
    }
    return -1;
}

// Insert patient at specific index
void insertAt(int index, Patient* p) {
    for (int i = rear; i > index; --i) {
        queue[i] = queue[i - 1];
    }
    queue[index] = p;
    rear++;
}

// Add patient
void addPatient(const char* type, const char* id) {
    Patient* p = createPatient(id, type);

    if (strcmp(type, "critical") == 0) {
        // Insert before first non-critical
        int i = front;
        while (i < rear && strcmp(queue[i]->type, "critical") == 0) {
            i++;
        }
        insertAt(i, p);
    } else {
        queue[rear++] = p; // add to end
    }
}

// Declare emergency
void declareEmergency(const char* id) {
    int index = findPatientIndex(id);
    if (index == -1) {
        cout << "Patient " << id << " not found!" << endl;
        return;
    }

    Patient* p = queue[index];
    for (int i = index; i > front; --i) {
        queue[i] = queue[i - 1];
    }
    queue[front] = p;

    cout << "Emergency declared: " << id << " moved to the front" << endl;
}

// Treat patient
void treatPatient() {
    if (front == rear) {
        cout << "No patients in queue!" << endl;
        return;
    }
    cout << "Treating patient " << queue[front]->id << endl;
    delete queue[front];
    for (int i = front; i < rear - 1; ++i) {
        queue[i] = queue[i + 1];
    }
    rear--;
}

// Show queue
void showQueue() {
    cout << "Queue: ";
    for (int i = front; i < rear; ++i) {
        cout << queue[i]->id;
        if (i < rear - 1)
            cout << ", ";
    }
    cout << endl;
}

// Main function to simulate scenario
int main() {
    addPatient("critical", "P1");
    addPatient("non-critical", "P2");
    addPatient("critical", "P3");
    treatPatient();
    addPatient("non-critical", "P4");
    declareEmergency("P4");
    showQueue();
    treatPatient();
    treatPatient();

    // Optional: Clean up remaining dynamically allocated memory
    while (front < rear) {
        delete queue[front++];
    }

    return 0;
}
