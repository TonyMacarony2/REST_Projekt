--------------------- Rest API Project - Overview ----------------------------------

Small C++ REST-API project that was coded for a software engineering class at BBZ in Schaffhausen.

The user can choose between a zen quote or a cat fact, as well as specify a number of entries up to 5.

The responses will be displayed along with ASCII-art from the ASCII Art Archive.

--------------------- Compilation instructions: ----------------------------------

Compile with Clion / Cmake version 3.24.2.

Dependencies:   vcpkg, curl, cmake

Important:      In "Cmakelists.txt", input the corresponding [USER NAME] or link to the "vcpkg.cmake" file.

                "set(CMAKE_TOOLCHAIN_FILE "C:/Users/[USER NAME]/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")"

--------------------- References: ----------------------------------

ZenQuotes          https://zenquotes.io/
MeowFacts          https://github.com/wh-iterabb-it/meowfacts
ASCII Art Archive  https://www.asciiart.eu/
