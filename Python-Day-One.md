### Two Execution Mode

* Interpreted Mode
* Interactive Mode

### Entry point

The first statement in the file being executed

### Statement

```java
System.out.println(
			"Hello, world!!!"
			);
```		
```python
Name = "John "\
		"Smith"
Print("something"
		+ " another")
		
```

#### Differences

* '\n' terminated
* '\' to escape
* But it is not needed when in a pair of parentheses

### Note

Blocks in Python are indicated by indentation level composed of either spaces or tabs.
All statements within the block must have the same indentation level.

### Identifier

* May only contain letters, digits, or the underscores, and
* May not begin with a digit.

### Data types
* `int`
* `long`
* `float`
* `complex`
* `bool`: True or False(Capitalized)
* `str`: `'string' or "string"` or `…`
* `list`: `[1, 2, 3, 'a']`
* `tuple`: `1, 2, 3` or `(1, 2, 3, 'a')`
* `dict`: `{123: 'bob', 456: 'sally'}`
* `set`: see the class methods

### Variables

Like that in JavaScript, just use it, without declaration,
but you cannot ref a var that has not been assigned a value.
And no hoisting.

#### Note

No constants(Write them with all capital letters to let the
reader, the human, understand and not to mute the value)

### Operators

%, +, -, *, /, **, //, x=

#### Added

**, //

#### Obsoleted

++, --

### Functions

Args without type and optional return value

### Use modules

* `from math import something`
* `from math import *`
* `import math`

### Note

* Objects instantiated without new key words;
* Method is called by '.' operator on an object;

### Numeric type constructors

* `int()`, `float()`, `long()` convert strings to objects of corresponding  type.
* `complex(x, y)` creates a complex number.

### Standard Input & Prompt

`raw_input([message])` prompts for input with the optional message 
and return a string of the input

### Standard Output

`print` is a __statement__

```python
print a, b, c, d 
==> 'a<space>b<space>c<space>d'
```