void thirdMenu(int f){//function that receives the flight position f
    char choice, last[30], first[30];
    int i, j, n, num, temp, order[128];

    do {//loop that says the menu
        
        printf("\nThird Level Menu (Flight %d)\n", flights[f]);
        printf("a. show number of empty seats\n");
        printf("b. Show list of empty seats\n");
        printf("c. Show alphabetical list of seats\n");
        printf("d. assign a customer to a seat\n");
        printf("e. Delete a seat assinment\n");
        printf("f. Return to Main menu\n");
        printf("Choice: ");// user picks one
        scanf(" %c", &choice);

        if (choice == 'a') {//counts the empty seats
            n = 0;
            for (i = 0; i < 128; i++) //increment through every seat
                if (seats[f][i].assigned == 0) n++;
            printf("Empty seats: %d\n", n);
        }

        else if (choice == 'b') { //lists empty seats
            for (i = 0; i < 128; i++)
                if (seats[f][i].assigned == 0) printf("%d ",seats[f][i].id);
            printf("\n");
        }

        else if (choice == 'c') {
            n = 0;
            for (i = 0; i < 128; i++)
                if (seats[f][i].assigned) order[n++] = i;

            //bubble sort
            for (i = 0; i < n - 1; i++)
                for (j = 0; j < n - 1 - i; j++) //compare each pair of neighbors

                    if (strcmp(seats[f][order[j]].last, seats[f][order[j + 1]].last) > 0) {
                        temp = order[j];
                        order[j] = order[j + 1];
                        order[j + 1] = temp;
                    }

            for (i = 0; i < n; i++)// print sorted passengers
                printf("Seat %d: %s, %s\n", seats[f][order[i]].id,
                       seats[f][order[i]].last, seats[f][order[i]].first);

            if (n == 0) printf("no passengers yet\n");
        }

        else if (choice == 'd') { 
            num = 0;
            printf("Seat number 1-128, 0 to abort: ");
            scanf("%d", &num);
            if (num < 1 || num > 128){
                printf("Aborted.\n");

            } 
            
            else if (seats[f][num - 1].assigned) { 
                printf("seat is already taken.\n");
            } 
            
            else {
                printf("Last name (0 to abort): ");
                scanf("%29s", last);

                if (strcmp(last, "0") == 0) {
                    printf("Aborted.\n");// cancel
                } 
                // strrcmp compares letters not memory addresses like ==
                else {
                    printf("First name/0 to abort: ");
                    scanf("%29s", first);
                    if (strcmp(first, "0") == 0) {
                        printf("Aborted.\n");
                    } 
                    else {
                        strcpy(seats[f][num - 1].last, last);// copy the last name into the seat
                        strcpy(seats[f][num - 1].first, first);
                        seats[f][num - 1].assigned = 1;//seat taken
                        printf("Seat %d assigned.\n", num);
                    }
                }
            }
        }
        else if (choice == 'e') {
            num = 0;
            printf("Seat number to delete (1-128, 0 to abort): ");
            scanf("%d", &num);
            if (num < 1 || num > 128) {
                printf("Aborted.\n");
            } 
            else if (seats[f][num - 1].assigned == 0) {
                printf("Seat is already empty.\n");
            } 
            else {
                seats[f][num - 1].assigned = 0;// mark empty
                strcpy(seats[f][num - 1].last, "");
                strcpy(seats[f][num - 1].first, "");//erase names
                printf("Seat %d is now empty.\n", num);
            }
        }
        else if (choice != 'f') {
            printf("Invalid choice.\n");
        }

    } while (choice != 'f');
}
