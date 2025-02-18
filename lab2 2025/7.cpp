#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) 
{
    cout << argv[argc-1] << endl
    << argc[argv-1] << endl;

    return EXIT_SUCCESS;
}
/*

Оскільки argv — це покажчик на перший елемент масиву 
аргументів, argv-1 вказує на область перед argv[0]. 

Але argc[argv-1] трактує argc як покажчик, а не число, 
і через pointer arithmetic це еквівалентно argv[argc-1].


argc[argv-1] використовує pointer arithmetic, 
і хоча виглядає нелогічно, в даному випадку воно працює 
еквівалентно argv[argc-1].

Код може викликати невизначену поведінку, якщо argv-1 
вказуватиме на недійсну область пам'яті, але компілятор 
не завжди це перевіряє.*/