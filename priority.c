// 10.Write a C program to implement a Priority Queue for a Hospital Management
// System.
// Each patient record should include: Name of Patient, Time of Arrival,
// Condition, Priority (1 = Highest, larger number = lower priority)
// Perform the following operations using a priority queue:
// 1. Insert new patient details into the queue.
// 2. Display the list of patients according to their priority order (lowest number
// first).
// 3. Delete (serve) the patient with the highest priority (lowest priority number).
// Use the following sample data to initialize the queue:
// Name of
// Patient
// Time of
// Arrival Condition Priority
// Pramod 10:35 Headache 4
// Narendra 10:40 Fracture 2
// Harish 10:45 Heart Attack 1
// Vandana 10:50 Fever 3


#include <stdio.h>
#include <string.h>
#define MAX 100

struct patient {
    char name[30];
    char time[10];
    char condition[30];
    int priority;
};

struct patient q[MAX];
int n = 0;

void insert(struct patient p) {
    int i;

    if (n == MAX) {
        printf("Queue is Full\n");
        return;
    }

    i = n - 1;

    while (i >= 0 && q[i].priority > p.priority) {
        q[i + 1] = q[i];
        i--;
    }

    q[i + 1] = p;
    n++;
}

void display() {
    int i;

    if (n == 0) {
        printf("Queue is Empty\n");
        return;
    }

    printf("\nName\tTime\tCondition\tPriority\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%d\n",
               q[i].name, q[i].time,
               q[i].condition, q[i].priority);
    }
}

void delete() {
    int i;

    if (n == 0) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Patient Served: %s\n", q[0].name);

    for (i = 0; i < n - 1; i++)
        q[i] = q[i + 1];

    n--;
}

int main() {
    int choice;
    struct patient p;

    insert((struct patient){"Pramod", "10:35", "Headache", 4});
    insert((struct patient){"Narendra", "10:40", "Fracture", 2});
    insert((struct patient){"Harish", "10:45", "Heart Attack", 1});
    insert((struct patient){"Vandana", "10:50", "Fever", 3});

    do {
        printf("\n1. Insert Patient");
        printf("\n2. Display Patients");
        printf("\n3. Serve Patient");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient Name: ");
                scanf("%s", p.name);

                printf("Enter Arrival Time: ");
                scanf("%s", p.time);

                printf("Enter Condition: ");
                scanf("%s", p.condition);

                printf("Enter Priority: ");
                scanf("%d", &p.priority);

                insert(p);
                break;

            case 2:
                display();
                break;

            case 3:
                delete();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}