#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define book structure
struct book {
    char title[50];
    char author[50];
    int id;
    int is_available;
};

// function to display main menu
void display_menu() {
    printf("\n\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. Exit\n");
}

// function to add book to library
void add_book(struct book* books, int* count) {
    printf("\nEnter Book Details:\n");
    printf("Title: ");
    scanf("%s", books[*count].title);
    printf("Author: ");
    scanf("%s", books[*count].author);
    printf("ID: ");
    scanf("%d", &books[*count].id);
    books[*count].is_available = 1;
    *count += 1;
    printf("\nBook Added Successfully!\n");
}

// function to display all books in library
void display_books(struct book* books, int count) {
    printf("\nLibrary Books:\n");
    printf("ID\tTitle\tAuthor\tAvailability\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t", books[i].id, books[i].title, books[i].author);
        if (books[i].is_available == 1) {
            printf("Available\n");
        }
        else {
            printf("Not Available\n");
        }
    }
}

// function to borrow book
void borrow_book(struct book* books, int count) {
    int id;
    printf("\nEnter Book ID to Borrow: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].is_available == 1) {
                books[i].is_available = 0;
                printf("\nBook Borrowed Successfully!\n");
            }
            else {
                printf("\nBook is Not Available for Borrowing.\n");
            }
            return;
        }
    }
    printf("\nBook ID Not Found.\n");
}

// function to return book
void return_book(struct book* books, int count) {
    int id;
    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].is_available == 0) {
                books[i].is_available = 1;
                printf("\nBook Returned Successfully!\n");
            }
            else {
                printf("\nBook is Already Available.\n");
            }
            return;
        }
    }
    printf("\nBook ID Not Found.\n");
}

int main() {
    struct book books[100];
    int count = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &count);
                break;
            case 2:
                display_books(books, count);
                break;
            case 3:
                borrow_book(books, count);
                break;
            case 4:
                return_book(books, count);
                break;
            case 5:
                exit(0);
            default:
                printf("invalid\n");
        }
    }
    return 0;
}
            
