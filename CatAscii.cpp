//
// Created by tony on 15/01/2025.
//

#include "CatAscii.h"
#include "RandomNumber.h"

using namespace std;

void printRandomCatAscii() {
    // Store the ASCII art in a vector
    vector<string> catAscii = {
            R"(
      |\      _,,,---,,_
ZZZzz /,`.-'`'    -.  ;-;;,_
     |,4-  ) )-,_. ,\ (  `'-'
    '---''(_/--'  `-'\_)
        )",
            R"(
 _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-
        )",
            R"(
    /\_____/\
   /  o   o  \
  ( ==  ^  == )
   )         (
  (           )
 ( (  )   (  ) )
(__(__)___(__)__ )
        )",
            R"(
    |\__/,|   (`\
  _.|o o  |_   ) )
-(((---(((--------
        )",
            R"(
 ,_     _
 |\\_,-~/
 / _  _ |    ,--.
(  @  @ )   / ,-'
 \  _T_/-._( (
 /         `. \
|         _  \ |
 \ \ ,  /      |
  || |-_\__   /
 ((_/`(____,-'
        )",
            R"(
                        _
                       | \
                       | |
                       | |
  |\                   | |
 /, ~\                / /
X     `-.....-------./ /
 ~-. ~  ~              |
    \             /    |
     \  /_     ___\   /
     | /\ ~~~~~   \ |
     | | \        || |
     | |\ \       || )
    (_/ (_/      ((_/
        )",
            R"(
       _
       \`*-.
        )  _`-.
       .  : `. .
       : _   '  \
       ; *` _.   `*-._
       `-.-'          `-.
         ;       `       `.
         :.       .        \
         . \  .   :   .-'   .
         '  `+.;  ;  '      :
         :  '  |    ;       ;-.
         ; '   : :`-:     _.`* ;
      .*' /  .*' ; .*`- +'  `*'
      `*-*   `*-*  `*-*'
        )",
            R"(
            _,'|             _.-''``-...___..--';)
           /_ \'.      __..-' ,      ,--...--'''
          <\    .`--'''       `     /'
           `-';'               ;   ; ;
     __...--''     ___...--_..'  .;.'
    (,__....----'''       (,..--''
        )"
    };

    // Get a random index using the random number generator
    int randomIndex = getRandomNumber(0, catAscii.size() - 1);

    // Select a random cat ASCII and print it
    cout << catAscii[randomIndex] << "\n";
}
