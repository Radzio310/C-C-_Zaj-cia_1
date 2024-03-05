#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 20

typedef struct
{
    char imie[NAME_LENGTH];
    char nazwisko[NAME_LENGTH];
    char numer[NUMBER_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactsCount = 0;

void displayContacts()
{
    if (contactsCount == 0)
    {
        printf("Contacts book is empty.\n");
        return;
    }
    for (int i = 0; i < contactsCount; i++)
    {
        printf("%d. %s %s - %s\n", i + 1, contacts[i].imie, contacts[i].nazwisko, contacts[i].numer);
    }
}

void addContact(const char *imie, const char *nazwisko, const char *numer)
{
    if (contactsCount >= MAX_CONTACTS)
    {
        printf("Contacts book is full.\n");
        return;
    }
    
    strncpy(contacts[contactsCount].imie, imie, NAME_LENGTH);
    contacts[contactsCount].imie[NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    strncpy(contacts[contactsCount].nazwisko, nazwisko, NAME_LENGTH);
    contacts[contactsCount].nazwisko[NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    strncpy(contacts[contactsCount].numer, numer, NUMBER_LENGTH);
    contacts[contactsCount].numer[NUMBER_LENGTH - 1] = '\0'; // Ensure null-termination
    contactsCount++;
    printf("Contact added successfully.\n");
}

void deleteContact(int index)
{
    if (index < 1 || index > contactsCount)
    {
        printf("Invalid contact number.\n");
        return;
    }
    index--; // Adjust for 0-based index
    for (int i = index; i < contactsCount - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }
    contactsCount--;
    printf("Contact deleted successfully.\n");
}

int main()
{
    printf("Contacts List/Book\n");

    // Example usage
    addContact("John", "Doe", "123456789");
    addContact("Jane", "Doe", "987654321");
    displayContacts();
    deleteContact(1);
    displayContacts();

    return 0;
}
