*This activity has been created as part of the 42 curriculum by mal-haze.*

# Libft

## Description

Libft is a custom C library that reimplements standard C library functions along with additional utility functions. This project is the first project in the 42 curriculum and serves as a foundation for future projects.

The library includes:
- **Part 1:** Libc functions (memory, string manipulation, character checks)
- **Part 2:** Additional utility functions (string manipulation, fd output)
- **Bonus:** Linked list functions

## Functions

### Part 1 - Libc Functions
| Function | Description |
|----------|-------------|
| `ft_isalpha` | Check if character is alphabetic |
| `ft_isdigit` | Check if character is a digit |
| `ft_isalnum` | Check if character is alphanumeric |
| `ft_isascii` | Check if character is ASCII |
| `ft_isprint` | Check if character is printable |
| `ft_strlen` | Get string length |
| `ft_memset` | Fill memory with a constant byte |
| `ft_bzero` | Zero a byte string |
| `ft_memcpy` | Copy memory area |
| `ft_memmove` | Copy memory area (handles overlap) |
| `ft_strlcpy` | Copy string with size limit |
| `ft_strlcat` | Concatenate string with size limit |
| `ft_toupper` | Convert to uppercase |
| `ft_tolower` | Convert to lowercase |
| `ft_strchr` | Locate character in string |
| `ft_strrchr` | Locate character from end of string |
| `ft_strncmp` | Compare strings |
| `ft_memchr` | Scan memory for a character |
| `ft_memcmp` | Compare memory areas |
| `ft_strnstr` | Locate substring |
| `ft_atoi` | Convert string to integer |
| `ft_calloc` | Allocate and zero memory |
| `ft_strdup` | Duplicate string |

### Part 2 - Additional Functions
| Function | Description |
|----------|-------------|
| `ft_substr` | Extract substring |
| `ft_strjoin` | Concatenate two strings |
| `ft_strtrim` | Trim characters from string |
| `ft_split` | Split string by delimiter |
| `ft_itoa` | Convert integer to string |
| `ft_strmapi` | Apply function to each character |
| `ft_striteri` | Apply function to each character with index |
| `ft_putchar_fd` | Output character to file descriptor |
| `ft_putstr_fd` | Output string to file descriptor |
| `ft_putendl_fd` | Output string with newline to fd |
| `ft_putnbr_fd` | Output number to file descriptor |

### Bonus - Linked List Functions
| Function | Description |
|----------|-------------|
| `ft_lstnew` | Create new list node |
| `ft_lstadd_front` | Add node at beginning |
| `ft_lstsize` | Count list nodes |
| `ft_lstlast` | Get last node |
| `ft_lstadd_back` | Add node at end |
| `ft_lstdelone` | Delete one node |
| `ft_lstclear` | Delete all nodes |
| `ft_lstiter` | Apply function to each node |
| `ft_lstmap` | Create new list by applying function |

## Instructions

### Compilation

```bash
# Compile the library
make

# Clean object files
make clean

# Remove all generated files
make fclean

# Recompile from scratch
make re
```

### Usage

Include the header in your C file:
```c
#include "libft.h"
```

Compile your program with the library:
```bash
cc your_program.c -L. -lft -o your_program
```

## Resources

- [C Library Reference](https://en.cppreference.com/w/c)
- [42 Docs](https://harm-smits.github.io/42docs/)
- [Linked List Tutorial](https://www.geeksforgeeks.org/data-structures/linked-list/)

### AI Usage
AI (GitHub Copilot) was used for:
- Code review and suggestions
- Explanations of function behavior
- Refactoring assistance to meet Norminette requirements
