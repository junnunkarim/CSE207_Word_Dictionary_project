# project outline

# project flow
- initialize a bst
    - if previous files exists
        - load from the files 
- show options to user
    - add word
    - search word
    - delete word
    - update word
    - find synonyms
- if "add word"
    - take input(word, definition and similar words) from user and insert it in the bst
        - when taking input for similar words check if the word is in the bst
            - if the word is in the bst, take the node's address and append it to the similar words list
            - if it is not, then create a node with a word object that contains only word name and insert it to the bst, also append it to the similar words list
- if "search word"
    - take input of the word to search for and search it through the bst
- if "delete word"
    - take input and remove the input word node from bst
- if "find synonyms"
    - take input and if the input is in the bst, then print the similar words list of that word with definition
- finally save the bst in two files, one for the word names and one for the definition and similar words list

## Main features
- implement bst and linked-list as libraries
- create a word class which stores:
    - string word name
    - string definition
    - a linked-list of similar meaning word pointers
- implement a function:
    - which creates a word object with the following parameters and adds the object to the bst
        - name
        - definition
        - ask if the user wants to add similar words
            - if yes, go to the function that adds similar words
    - which add "similar words" to a linked-list of words
    - for saving words in a file which:
        - saves the word names in a file and word definition and similer meaning words in another file

## optional features
- implement a database to store words instead of files
- implement a tui/gui using imgui
