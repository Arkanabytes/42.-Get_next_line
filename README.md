<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for build-url, contributors-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links

[![Build Status][build-shield]][build-url]
[![Contributors][contributors-shield]][contributors-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
-->

[linkedin-url]: https://linkedin.com/in/consuelo-alejandra-pinto-toro/

# Get_Next_Line

### Objectives
This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables.
You will also gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.
Your respect of the Norm will improve the rigor of your programming. We also suspect that your approach to coding will change when you will discover that the initial state of a variable in a function can vary depending on the call of that very function.

### Compilation:

`make all` | First time compilation.

`make fclean` | Delete files generated from compilation.

`make re` | Delete files generated from compilation and recompile.

### Execution:

`./test_gnl` | Read from Standard Input.

`./test_gnl "file_path"` | Read from a single file.

`./test_gnl "file_path_1" "file_path_2" "file_path_3"` | Read from multiple files.

`./test_gnl "file_path_1" "file_path_2" "file_path_3" mix n` | Read n lines from multiple files.

### Returning values:

`1` | Line read.

`0` | No read, end of file.

`-1` | Error.
