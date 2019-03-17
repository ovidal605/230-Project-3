#include "dictionary.h"

//Returns a pointer to a Dictionary struct
Dictionary *dict_create(char *w, int c, Dictionary *n)
{
    //Allocates memory for the word and copies the word
    char *wordCopy = malloc((strlen(w) + 1) * sizeof(char));
    strcpy(wordCopy, w);

    //Creates and allocates memory for a Dictionary struct
    Dictionary *newDict = (Dictionary *)malloc(sizeof(Dictionary));

    //Sets the word, count, and next 
    setWord(newDict, wordCopy);
    setCount(newDict, c);
    set_next(newDict, n);

    return newDict;
}

//Sets the word of a dictionary
void setWord(Dictionary *dict, char *word){
    dict->word = word;
}

//Sets the count of the word
void setCount(Dictionary *dict, int count){
    dict->count = count;
}

//Increases the count of the word
void word_increase(Dictionary *currWord)
{
    ++(currWord->count);
}

//Gets the word in the dictionary
char *get_word(Dictionary *dict)
{
    return dict->word;
}

//Gets the count of the word
int get_int(Dictionary *dict)
{
    return dict->count;
}

//Gets the next word in the dictionary
Dictionary *get_next(Dictionary *dict)
{
    return dict->next;
}

//Sets the next word in the dictionary
void set_next(Dictionary *dict, Dictionary *next)
{
    dict->next = next;
}

//Adds a word to the dictionary
void add_word(char *word, Dictionary *dict)
{
    //If the Dictionary is empty
    if (get_next(dict) == NULL)
    {
        //Created a new Dictionary
        Dictionary *newWord = dict_create(word, 1, NULL);
        //Link the first dictionary to the new one
        set_next(dict, newWord);
    }
    else
    {
        //Get the first word in the Dictionary and the previous word
        Dictionary *currWord = get_next(dict);
        Dictionary *lastWord = dict;

        //While the end is not reached
        while (currWord != NULL)
        {
            //If the word is in the dictionary increase the count and return 
            if (strcmp(get_word(currWord), word) == 0)
            {
                word_increase(currWord);
                return;
            }
            //The last word becomes the current word
            lastWord = currWord;
            //The current word becomes the next word in the Dictionary
            currWord = get_next(currWord);
        }

        //If the word is not in the Dictionary create a new word and add it to the end
        Dictionary *newWord = dict_create(word, 1, NULL);
        set_next(lastWord, newWord);
    }
}

//Prints the Dictionary
void print_dict(Dictionary *dict)
{   
    //Get the first word in the Dictionary
    dict = get_next(dict);

    //Sets a counter to print words in segments
    int counter = 0;

    //While the end of the Dictionary is not reached
    while (dict != NULL)
    {   
        //Print the word and its count
        printKeyValuePair(dict->word, get_int(dict), 26);
        
        //Get the next word in the Dictionary
        dict = get_next(dict);

        //If 15 words are displayed ENTER must be pressed to print the next 15 words
        if (counter == 15)
        {
            printStr("Press ENTER to view the next 15 words.\n\n");
            getchar();
            counter = 0;
        }
        ++counter;
    }
}

//Frees the Dictionary
void free_dict(Dictionary *dict)
{
    //If the dictionary is not empty free the link, word, and Dictionary
    if (dict != NULL)
    {
        free_dict(get_next(dict));
        free(dict->word);
        free(dict);
    }
}