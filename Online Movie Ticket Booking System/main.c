#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

///////////////////////////////////////////////////////////////////////////

void running_Movies()
{
    FILE *running_movies;
    getchar();
    running_movies = fopen("Running_Movies.txt", "w");
    if (running_movies == NULL)
    {
        printf("Error opening file for writing!\n");
        return;
    }

    printf("\nYou Are rewriting movies: \n\n");

    char name[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter no %d movie name: ", i + 1);
        fgets(name, sizeof(name), stdin);
        fprintf(running_movies, "%d %s", i + 1, name);
    }

    fclose(running_movies);
    system("cls || clear");
}

//////////////////////////////////////////////////////////////////////////////

void upcoming_Movies()
{
    FILE *upcoming_Movies;
    printf("How many movie is coming: \n");
    int x;
    scanf("%d", &x);
    getchar();
    upcoming_Movies = fopen("Upcoming_Movies.txt", "w");
    if (upcoming_Movies == NULL)
    {
        printf("Error opening file for writing!\n");
        return;
    }

    printf("\nYou Are rewriting upcoming movies: \n\n");

    char name[100];
    for (int i = 0; i < x; i++)
    {
        printf("Enter no %d movie name: ", i + 1);
        fgets(name, sizeof(name), stdin);
        fprintf(upcoming_Movies, "%d %s", i + 1, name);
    }

    fclose(upcoming_Movies);
    system("cls || clear");
}

////////////////////////////////////////////////////////////////////////////////

void movie_details()
{
    for (int i = 1; i <= n; i++)
    {
        FILE *movie_details;
        char filename[100];
        sprintf(filename, "Movie_details_%d.txt", i);
        movie_details = fopen(filename, "w");
        if (movie_details == NULL)
        {
            printf("Error opening file %s for writing!\n", filename);
            continue;
        }

        char movie_name[100], cast_name[200], director[100], publish_date[100], IMDb_rating[100];

        printf("\nEnter details for movie %d:\n", i);
        printf("Enter movie name: ");
        fgets(movie_name, sizeof(movie_name), stdin);
        fprintf(movie_details, "\nMovie           : %s", movie_name);

        printf("Enter cast names using comma (,): ");
        fgets(cast_name, sizeof(cast_name), stdin);
        fprintf(movie_details, "Cast's          : %s", cast_name);

        printf("Enter movie director's name: ");
        fgets(director, sizeof(director), stdin);
        fprintf(movie_details, "Movie Director  : %s", director);

        printf("Enter movie publish date (e.g. 11 Jan 2011): ");
        fgets(publish_date, sizeof(publish_date), stdin);
        fprintf(movie_details, "Release Date    : %s", publish_date);

        printf("Enter IMDb rating for this movie: ");
        fgets(IMDb_rating, sizeof(IMDb_rating), stdin);
        fprintf(movie_details, "IMDb Rating     : %s", IMDb_rating);

        fclose(movie_details);
        system("cls || clear");
    }
}

//////////////////////////////////////////////////////////////////////////////////

void show_running_movies()
{
    FILE *Running_Movies;
    Running_Movies = fopen("Running_Movies.txt", "r");
    if (Running_Movies == NULL)
    {
        printf("Error opening file!\a\n");
        return;
    }

    printf("\nOur running movies are: \n");
    char line[100];
    while (fgets(line, sizeof(line), Running_Movies))
    {
        printf("%s", line);
    }

    fclose(Running_Movies);
}

/////////////////////////////////////////////////////////////////////////////////

int select_movie()
{
    printf("\nWhich movie you wanna watch?");
    printf("\nSelect a movie: ");
    int select;
    scanf("%d", &select);

    system("cls || clear");


    FILE *Movie_details;
    char filename[100];
    sprintf(filename, "Movie_details_%d.txt", select);
    Movie_details = fopen(filename, "r");
    if (Movie_details == NULL)
    {
        printf("Error opening file! or Your input is wrong!!\n\a");
        return 0;
    }
    char line[100];
    while (fgets(line, sizeof(line), Movie_details))
    {
        printf("%s", line);
    }
    fclose(Movie_details);
    return 1;
}

///////////////////////////////////////////////////////////////////////////////

void payment()
{
    //system("cls || clear");
    FILE *make_payment;
    make_payment = fopen("Payment_list.txt", "a");
    printf("\nTo confirm your seat/s.");
    printf("\nSend money to this number: 016************\n");
    printf("Bkash, Nagad or Rocket only.\n");
    printf("Enter your transmission(Trx) ID: ");
    char ID[100];
    scanf("%s", ID);
    fprintf(make_payment, "%s\n", ID);
    getchar();

    if (make_payment == NULL)
    {
        printf("Error opening file for writing!\n");
        return;
    }

    system("cls || clear");
    printf("\n\n|**********************************************|\n");
    printf("|                                              |\n");
    printf("|       Payment successfull!! congrats...      |\n");
    printf("|                                              |\n");
    printf("!**********************************************!\n\n");
    //system("cls || clear");
}

