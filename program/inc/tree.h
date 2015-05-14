/*
 * tree.h
 *
 *  Created on: May 14, 2015
 *      Author: serek8
 */

#ifndef TREE_H_
#define TREE_H_



template <class ContentType>
class TreeElement
{
public:
	TreeElement *left, *right;
	ContentType content;

	TreeElement(ContentType contentToPush)
	{
		left = 0;
		right = 0;
		content = contentToPush;
	}


	void addLeft(ContentType contentToPush)
	{
		this->left = new TreeElement(contentToPush);
	}

	void addRight(ContentType contentToPush)
	{
		this->right = new TreeElement(contentToPush);
	}

	char showLeft()
	{
		return this->left;
	}
	char showRight()
	{
		return this->right;
	}


	void print()
	{
		std::cout<<this->content<<" ";
		if(this->left != 0) left->print();
		if(this->right != 0) right->print();

	}

};

template <class ContentType>
class Tree
{
public:
	TreeElement<ContentType> *head;
	TreeElement<ContentType> *iterator;
	int isSet;

	Tree(ContentType topElement)
	{
		head = new TreeElement<ContentType>(topElement);
		iterator = head;
		isSet = 0;
	}

	void add(ContentType contentToPush)
	{
		if(isSet) { isSet=0; return; }
		if(iterator->content > contentToPush)
		{
			if(iterator->left == 0)
			{
				iterator->addLeft(contentToPush);
			}
			else
			{
				iterator=iterator->left;
				add(contentToPush);
				isSet = 1;
			}
		}
		if(iterator->content <= contentToPush)
		{
			if(iterator->right == 0)
			{
				iterator->addRight(contentToPush);
			}
			else
			{
				iterator=iterator->right;
				add(contentToPush);
				isSet = 1;
			}
		}
	}

	void print(){head->print();}

};



#endif /* TREE_H_ */
