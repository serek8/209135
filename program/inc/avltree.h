/*
 * avltree.h
 *
 *  Created on: May 20, 2015
 *      Author: serek8
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <iostream>
#include <iomanip>

using namespace std;

// definicja typu danych reprezentującego węzeł drzewa AVL
//--------------------------------------------------------

struct AVLNode
{
	// Gałąź rodzica, lewa podgaląć, prawa podgałąź
  AVLNode * p, * left, * right;

  //klucz
  int key, bf;
};

// Definicja klasy obsługującej drzewo AVL
//----------------------------------------

class AVL
{
  public:

    AVLNode * root;  // korzeń drzewa
    int count;       // liczba węzłów

    AVL();
    ~AVL();
    AVLNode * rotationRR(AVLNode * A);
    AVLNode * rotationLL(AVLNode * A);
    AVLNode * rotationRL(AVLNode * A);
    AVLNode * rotationLR(AVLNode * A);
    bool      insert(AVLNode * n);
    AVLNode * search(int key);
    AVLNode * maxNode(AVLNode * x);
    AVLNode * minNode(AVLNode * x);
    AVLNode * pred(AVLNode * x);
    AVLNode * remove(AVLNode * x);
    void      walk(AVLNode * x);
    void      coutAVLcount();
};

// **********************************************
// *** Definicje funkcji składowych klasy AVL ***
// **********************************************

// Konstruktor klasy AVL
//----------------------

AVL::AVL()
{
  root = NULL;
  count = 0;
}

// Destruktor klasy AVL
//---------------------

AVL::~AVL()
{
  while(root) delete(remove(root));
}

// Rotacja RR
//-----------

AVLNode * AVL::rotationRR(AVLNode * A)
{
  AVLNode * B = A->right, * P = A->p;

  A->right = B->left;
  if(A->right) A->right->p = A;
  B->left = A;
  B->p = P;
  A->p = B;
  if(P)
  {
    if(P->left == A) P->left = B; else P->right = B;
  }
  else root = B;

  if(B->bf == -1)
  {
    A->bf = B->bf = 0;
  }
  else
  {
    A->bf = -1; B->bf = 1;
  }
  return B;
}

// Rotacja LL
//-----------

AVLNode * AVL::rotationLL(AVLNode * A)
{
  AVLNode * B = A->left, * P = A->p;

  A->left = B->right;
  if(A->left) A->left->p = A;
  B->right = A;
  B->p = P;
  A->p = B;
  if(P)
  {
    if(P->left == A) P->left = B; else P->right = B;
  }
  else root = B;

  if(B->bf == 1)
  {
    A->bf = B->bf = 0;
  }
  else
  {
    A->bf = 1; B->bf = -1;
  }

  return B;
}

// Rotacja RL
//-----------

AVLNode * AVL::rotationRL(AVLNode * A)
{
  AVLNode * B = A->right, * C = B->left, * P = A->p;

  B->left = C->right;
  if(B->left) B->left->p = B;
  A->right = C->left;
  if(A->right) A->right->p = A;
  C->left = A;
  C->right = B;
  A->p = B->p = C;
  C->p = P;
  if(P)
  {
    if(P->left == A) P->left = C; else P->right = C;
  }
  else root = C;

  A->bf = (C->bf == -1) ?  1 : 0;
  B->bf = (C->bf ==  1) ? -1 : 0;
  C->bf = 0;

  return C;
}

// Rotacja LR
//-----------

AVLNode * AVL::rotationLR(AVLNode * A)
{
  AVLNode * B = A->left, * C = B->right, * P = A->p;

  B->right = C->left;
  if(B->right) B->right->p = B;
  A->left = C->right;
  if(A->left) A->left->p = A;
  C->right = A;
  C->left = B;
  A->p = B->p = C;
  C->p = P;
  if(P)
  {
    if(P->left == A) P->left = C; else P->right = C;
  }
  else root = C;

  A->bf = (C->bf ==  1) ? -1 : 0;
  B->bf = (C->bf == -1) ?  1 : 0;
  C->bf = 0;

  return C;
}

// Wstawia element do struktury AVL
//---------------------------------

bool AVL::insert(AVLNode * n)
{
  AVLNode * x = root, * y, * z;

  y = n->left = n->right = NULL;
  n->bf = 0;

  while(x)
  {
    if(x->key == n->key)
    {
      delete n;
      return false;
    }
    y = x;
    x = (n->key < x->key) ? x->left : x->right;
  }

  count++;

  if(!(n->p = y))
  {
    root = n;
    return true;
  }
  if(n->key < y->key) y->left = n; else y->right = n;
  if(y->bf)
  {
    y->bf = 0;
    return true;
  }
  y->bf = (y->left == n) ? 1 : -1;
  z = y->p;
  while(z)
  {
    if(z->bf) break;
    z->bf = (z->left == y) ? 1 : -1;
    y = z; z = z->p;
  }

  if(!z) return true;

  if(z->bf == 1)
  {
    if(z->right == y)
    {
      z->bf = 0;
      return true;
    }
    if(y->bf == -1) rotationLR(z); else rotationLL(z);
    return true;
  }
  else
  {
    if(z->left == y)
    {
      z->bf = 0;
      return true;
    }
    if(y->bf == 1) rotationRL(z); else rotationRR(z);
    return true;
  }
}

// Wyszukuje element wg wartości klucza
//-------------------------------------

AVLNode * AVL::search(int key)
{
  AVLNode * x = root;

  while((x) && (x->key != key))
    x = (key < x->key) ? x->left : x->right;

  return x;
}

// Zwraca węzeł z maksymalnym kluczem
//-----------------------------------

AVLNode * AVL::minNode(AVLNode * x)
{
  while(x->left) x = x->left;
  return x;
}

// Zwraca węzeł z minimalnym kluczem
//----------------------------------

AVLNode * AVL::maxNode(AVLNode * x)
{
  while(x->right) x = x->right;
  return x;
}

// Zwraca węzeł poprzednika
//-------------------------

AVLNode * AVL::pred(AVLNode * x)
{
  if(x->left) return maxNode(x->left);

  AVLNode * y;

  do
  {
    y = x;
    x = x->p;
  } while(x && (x->right != y));

  return x;
}

// Usuwa element x ze struktury AVL. Zwraca usunięty węzeł
//--------------------------------------------------------

AVLNode * AVL::remove(AVLNode * x)
{
  AVLNode * t, * y, * z;
  bool nest;

  if((x->left) && (x->right))
  {
    y = remove(pred(x));
    count++;
    nest = false;
  }
  else
  {
    if(x->left)
    {
      y = x->left; x->left = NULL;
    }
    else
    {
      y = x->right; x->right = NULL;
    }
    x->bf = 0;
    nest = true;
  }

  if(y)
  {
    y->p = x->p;
    if(y->left  = x->left)  y->left->p  = y;
    if(y->right = x->right) y->right->p = y;
    y->bf = x->bf;
  }

  if(x->p)
  {
    if(x->p->left == x) x->p->left = y; else x->p->right = y;
  }
  else root = y;

  if(nest)
  {
    z = y;
    y = x->p;
    while(y)
    {
      if(!(y->bf))
      {

// Przypadek nr 1

        y->bf = (y->left == z) ? -1 : 1;
        break;
      }
      else
      {
        if(((y->bf ==  1) && (y->left  == z)) || ((y->bf == -1) && (y->right == z)))
        {

// Przypadek nr 2

          y->bf = 0;
          z = y; y = y->p;
        }
        else
        {
          t = (y->left == z) ? y->right : y->left;
          if(!(t->bf))
          {

// Przypadek 3A

            if(y->bf == 1) rotationLL(y); else rotationRR(y);
            break;
          }
          else if(y->bf == t->bf)
          {

// Przypadek 3B

            if(y->bf == 1) rotationLL(y); else rotationRR(y);
            z = t; y = t->p;
          }
          else
          {

// Przypadek 3C

            if(y->bf == 1) rotationLR(y); else rotationRL(y);
            z = y->p; y = z->p;
          }
        }
      }
    }
  }
  count--;
  return x;
}

// Przechodzi przez drzewo wypisując zawartość węzłów
//---------------------------------------------------

void AVL::walk(AVLNode * x)
{
  cout << x->key << " : bf = " << setw(2) << x->bf << " : Left-> ";
  if(x->left) cout << setw(3) << x->left->key;
  else        cout << "NIL";
  cout << ", Right-> ";
  if(x->right) cout << setw(3) << x->right->key;
  else         cout << "NIL";
  cout << " : p -> ";
  if(x->p) cout << setw(3) << x->p->key;
  else     cout << "NIL";
  cout << endl;
  if(x->left)  walk(x->left);
  if(x->right) walk(x->right);
}


// Wypisuje do cout liczbę węzłów drzewa AVL
//------------------------------------------

void AVL::coutAVLcount()
{
  cout << "\nLiczba wezlow drzewa AVL : " << count << endl << endl;
}




#endif /* AVLTREE_H_ */
