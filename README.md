# Functions
## Just another useless language

### Purpose
This language began development over the summer holidays, as I had nothing better to do. It was just a fun little project to see how much I knew, expand my knowledge, and challenge myself with something new. I created it to be an example of very basic programming, to demonstrate to my friends what I do in a simple way, and to show off, and say I had my own language. I don't see any real purpose for it, other than just a bit of fun.

### Installation
Read the [INSTALL.md](/docs/INSTALL.md) for instructions on how to install

### Usage
This language is a compiler/transpiler, as it converts the written code to c++, and then uses gcc to compile this down to a binary.  
For every compile, the `-f` flag must be used to specify the file input, and `-o` can be used to specify output, but will default to `./func` if not defined. For example:
```
functions -f main.func -o hello
```

### Known Issues
Currently no known issues, unless they are intentional

### Git usage
There are currently two branches, master and dev. All work is done on dev, and then merged into master when operational.

### Documentation
All the documentation for the language, however small it may be, is stored in [SYNTAX.md](/docs/SYNTAX.md)

### Getting Help
If you have questions, concerns, bug reports, etc, please file an issue in this repository's Issue Tracker.

### Licensing
This project is licensed under the GNU GPL Version 3, for more detail see [LICENSE](/LICENSE)