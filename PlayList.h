/*
Author: Gillian Pantaleon
Course: CSCI-235
Project 3

This header file declares the PlayList class. PlayList is the derived class of LinkedSet.
*/


#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "LinkedSet.h"
#include "Song.h"


class PlayList: public LinkedSet<Song>
{
	public:
		PlayList();	//Default Constructor
		PlayList(const Song& a_song);	//Parameterized Constructor
		PlayList(const PlayList & a_play_list); //Copy Constructor
		~PlayList();	//Destructor
		bool add(const Song& new_song) override;	//Adds Song to end of PlayList
		bool remove(const Song& a_song) override;	//Removes a Song and maintains order of PlayList
		void displayPlayList();
		void loop();
		void unloop();

	private:
		Node<Song>* tail_ptr_;	//Pointer to last node
		Node<Song>* getPointerToLastNode() const;	//Helper: returns the pointer to the last node
		Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;	//Helper: returns the pointer to a target node
		
};	//end PlayList

#endif


