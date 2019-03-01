/*
Author: Gillian Pantaleon
Course: CSCI-235
Project 3

This file contains the implementation of the PlayList class. PlayList inherits from LinkedSet. 
*/


#include "PlayList.h"
#include <iostream>


PlayList::PlayList() : tail_ptr_(nullptr) {}	//Default constructor


//Parameterized constructor: Adds a Song when a PlayList object is instantiated
PlayList::PlayList(const Song& a_song)
{
	tail_ptr_ = nullptr;
	add(a_song);
}


//Copy Constructor
PlayList::PlayList(const PlayList & a_play_list) : LinkedSet(a_play_list)
{
	if (!isEmpty())	tail_ptr_ = getPointerToLastNode();	//points tail_ptr_ to end of the chain
	else tail_ptr_ = nullptr;
}


//Destructor
PlayList::~PlayList()
{
	unloop();
	delete tail_ptr_;
	tail_ptr_ = nullptr;
	clear();
}


//Precondition: PlayList is empty or contains at least 1 song
//Postcondition: Adds a Song to end of PlayList
//Returns true if addition successful; otherwise false 
bool PlayList::add(const Song& new_song)
{
	if (!contains(new_song))
	{
		Node<Song>* next_node_ptr = new Node<Song>();
		next_node_ptr->setItem(new_song);
		
		if (head_ptr_ == nullptr) head_ptr_ = next_node_ptr; //Empty case
		else tail_ptr_->setNext(next_node_ptr);

		tail_ptr_ = next_node_ptr;

		item_count_++;

		return true;
    }
    else return false;
}


//Precondition: PlayList contains at least 1 song
//Postcondition: Removes a Song from PlayList and maintains order
//Returns true if removal successful; otherwise false
bool PlayList::remove(const Song& a_song)
{
	Node<Song>* previous_ptr = nullptr;
	Node<Song>* target_node_ptr = getPointerTo(a_song, previous_ptr);	//previous_ptr value changes
	bool can_remove_item = !isEmpty() && (target_node_ptr != nullptr);
	if (can_remove_item)
	{
		if (target_node_ptr == head_ptr_) LinkedSet::remove(a_song);	//Removes 1st Song
		else
		{
			target_node_ptr->setItem(previous_ptr->getItem());	//Copy data from previous node to target node

        	if (target_node_ptr != tail_ptr_)	//Removes Song from middle of PlayList
			{
				//Deletes target node
				Node<Song>* remove_node_ptr = target_node_ptr;
				target_node_ptr = target_node_ptr->getNext();

				previous_ptr->setNext(target_node_ptr);	//prev_ptr_ now points to subsequent node after target

				//Frees up the heap
				remove_node_ptr->setNext(nullptr);
				delete remove_node_ptr;
				remove_node_ptr = nullptr;
			}
			else	//Removes Last song
			{
				target_node_ptr->setItem(previous_ptr->getItem());	//Copies data from previous node to target node
	
				//Frees up the heap
				previous_ptr->setNext(nullptr);
				delete target_node_ptr;
				target_node_ptr = nullptr;
    	    }    
        item_count_--;
    	}
    }
    return can_remove_item;
}


//Shows all Songs in PlayList
void PlayList::displayPlayList()
{
	for (int i = 0; i < getCurrentSize(); i++)
		std::cout << "* Title: " << toVector()[i].getTitle() << " * Author: " << toVector()[i].getAuthor()<< " * Album: " << toVector()[i].getAlbum() << "*\n";
	std::cout << '\n' << "End of playlist" << std::endl;
}


//Loops the Songs in PlayList
void PlayList::loop()
{
	tail_ptr_ = head_ptr_;
}


//Removes the loop
void PlayList::unloop()
{
	tail_ptr_ = getPointerToLastNode();
}




//Helper function: traverses the linked chain and returns the pointer to the last node
//Precondition: PlayList is not empty
//Postcondition: Returned pointer points to the last node of the chain
Node<Song>* PlayList::getPointerToLastNode() const
{
	Node<Song>* last_node_ptr = head_ptr_;
	Node<Song>* check_next_ptr = last_node_ptr;
	for (int i =  0; i < item_count_; i++)
	{
		check_next_ptr = check_next_ptr->getNext();
		if (check_next_ptr == nullptr) break;	//last_node_ptr points to the last node
		else last_node_ptr = last_node_ptr->getNext();
	}
	return last_node_ptr;
}


//Helper function: returns a pointer to the target Song, or nullptr if target is not in PlayList
//Precondition: PlayList is not empty
//Postcondition: previous_ptr is null if target is not in PlayList or if target is the 1st Song,
//					otherwise it points to the node preceding target
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const
{
	Node<Song>* current_ptr = LinkedSet::getPointerTo(target);	//Returns pointer to target node, or nullptr if not in PlayList
	if (current_ptr != nullptr && item_count_ > 1)	//Iterates thru the linked chain if target is in PlayList and not 1st Song 
	{
		previous_ptr = head_ptr_;
		Node<Song>* check_next_ptr = previous_ptr;
		bool found = false;
		while (!found && check_next_ptr != current_ptr)	//Traverses the chain until previous_ptr points to node preceding the target
		{
			check_next_ptr = check_next_ptr->getNext();	//check_next_ptr points to the subsequent node
			if (check_next_ptr == current_ptr)	found = true;	//previous_ptr points to the correct node
			else previous_ptr = previous_ptr->getNext();
		}
	}
	return current_ptr;
}
