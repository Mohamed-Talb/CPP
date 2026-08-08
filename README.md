# CPP MODULES

This repository contains the subjects and solutions for the 42 C++ Modules from `M00` to `M09`.

The modules introduce object-oriented programming and the main features of C++ step by step. Each module focuses on a specific group of concepts and contains several exercises used to practise them.

## WHY C++98?
The modules use the C++98 standard to teach the foundations of the language without relying on modern shortcuts.
Working with C++98 helps us understand:

1. Classes and object-oriented programming
2. Manual memory and resource management
3. Copy behavior and object lifetime
4. Inheritance and polymorphism
5. Templates and standard containers
6. How higher-level C++ features work internally

Compile exercises with:
```bash
g++ -Wall -Wextra -Werror -std=c++98
```

## REPOSITORY STRUCTURE
```text
CPP-POOL/
├── SUBJECTS/
│   ├── M00/
│   ├── M01/
│   └── ...
│
└── SOLUTIONS/
    ├── M00/
    │   ├── ex00/
    │   ├── ex01/
    │   └── ex02/
    ├── M01/
    └── ...
```

- `SUBJECTS/` contains the module PDFs and their required attachments.
- `SOLUTIONS/` contains one directory for every completed exercise.

## MODULE CONCEPTS
| Module | Main concepts |
|---|---|
| `M00` | C++ introduction, namespaces, streams, classes, member functions, `this`, initialization lists, `const`, visibility, structs, accessors and member pointers |
| `M01` | Memory allocation, `new`, `delete`, pointers, references and file streams |
| `M02` | Ad-hoc polymorphism, function and operator overloading, fixed-point numbers and Orthodox Canonical Form |
| `M03` | Inheritance, constructor chains and class relationships |
| `M04` | Subtype polymorphism, virtual functions, abstract classes and interfaces |
| `M05` | Exceptions, exception classes, nested classes and error handling |
| `M06` | Type conversion, `static_cast`, `dynamic_cast`, `reinterpret_cast` and `const_cast` |
| `M07` | Function templates, class templates, default types and template specialization |
| `M08` | STL containers, iterators, algorithms and templated containers |
| `M09` | Advanced use of STL containers and algorithms for data processing and sorting |

The related 42 learning notions are available on the intranet:

- [C++ Introduction](https://elearning.intra.42.fr/notions/piscine-c-introduction/subnotions)
- [Module 00 - C++ Basics](https://elearning.intra.42.fr/notions/piscine-c-d00-c-basics/subnotions)
- [Module 01 - C++ Basics 2](https://elearning.intra.42.fr/notions/piscine-c-d01-c-basics-2/subnotions)
- [Module 02](https://elearning.intra.42.fr/notions/piscine-c-d02-93e8d707-f883-4f82-928b-cbc45a162079/subnotions)
- [Module 03 - Inheritance](https://elearning.intra.42.fr/notions/piscine-c-d03-inheritance/subnotions)
- [Module 04 - Subtype Polymorphism](https://elearning.intra.42.fr/notions/piscine-c-d04-sub-typing-polymorphism/subnotions)
- [Module 05 - Nested Classes and Exceptions](https://elearning.intra.42.fr/notions/piscine-c-d05-nested-classes-and-exceptions/subnotions)
- [Module 06 - Casts](https://elearning.intra.42.fr/notions/piscine-c-d06-casts/subnotions)
- [Module 07 - Templates](https://elearning.intra.42.fr/notions/piscine-c-d07-templates/subnotions)
- [Module 08 - STL](https://elearning.intra.42.fr/notions/piscine-c-d08-stl/subnotions)

## HOW TO SOLVE AN EXERCISE
1. Open the module subject:
   ```bash
   SUBJECTS/M00/M00.pdf
   ```
2. Read the general rules and the selected exercise carefully.
3. Create or enter its solution directory:

   ```bash
   mkdir -p SOLUTIONS/M00/ex00
   cd SOLUTIONS/M00/ex00
   ```
4. Copy only the attachments required by the subject.
5. Implement the exercise without checking the existing solution first.
6. Build with the required flags and test normal, edge and error cases.
7. Compare the final filenames and output with the subject requirements.

## USING SUBJECT ATTACHMENTS
Some modules provide extra files next to their PDF, for example:
```text
SUBJECTS/M00/Account.hpp
SUBJECTS/M00/tests.cpp
SUBJECTS/M00/19920104_091532.log
SUBJECTS/M07/main.cpp
SUBJECTS/M09/cpp_09.tgz
```
Copy an attachment into an exercise only when the subject asks for it:
```bash
cp SUBJECTS/M00/Account.hpp SOLUTIONS/M00/ex02/
cp SUBJECTS/M00/tests.cpp SOLUTIONS/M00/ex02/
```
Extract an archive in a temporary directory before using its files:
```bash
mkdir -p /tmp/cpp09-attachments
tar -xzf SUBJECTS/M09/cpp_09.tgz -C /tmp/cpp09-attachments
```
Important rules:

1. Read the PDF before using any attachment.
2. Preserve required filenames and function signatures.
3. Do not modify provided files unless the subject allows it.
4. Do not submit unnecessary attachment or test files.
5. Use provided `main.cpp` or test files to verify behavior when requested.

## BUILDING AN EXERCISE
Most exercise directories contain a `Makefile`:
```bash
cd SOLUTIONS/M00/ex00
make
./program_name
```
The Makefile should normally support:
```bash
make
make clean
make fclean
make re
```
For a quick manual compilation:
```bash
g++ -Wall -Wextra -Werror -std=c++98 *.cpp -o test_program
./test_program
```


## IMPORTANT
The solutions in this repository should be used for review after attempting the exercises. Reading a finished solution first removes the main learning value of the modules.

Always follow the PDF stored in `SUBJECTS/` because requirements can differ between subject versions.
