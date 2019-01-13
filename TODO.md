# TODO list

## Syntax changes

#### out():
* accept no value, and just print a new line      
* detect "" and print a string

#### init() 
* detect type of value
* possibly value is required, or use auto

___

## Refactoring

#### All Paser functions
rewrite so it splits the args into a string vector, splitting at every comma

### Compiler
Improve design so testing is easier

### ArgParser
Rewrite so tests can be run, checking for files and stuff

### Main file
Remove all arg stuff from main. Add a function to ArgParser to do that  
Only stuff left is ArgsParse object init and Compiler init and run  
Makes unit tests easier  

## Project Changes
__Change from Makefile to CMake!!!__  
need help with this as i have no experience