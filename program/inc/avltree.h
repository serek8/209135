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
#include "avltreeelement.h"

using namespace std;


// Definicja klasy obsługującej drzewo AVL
//----------------------------------------
/*
 * @brief Definiuje obiekt drzewa AVL
 */
template <class ContentType>
class AVLTree
{
  public:

	/// @brief korzeń drzewa
    AVLTreeNode<ContentType> * rootNode;



    AVLTree()
    {
      rootNode = NULL;
    }
    ~AVLTree()
    {
      while(rootNode)
      {
    	  delete(remove(rootNode));
      }
    }

    /*
     * @brief Wsadza klucz do drzewa
     * @param newkey klucz do wsadzenia
     */
    void insert(int &newKey)
        {
    	AVLTreeNode<ContentType>* newNode = new AVLTreeNode<ContentType>(newKey);
        	//AVLTreeNode<ContentType>  *newNode2 = new AVLTreeNode<ContentType>();
          AVLTreeNode<ContentType> * searchingNode = rootNode,	// Wskaznik do przeszukania drzewa i znalezienia tego samego klucza
        		  * parentForNewNode = NULL,// parentForNewNode
        		  * grandpaNode;

          while(searchingNode)
          {
            if(searchingNode->key == newNode->key) // sprawdzam czy taki klucz juz istnieje
            {
              //delete n; // skoro istnieje to po co taki TODO: do zmiany

              //cout	<<"Taki klucz juz istnieje !\n";
              return ;
            }
            parentForNewNode = searchingNode;
            if(newNode->key < searchingNode->key) searchingNode= searchingNode->leftNode; // przechodze w lewo czesc drzewa
            else searchingNode = searchingNode->rightNode;				// przechodze w prawa czesc drzewa
          }


          // jezeli to jest pierwszy element to wpisuje go to root'a drzewa
          if(!(newNode->parentNode = parentForNewNode))
          {
            rootNode = newNode;
            return ;
          }
          // wybieram strone gałęzi na której ma byc element
          if(newNode->key < parentForNewNode->key) parentForNewNode->leftNode = newNode;
          else parentForNewNode->rightNode = newNode;

          //sprawdzam czy potrzebne są rotacje, jak nie to koniec ;-)
          if(parentForNewNode->balanceFactor)
          {
            parentForNewNode->balanceFactor = 0;
            return ;
          }


          //parentForNewNode->balanceFactor = (parentForNewNode->leftNode == newNode) ? 1 : -1;
          if(parentForNewNode->leftNode == newNode) parentForNewNode->balanceFactor= 1;
          else  parentForNewNode->balanceFactor = -1;
          grandpaNode = parentForNewNode->parentNode;

          // usatawiam balanceFactors na 1 przed dodaniem
          // nowej gałęci oraz wyznaczam grandpaForNewNode od ktorego zaczynam rotacje
          while(grandpaNode)
          {
            if(grandpaNode->balanceFactor) break; // gdy byly juz wczesniej ustawione to przerwij

            if(grandpaNode->leftNode == parentForNewNode) grandpaNode->balanceFactor = 1;
            else grandpaNode->balanceFactor = -1;
            parentForNewNode = grandpaNode; grandpaNode = grandpaNode->parentNode;
          }

          // jesli do konca byly zbalansowane to przerwij
          if(!grandpaNode) return ;

          //rotacje na podstawie balanceFactors
          if(grandpaNode->balanceFactor == 1)
          {
            if(grandpaNode->rightNode == parentForNewNode)
            {
              grandpaNode->balanceFactor = 0;
              return ;
            }
            if(parentForNewNode->balanceFactor == -1) rotationLR(grandpaNode); //Rotacja podwójna w lewo-prawo
            else rotationLL(grandpaNode); // Rotacja pojedyncza w prawo
            return ;
          }
          else
          {
            if(grandpaNode->leftNode == parentForNewNode)
            {
              grandpaNode->balanceFactor = 0;
              return ;
            }
            if(parentForNewNode->balanceFactor == 1) rotationRL(grandpaNode); //Rotacja podwójna w lewo-prawo
            else rotationRR(grandpaNode); //Rotacja pojedyncza w lewo
            return ;
          }
        }

