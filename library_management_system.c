#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

// Structure to store book information
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

// Function prototypes
void addBook(Book library[], int *bookCount);
void viewBooks(Book library[], int bookCount);
void deleteBook(Book library[], int *bookCount);
void clearAll();

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;
    while (1) {
        // Display menu
        printf("\n___Library Management System___\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("3. Delete a book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearAll();  

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                viewBooks(library, bookCount);
                break;
            case 3:
                deleteBook(library, &bookCount);
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
// Function to add a book to the library
void addBook(Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    // Get the book details
    printf("Enter book title: ");
    fgets(library[*bookCount].title, sizeof(library[*bookCount].title), stdin);
    library[*bookCount].title[strcspn(library[*bookCount].title, "\n")] = '\0';  // Remove newline character
    printf("Enter book author: ");
    fgets(library[*bookCount].author, sizeof(library[*bookCount].author), stdin);
    library[*bookCount].author[strcspn(library[*bookCount].author, "\n")] = '\0';  // Remove newline character
    (*bookCount)++; 
    printf("Book added successfully!\n");
}
// Function to view all books in the library
void viewBooks(Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\n=== List of Books ===\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. Title: %s, Author: %s\n", i + 1, library[i].title, library[i].author);
    }
}
// Function to delete a book from the library
void deleteBook(Book library[], int *bookCount) {
    if (*bookCount == 0) {
        printf("No books to delete.\n");
        return;
    }

    int bookIndex;
    printf("Enter the book number to delete: ");
    scanf("%d", &bookIndex);
    clearAll(); 

    if (bookIndex < 1 || bookIndex > *bookCount) {
        printf("Invalid book number!\n");
        return;
    }

    for (int i = bookIndex - 1; i < *bookCount - 1; i++) {
        library[i] = library[i + 1];
    }

    (*bookCount)--;  
    printf("Book deleted successfully!\n");
}

void clearAll() {
    while (getchar() != '\n'); 
}
