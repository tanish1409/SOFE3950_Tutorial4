/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens){
    *tokens = strtok(input, " ");
    tokens++;
    while ((*tokens = strtok(NULL, " ")) != NULL)
    {
        tokens++;
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players)
{
    for (int i = 0; i < num_players; i++)
    {
        for (int j = i + 1; j < num_players; j++)
        {
            if (players[j].score > players[i].score)
            {
                // Swap players
                player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
    // Display results
    printf("Game Results:\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("%d. %s - Score: %d\n", i + 1, players[i].name, players[i].score);
    }
}

// int main(int argc, char *argv[])
// {
//     // An array of 4 players, may need to be a pointer if you want it set dynamically
//     player players[NUM_PLAYERS];
    
//     // Input buffer and and commands
//     char buffer[BUFFER_LEN] = { 0 };
//     char *tokens[BUFFER_LEN / 2];   

//     printf("Welcome to Jeopardy!\n");
//     // Display the game introduction and initialize the questions
//     initialize_game();

//     // Prompt for players names
//     for (int i = 0; i < NUM_PLAYERS; i++) {
//         printf("Enter name for player %d: ", i + 1);
//         fgets(buffer, BUFFER_LEN, stdin);
//         sscanf(buffer, "%s", players[i].name);
//         players[i].score = 0;
//     }
    
//     // initialize each of the players in the array

//     // Perform an infinite loop getting command input from users until game ends
//     while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
//     {
//         // Call functions from the questions and players source files

//         // Execute the game until all questions are answered

//         // Display the final results and exit
//     }
//     return EXIT_SUCCESS;
// }

int main(int argc, char *argv[])
{
    // An array of 4 players
    player players[NUM_PLAYERS];

    // Input buffer and and commands
    char buffer[BUFFER_LEN] = {0};
    char *tokens[BUFFER_LEN / 2];

    // Display the game introduction and initialize the questions
    printf("Welcome to Jeopardy!\n");
    initialize_game();

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Enter name for player %d: ", i + 1);
        fgets(buffer, BUFFER_LEN, stdin);
        sscanf(buffer, "%s", players[i].name);
        players[i].score = 0;
    }

    // Perform an infinite loop getting command input from users until game ends
    while (true)
    {
        // Display the list of categories to the player
        display_categories();

        // Get the player's selection
        printf("Enter the name of the category and the dollar value of the question (e.g. 'programming 100'): ");
        fgets(buffer, BUFFER_LEN, stdin);
        sscanf(buffer, "%s", buffer);
        char category[MAX_LEN];
        int value;
        sscanf(buffer, "%s %d", category, &value);

        // Display the question
        display_question(category, value);

        // Get the player's answer
        printf("Enter your answer: ");
        fgets(buffer, BUFFER_LEN, stdin);
        strtok(buffer, "\n"); // Remove newline character

        // Process the answer
        if (valid_answer(category, value, buffer))
        {
            printf("Correct!\n");
            update_score(players, NUM_PLAYERS, players[0].name, value); // Update the score for the first player for now
        }
        else
        {
            printf("Incorrect!\n");
        }

        // Check if all questions have been answered
        bool all_answered = true;
        for (int i = 0; i < NUM_QUESTIONS; i++)
        {
            if (!questions[i].answered)
            {
                all_answered = false;
                break;
            }
        }

        if (all_answered)
        {
            break;
        }
    }

    // Display final results
    show_results(players, NUM_PLAYERS);

    return EXIT_SUCCESS;
}
