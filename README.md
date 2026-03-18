*This project has been created as part of the 42 curriculum by adarmoya.*

# get_next_line

## Description

**get_next_line** is a C function that reads and returns a file descriptor’s content one line at a time.

The goal of this project is to implement a function with the following prototype:

```c
char *get_next_line(int fd);
````

Each call to the function returns the next line from the file descriptor, including the newline character (`\n`) if it exists. When the end of file is reached or if an error occurs, the function returns `NULL`.

This project focuses on:

* File descriptor manipulation
* Static variables
* Dynamic memory allocation
* Buffer management
* Memory leak prevention

The bonus part extends the functionality to support multiple file descriptors simultaneously.

---

## Instructions

### Compilation

Compile the project with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You may define a different buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c
```

If testing with a `main.c` file:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

### Usage

Example:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Requirements

* No memory leaks
* Norm-compliant code
* Proper handling of:

  * Invalid file descriptors
  * Empty files
  * Files without a trailing newline
  * Very large files
  * Multiple file descriptors (bonus)

---

### Algorithm Explanation and Justification
Problem Constraints

The function must:

Read from a file descriptor using read()

Return exactly one line per call

Preserve unread data for the next call

Avoid memory leaks

Work with any BUFFER_SIZE

## Resources

### Documentation

* The `read()` manual page

  ```bash
  man 2 read
  ```

* The `malloc()` and `free()` manual pages

  ```bash
  man 3 malloc
  ```

* File descriptor documentation

  ```bash
  man 2 open
  ```

### Articles & References

* The GNU C Library documentation
  [https://www.gnu.org/software/libc/manual/](https://www.gnu.org/software/libc/manual/)

* Understanding static variables in C
  [https://www.learn-c.org/](https://www.learn-c.org/)

* Memory management in C
  [https://cplusplus.com/reference/cstdlib/](https://cplusplus.com/reference/cstdlib/)

### AI Usage

AI tools were used for:

* Reviewing documentation structure for clarity
* Improving wording and formatting of this README file
* Getting general explanations about static variables and memory management concepts

AI was **not** used to generate the project’s core logic or mandatory implementation. All algorithm design, buffer management, and memory handling logic were written and understood independently.

