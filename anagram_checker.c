#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int is_anagram(char *string1, char *string2);

int main() {
    // Declare variables
    char string1[25];
    char string2[25];
    int result;
    
    // Get user input
    printf("Enter two strings and I'll tell you if they're anagrams.\n");
    printf("Enter the first string: ");
    fgets(string1, 25, stdin);
    string1[strcspn(string1, "\n")] = 0; // remove trailing newline from input
    printf("Enter the second string: ");
    fgets(string2, 25, stdin); 
    string2[strcspn(string2, "\n")] = 0; // remove trailing newline from input

    // Call the is_anagram function
    result = is_anagram(string1, string2);

    // Output decision tree
    if (result == 0){
        printf("%s and %s are anagrams.\n", string1, string2);
    }
    else if (result == 1){
        printf("%s and %s are not anagrams.\n", string1, string2);
    }
    else {
        printf("Something has gone terribly awry. Try again.\n");
        return (1);
    }
    return (0);
}

/* This function tests whether the strings are anagrams */
int is_anagram(char *string1, char *string2){
    // get lengths of strings
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    // 1. Test for equal length. If they are unequal the strings 
    // cannot be anagrams.
    if (len1 != len2){
        return (1);
    }
    
    // Get the count of each character in both strings
    
    // Create two arrays to hold the count of each ccharacter 
    int count1[256] = {0};
    int count2[256] = {0};

    // Iterate over both strings and increment the count of each character
    int i;
    for (i = 0; string1[i] != '\0'; ++i){
        ++count1[string1[i]];
        // printf("%c:%d\n",string1[i], count1[string1[i]]); // FOR TESTING
    }
    for (i = 0; string2[i] != '\0'; ++i){
        ++count2[string2[i]];
        // printf("%c:%d\n",string2[i], count2[string2[i]]); // FOR TESTING
    }

    // Compare the count of each character
    for (i = 0; i < 256; ++i){
        if (count1[i] != count2[i]){
            return (1);
        }
    }

    return 0;
}

