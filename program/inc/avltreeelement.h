/*
 * avltreeelement.h
 *
 *  Created on: May 21, 2015
 *      Author: serek8
 */

#ifndef AVLTREEELEMENT_H_
#define AVLTREEELEMENT_H_

// definicja typu danych reprezentującego węzeł drzewa AVL
//--------------------------------------------------------
template <class ContentType>
/*
 * @brief element drzewa BST
 *
 */
class AVLTreeNode
{
public:

	// Gałąź rodzica, lewa podgaląć, prawa podgałąź
	AVLTreeNode * parentNode,
				* leftNode,
				* rightNode;

  //klucz
  int key, balanceFactor;
  ContentType content;

   AVLTreeNode()
  {
	   parentNode = leftNode = rightNode = NULL;
	   key = balanceFactor = 0;
  }
   AVLTreeNode(int newKey)
   {
	   parentNode = leftNode = rightNode = NULL;
	   balanceFactor = 0;
		key = newKey;
   }
};




#endif /* AVLTREEELEMENT_H_ */
