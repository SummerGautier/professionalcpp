## Professional C++ Development
This project is about sharpening 'working' cpp skills into standardized development using C++20 and above. 
The workbook being used for these local projects is "Programming: Principles and Practice Using C++" by Bjarne Stroustrap who created C++. 
While the book was written on C++17 standard, the projects in this repository subsistute C++20 standard wherever it is known to the repo owner.

### Compilation & Linker
CLang & LLVM toolkit were chosen for this journey due to the following features:
- Library / Modular Design
- Extensive AST to support IDE usage & more helpful diagnostics
- LLVM builds IR that is multi-platform
- Codegen supports up to standard library C++23
- Commercial Use Apache 2.0 software license (since we're learning professional standards)

While most of these features are not terribly important to this project, it was important to choose a toolchain that would support professional development later on--since real projects are the goal. 

## Using This Project
### /Chapter Sub-Directories
Each sub-directory corresponds to a chapter or sub-section of the book. The code contains comments explaining it's purpose / how it operates. 

### Main.cpp
Each exercise starts in Main.cpp and may have other associated files. If you are knowledgeble about C++ at a basic level, then using an IDE you should be able to run the program from Main.cpp / main() as the entrypoint. 

### CLI Running The Program
Since the point is trying to learn professional style and standards of C++ development, the decision was to use the command line instead of an IDE:

```
clang++ -std=c++20 Main.cpp -o program.exe
./program.exe
```