//////////////////////////////////////////////////////////////////////////////////

void seat_type()
{
    printf("\nOur seat type is: \n");
    printf("1. Standard/Regular Seats.(300tk/seat)\n");
    printf("2. Premium/Comfort Seats.(500tk/seat)\n");
    printf("3. VIP/Luxury Seats.(800tk/seat)\n");
    printf("\nYou can choose any one type seat and buy maximum 5 seats at once!\n");
}

///////////////////////////////////////////////////////////////////////////////////

int choice_seat()
{
    int t_price=0;
    printf("Which type of seat do you want?\n");
    printf("Press 1, 2 or 3.\n");
    int seat;
    scanf("%d", &seat);
    printf("How many seat/s you need: \n");
    int seats;
    scanf("%d", &seats);
    if(seats <= 5 && seats > 0 && seat == 1)
    {
        t_price = seats * 300;
    }

    else if(seats <= 5 && seats > 0 && seat == 2)
    {
        t_price = seats * 500;
    }

    else if(seats <= 5 && seats > 0 && seat == 3)
    {
        t_price = seats * 800;
    }

    system("cls || clear");
    return t_price;
}

//////////////////////////////////////////////////////////////////////

int cancel_seat()
{
    printf("\n\nDo you want to cancel your ticket/s?\n");
    printf("Press 0 to cancel.\n");
    printf("Press 1 to continue.\n");
    int del;
    scanf("%d", &del);
    return del;
}

/////////////////////////////////////////////////////////////////////////////////

void show_upcoming_movies()
{
    FILE *upcoming_Movies;
    upcoming_Movies = fopen("Upcoming_Movies.txt", "r");
    if (upcoming_Movies == NULL)
    {
        printf("Error opening file!\a\n");
        return;
    }
    printf("\nOur Upcoming movies are: \n");
    char line[100];
    while (fgets(line, sizeof(line), upcoming_Movies))
    {
        printf("%s", line);
    }
    fclose(upcoming_Movies);
}

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    printf("Are you user or admin ?\n");
    printf("Press ->1<- for user & ->0<- for admin.\n");
    int press;
    scanf("%d", &press);
    system("cls || clear");

    //////////////////////////////////////////////////////////////////////////

    if (press == 0)
    {
        printf("Enter the passkey: \n");
        int passkey;
        scanf("%d", &passkey);
        if(passkey == 5665)
        {
            printf("How many movies: ");
            scanf("%d", &n);
            system("cls || clear");
            running_Movies();
            movie_details();
            upcoming_Movies();
        }
        else
            printf("Wrong Passkey Bro!!\n Try again\n");
    }

    ///////////////////////////////////////////////////////////////////////////

    else if (press == 1)
    {
        show_running_movies();
        int select = select_movie();
        if (select == 1)
        {
            seat_type();
            //////////////////////////////////////
            int total_price  = choice_seat();
            if(total_price != 0)
            {
                printf("\nTotal bill: %dtk", total_price);
                printf("\nDo you have any coupon?\n");
                int coupon;
                printf("If yes press 1.\n");
                printf("If no press 0.\n");
                scanf("%d", &coupon);
                if(coupon == 0)
                {
                    int cancel = cancel_seat();
                    if(cancel == 0)
                    {
                        printf("Your ticket/s cancel successfully.\n");
                    }
                    else if(cancel == 1)
                    {
                        payment();
                    }
                    else
                        printf("Wrong input vhai !!.\a\n");
                }
                else if(coupon == 1)
                {
                    printf("\nEnter the coupon.\n");
                    char coupon[50];
                    scanf("%s", &coupon);
                    getchar();
                    if (strcmp(coupon, "biye_krmo") == 0)
                    {
                        total_price = total_price * 0.6;
                        printf("Coupon applied successfully.\n");
                        printf("\nNow Total bill: %dtk", total_price);
                        int cancel = cancel_seat();
                        if(cancel == 0)
                        {
                            printf("Your ticket/s cancel successfully.\n");
                        }
                        else if(cancel == 1)
                        {
                            payment();
                        }
                        else
                            printf("Wrong input vhai !!.\a\n");
                    }
                    else
                    {
                        printf("\nWrong input vhai!!\n");
                    }
                }
                else
                    printf("Wrong input!\n");
            }
            else
                printf("Wrong input or you cannot buy more than 5 seats at once!\a\n");
            ///////////////////////////////////////
            show_upcoming_movies();
            printf("\n\n|**********************************************|\n");
            printf("|                                              |\n");
            printf("|       Thanks for choosing our system!        |\n");
            printf("|                                              |\n");
            printf("!**********************************************!\n\n");
        }
    }
    else
        printf("Wrong input!\a\n");

    return 0;
}