    /*
     * @brief rotacja pojedyncza w lewo
     */
    AVLTreeNode<ContentType> * rotationRR(AVLTreeNode<ContentType> * A)
    {
      AVLTreeNode<ContentType> * B = A->rightNode, * P = A->parentNode;

      A->rightNode = B->leftNode;
      if(A->rightNode) A->rightNode->parentNode = A;
      B->leftNode = A;
      B->parentNode = P;
      A->parentNode = B;
      if(P)
      {
        if(P->leftNode == A) P->leftNode = B; else P->rightNode = B;
      }
      else rootNode = B;

      if(B->balanceFactor == -1)
      {
        A->balanceFactor = B->balanceFactor = 0;
      }
      else
      {
        A->balanceFactor = -1; B->balanceFactor = 1;
      }
      return B;
    }

    /*
     * @brief rotacja pojedyncza w prawo
     */
    AVLTreeNode<ContentType> * rotationLL(AVLTreeNode<ContentType> * A)
    {
      AVLTreeNode<ContentType> * B = A->leftNode, * P = A->parentNode;

      A->leftNode = B->rightNode;
      if(A->leftNode) A->leftNode->parentNode = A;
      B->rightNode = A;
      B->parentNode = P;
      A->parentNode = B;
      if(P)
      {
        if(P->leftNode == A) P->leftNode = B; else P->rightNode = B;
      }
      else rootNode = B;

      if(B->balanceFactor == 1)
      {
        A->balanceFactor = B->balanceFactor = 0;
      }
      else
      {
        A->balanceFactor = 1; B->balanceFactor = -1;
      }

      return B;
    }
    /*
     * @brief rotacja podwojna lewo prawo
     */
    AVLTreeNode<ContentType> * rotationRL(AVLTreeNode<ContentType> * A)
    {
      AVLTreeNode<ContentType> * B = A->rightNode, * C = B->leftNode, * P = A->parentNode;

      B->leftNode = C->rightNode;
      if(B->leftNode) B->leftNode->parentNode = B;
      A->rightNode = C->leftNode;
      if(A->rightNode) A->rightNode->parentNode = A;
      C->leftNode = A;
      C->rightNode = B;
      A->parentNode = B->parentNode = C;
      C->parentNode = P;
      if(P)
      {
        if(P->leftNode == A) P->leftNode = C; else P->rightNode = C;
      }
      else rootNode = C;

      A->balanceFactor = (C->balanceFactor == -1) ?  1 : 0;
      B->balanceFactor = (C->balanceFactor ==  1) ? -1 : 0;
      C->balanceFactor = 0;

      return C;
    }
    /*
     * @brief rotacja podwojna lewo prawo
     */
    AVLTreeNode<ContentType> * rotationLR(AVLTreeNode<ContentType> * A)
    {
      AVLTreeNode<ContentType> * B = A->leftNode, * C = B->rightNode, * P = A->parentNode;

      B->rightNode = C->leftNode;
      if(B->rightNode) B->rightNode->parentNode = B;
      A->leftNode = C->rightNode;
      if(A->leftNode) A->leftNode->parentNode = A;
      C->rightNode = A;
      C->leftNode = B;
      A->parentNode = B->parentNode = C;
      C->parentNode = P;
      if(P)
      {
        if(P->leftNode == A) P->leftNode = C; else P->rightNode = C;
      }
      else rootNode = C;

      A->balanceFactor = (C->balanceFactor ==  1) ? -1 : 0;
      B->balanceFactor = (C->balanceFactor == -1) ?  1 : 0;
      C->balanceFactor = 0;

      return C;
    }

    /// @brief Wyszukuje element wg wartości klucza
    /// @param key klucz do wyszukania

    AVLTreeNode<ContentType> * find(int key)
    {
      AVLTreeNode<ContentType> * tmpNode = rootNode;

      while((tmpNode) && (tmpNode->key != key))
      {
    	  if(key < tmpNode->key) 	 tmpNode = tmpNode->leftNode;
    	  else				 tmpNode = tmpNode->rightNode;
      }

      return tmpNode;
    }
    /// @brief Zwraca węzeł z minimalnym kluczem

    AVLTreeNode<ContentType> * findMaxKeyNode(AVLTreeNode<ContentType> * tmpNode)
    {
      while(tmpNode->rightNode) tmpNode = tmpNode->rightNode;
      return tmpNode;
    }

    /// @brief Zwraca węzeł poprzednika
    AVLTreeNode<ContentType> * findAtherNodeMatch(AVLTreeNode<ContentType> * nodeComperator)
    {
      if(nodeComperator->leftNode) return findMaxKeyNode(nodeComperator->leftNode);

      AVLTreeNode<ContentType> * y;

      do
      {
        y = nodeComperator;
        nodeComperator = nodeComperator->parentNode;
      } while(nodeComperator && (nodeComperator->rightNode != y));

      return nodeComperator;
    }

