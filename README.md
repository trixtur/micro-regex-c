[![trixtur](https://circleci.com/gh/trixtur/micro-regex-c.svg?style=svg)](https://circleci.com/gh/trixtur/micro-regex-c)


# micro-regex-c
## An extremely basic regex implementation in C
### Description
The drive to build this micro [regex](https://en.wikipedia.org/wiki/Regular_expression) library in C came from a need to have a small portable Regular Expression library for a text based game.

The basic design was based upon Rob Pike's regex-code for the book *"Beautiful Code"* which I read [here](http://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html).

### API

 - `c`    matches any literal character c
 - `\d`   matches any decimal character
 - `\w`   matches any word character
 - `.`    matches any single character
 - `^`    matches the beginning of the input string
 - `$`    matches the end of the input string
 - `*`    matches zero or more occurrences of the previous character
 

### Usage
A simple driver has been written as an example for using the regex library and parsing strings.

### Attributions
Thanks to the authors of [tiny-regex-c](https://github.com/kokke/tiny-regex-c)

### License
All material in this repository is in the public domain.
