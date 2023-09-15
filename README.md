# Datastructures-And-Algorithms
Popular data structures and algorithms implemented in C++.

## Project Structure
1. Root contains all folders named according to either the data structure they implement or the algorithm.
2. In order to test any data structure or algorithm:
   1. ```cd <folder_name> ```
   2. eg: ``` cd ./LinkedLists ```
   3. Run command ```make all```
   4. This will execute the **Makefile** which will compile the CPP files and automatically run the executable after compilation.
   5. If you would like to play around with the code, *main.cpp* can be edited as per your requirements.
   6. All data structure/algorithm implementations are in their respective *.cpp* files inside the **include** folder.
3. By default, this Makefile is using *clang* compiler. In case you have GCC, just replace _CXX_ variable in the Makefile to the one your system has, in this case GCC. 
