#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"
int strcasecmp(const char *s1, const char *s2);

question questions[NUM_QUESTIONS] = {
    {"programming", "Question 1", "A1", 100, false},
    {"programming", "Question 2", "A2", 200, false},
    {"programming", "Question 3", "A3", 300, false},
    {"programming", "Question 4", "A4", 400, false},
    {"algorithms", "Question 1", "A1", 100, false},
    {"algorithms", "Question 2", "A2", 200, false},
    {"algorithms", "Question 3", "A3", 300, false},
    {"algorithms", "Question 4", "A4", 400, false},
    {"databases", "Question 1", "A1", 100, false},
    {"databases", "Question 2", "A2", 200, false},
    {"databases", "Question 3", "A3", 300, false},
    {"databases", "Question 4", "A4", 400, false}
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
    printf("Category: %s, Value: %d\n", category, value);
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value)
        {
            printf("%s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        //printf(questions[i].answer);
        if (strcmp(questions[i].category, category) == 0 &&
            questions[i].value == value &&
            strcasecmp(questions[i].answer, answer) == 0 &&
            !questions[i].answered)
        {
            questions[i].answered = true;
            return true;
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
