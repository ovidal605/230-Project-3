#include "dictionary.h"

//Returns a pointer to a Dictionary struct
Dictionary *dictCreate(char *w, int c, Dictionary *n)
{
    //Allocates memory for the word and copies the word
    char *wordCopy = malloc((strlen(w) + 1) * sizeof(char));
    strcpy(wordCopy, w);

    //Creates and allocates memory for a Dictionary struct
    Dictionary *newDict = (Dictionary *)malloc(sizeof(Dictionary));

    //Sets the word, count, and next 
    setWord(newDict, wordCopy);
    setCount(newDict, c);
    setNext(newDict, n);

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
void increaseWord(Dictionary *currWord)
{
    ++(currWord->count);
}

//Gets the word in the dictionary
char *getWord(Dictionary *dict)
{
    return dict->word;
}

//Gets the count of the word
int getCount(Dictionary *dict)
{
    return dict->count;
}

//Gets the next word in the dictionary
Dictionary *getNext(Dictionary *dict)
{
    return dict->next;
}

//Sets the next word in the dictionary
void setNext(Dictionary *dict, Dictionary *next)
{
    dict->next = next;
}

//Adds a word to the dictionary
void addWord(char *word, Dictionary *dict)
{
    //If the Dictionary is empty
    if (getNext(dict) == NULL)
    {
        //Created a new Dictionary
        Dictionary *newWord = dictCreate(word, 1, NULL);
        //Link the first dictionary to the new one
        setNext(dict, newWord);
    }
    else
    {
        //Get the first word in the Dictionary and the previous word
        Dictionary *currWord = getNext(dict);
        Dictionary *lastWord = dict;

        //While the end is not reached
        while (currWord != NULL)
        {
            //If the word is in the dictionary increase the count and return 
            if (strcmp(getWord(currWord), word) == 0)
            {
                increaseWord(currWord);
                return;
            }
            //The last word becomes the current word
            lastWord = currWord;
            //The current word becomes the next word in the Dictionary
            currWord = getNext(currWord);
        }

        //If the word is not in the Dictionary create a new word and add it to the end
        Dictionary *newWord = dictCreate(word, 1, NULL);
        setNext(lastWord, newWord);
    }
}

//Prints the Dictionary
void printDict(Dictionary *dict)
{   
    //Get the first word in the Dictionary
    dict = getNext(dict);

    //While the end of the Dictionary is not reached
    while (dict != NULL)
    {   
        //Print the word and its count
        printKeyValuePair(dict->word, getCount(dict), 26);
        
        //Get the next word in the Dictionary
        dict = getNext(dict);
    }
}

//Frees the Dictionary
void freeDict(Dictionary *dict)
{
    //If the dictionary is not empty free the link, word, and Dictionary
    if (dict != NULL)
    {
        freeDict(getNext(dict));
        free(dict->word);
        free(dict);
    }
}