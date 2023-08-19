# project outline


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
- implement a gui using imgui