    /** @brief Usuwa element x ze struktury AVL. Zwraca usunięty węzeł
     */

    AVLTreeNode<ContentType> * remove(AVLTreeNode<ContentType> * x)
    {
      AVLTreeNode<ContentType> * t, * y, * z;
      bool nest;

      // Jeśli węzeł x posiada dwójkę dzieci, lewego i prawego potomka:
      if((x->leftNode) && (x->rightNode))
      {
        y = remove(findAtherNodeMatch(x));
        //rekurencyjnie usuwamy y za pomocą tego samego algorytmu
        nest = false;
      }
      //Jeśli węzeł x posiada tylko jedno dziecko lub nie posiada wcale dzieci:
      else  {
        if(x->leftNode) {
          y = x->leftNode;
          x->leftNode = NULL;
        }
        else {
          y = x->rightNode; x->rightNode = NULL;
        }
        x->balanceFactor = 0;
        nest = true;
      }

      if(y)  {
        y->parentNode = x->parentNode;
        if(x->leftNode)
        	{
        		y->leftNode  = x->leftNode;
        		y->leftNode->parentNode  = y;
        	}
        if(x->rightNode)
        	{
        		y->rightNode = x->rightNode;
        		y->rightNode->parentNode = y;
        	}
        y->balanceFactor = x->balanceFactor;
      }

      if(x->parentNode)   {
        if(x->parentNode->leftNode == x) x->parentNode->leftNode = y; else x->parentNode->rightNode = y;
      }
      else rootNode = y;

      if(nest)  {
        z = y;
        y = x->parentNode;
        while(y)
        {
        	// węzeł y był w stanie równowagi przed usunięciem węzła x w jednym z jego poddrzew.
          if(!(y->balanceFactor)) {
            y->balanceFactor = (y->leftNode == z) ? -1 : 1;
            break;
          }
          else {
        	//skrócone zostało cięższe poddrzewo
            if		(((y->balanceFactor ==  1) &&
            		(y->leftNode  == z)) || ((y->balanceFactor == -1) &&
            		(y->rightNode == z))) {
              y->balanceFactor = 0;
              z = y; y = y->parentNode;
            }
            else {
              t = (y->leftNode == z) ? y->rightNode : y->leftNode;

              //Wykonujemy odpowiednią rotację pojedynczą
              if(!(t->balanceFactor)) {
                if(y->balanceFactor == 1) rotationLL(y); else rotationRR(y);
                break;
              }
              //Wykonujemy odpowiednią rotację pojedynczą
              else if(y->balanceFactor == t->balanceFactor)
              {
                if(y->balanceFactor == 1) rotationLL(y); else rotationRR(y);
                z = t; y = t->parentNode;
              }
              //Wykonujemy rotację podwójną
              else
              {
                if(y->balanceFactor == 1) rotationLR(y); else rotationRL(y);
                z = y->parentNode; y = z->parentNode;
              }
            }
          }
        }
      }
      return x;
    }
    void      print()
    {
    	this->recurringPrint(this->rootNode);
    }
    void recurringPrint(AVLTreeNode<ContentType> * x)
    {
      cout<< "klucz:"<< x->key <<"\n";
      if(x->leftNode)  recurringPrint(x->leftNode);
      if(x->rightNode) recurringPrint(x->rightNode);
    }

    void print(AVLTreeNode<ContentType> * x)
    {
      cout << x->key << " : bf = " << setw(2) << x->balanceFactor;
      cout << endl;
      if(x->leftNode)  print(x->leftNode);
      if(x->rightNode) print(x->rightNode);
    }

    void insertBST(int key)
    {

      AVLTreeNode<ContentType> *n =new AVLTreeNode<ContentType>(key);
      AVLTreeNode<ContentType> * y, * x = rootNode;

      y = n->leftNode = n->rightNode = NULL;

      while(x)
      {
        if(n->key == x->key)
        {
          delete n;
          return;
        }
        y = x;
        x = (n->key < x->key) ? x->leftNode : x->rightNode;
      }

      n->parentNode = y;

      if(!y) rootNode = n;
      else if(n->key < y->key) y->leftNode  = n;
      else                     y->rightNode = n;

      return;

    }


};




#endif /* AVLTREE_H_ */
