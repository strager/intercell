#ifndef DeleteListAndTheirElementsH
#define DeleteListAndTheirElementsH

#include <iostream>  // cout
#include <list>
#include <typeinfo>  // typeid
#include "Debug.h"  // debug_level
using std::list;
using std::cout;
using std::endl;

// ----------------------------------------------------------------------------

template <typename D>  // D=Data  // Speicherfreigabe in umgekehrter Reihenfolge  // Wenn ausgelagert und Definition im Header: [C++ Warnung] TDeleteListAndTheirElements.cpp(3): W8058 Präcompilierter Header: Header unvollständig kann nicht erzeugt werden
void DeleteListAndTheirElements(list<D*>* l, typename list<D*>::iterator i)
  {                                                                              if(debug_level>=5)  cout << "DelLstEl(list<" << typeid(D).name() << "*>* l: " << l << ", list<" << typeid(D).name() << "*>::iterator i)\tsize " << l->size() << endl;
  if (l->size()>0)                                                               // Bei Ausgabe von uninitialisiertem *i mit g++ Datenzugriffsfehler.
    {
    i = l->end();
    do
      {
      --i;                                                                       if(debug_level>=5)  cout << "DelLstEl(l,i)\tdelete " << *i << endl;
      delete *i;
      }
    while (i!=l->begin());
    }
  delete l;

  // alternative way (thx strager)
  // for (i = l->rbegin();i!=l->rend();++i)
  //   delete *i
  // delete l;
  }

#endif
