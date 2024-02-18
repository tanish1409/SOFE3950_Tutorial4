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
#include "questions.h"


question questions[NUM_QUESTIONS] = {
    {"programming", "Question 1", "Answer 1", 100, false},
    {"programming", "Question 2", "Answer 2", 200, false},
    {"programming", "Question 3", "Answer 3", 300, false},
    {"algorithms", "Question 1", "Answer 1", 100, false},
    {"algorithms", "Question 2", "Answer 2", 200, false},
    {"algorithms", "Question 3", "Answer 3", 300, false},
    {"databases", "Question 1", "Answer 1", 100, false},
    {"databases", "Question 2", "Answer 2", 200, false},
    {"databases", "Question 3", "Answer 3", 300, false},
    // Add more questions as needed
};

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
     for (int i = 0; i < NUM_QUESTIONS; i++) {
        questions[i].answered = false;
    }
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%s\n", categories[i]);
        for (int j = 0; j < NUM_QUESTIONS / NUM_CATEGORIES; j++) {
            if (!questions[i * (NUM_QUESTIONS / NUM_CATEGORIES) + j].answered) {
                printf("  %d\n", questions[i * (NUM_QUESTIONS / NUM_CATEGORIES) + j].value);
            }
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("%s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                return true;
            }
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}
