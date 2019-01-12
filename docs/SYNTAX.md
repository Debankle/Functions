# Syntax

### File type

To make this language special, `.func` should be used as the file extension

### Require

use `require(package)` to use a custom package. All files must be headed with require(sys)

    require(sys) or require(string)

### Define

use `init(variable)` to define a variable for future use. It must be defined this way, or errors will be thrown.  
Future ideas: init with a default value e.g. `init(a, "hello world")` but not yet defined


### Print

use `out()` to print code e.g
    
    out("Hello World!") or out(99)

### Return

use `done(arg)` to exit a function, default value is 0 e.g.

    done(0) or done(false)

### Future ideas

Everything uses methods. Everything is a function e.g. sum(), mul(). All variables need to be initialized with init() before use.  
No idea how classes will be created yet. Possibly 
    
    Class(name, var1, var2, func1(), func2())