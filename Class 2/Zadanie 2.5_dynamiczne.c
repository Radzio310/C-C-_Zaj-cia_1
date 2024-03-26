#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    const char *imie;
    const char *nazwisko;
    const char *numer;
} Contact;

Contact *contacts = NULL;
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
    contacts = realloc(contacts, (contactsCount + 1) * sizeof(Contact));
    contacts[contactsCount].imie = strdup(imie);
    contacts[contactsCount].nazwisko = strdup(nazwisko);
    contacts[contactsCount].numer = strdup(numer);
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
    free((char *)contacts[index].imie);
    free((char *)contacts[index].nazwisko);
    free((char *)contacts[index].numer);
    for (int i = index; i < contactsCount - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }
    contactsCount--;
    contacts = realloc(contacts, contactsCount * sizeof(Contact));
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

    // Free allocated memory
    for (int i = 0; i < contactsCount; i++)
    {
        free((char *)contacts[i].imie);
        free((char *)contacts[i].nazwisko);
        free((char *)contacts[i].numer);
    }
    free(contacts);

    return 0;
}
