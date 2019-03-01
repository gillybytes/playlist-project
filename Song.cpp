/*
Author: Gillian Pantaleon
Course: CSCI-235
Project 2

This file contains the implementation of the Song class.
*/


#include "Song.h"

Song::Song() {}	//default constructor


//Instantiates a Song object with title, author, and album
//If author and album are not given, then the default is blank 
Song::Song(const std::string& title, const std::string& author, const std::string& album)
{
	title_ = title;
	author_ = author;
	album_ = album;
}


//Assigns a value to title_
void Song::setTitle(std::string title)
{
	title_ = title;
}


//Assigns a value to author_
void Song::setAuthor(std::string author)
{
	author_ = author;
}


//Assigns a value to album_
void Song::setAlbum(std::string album)
{
	album_ = album;
}


std::string Song::getTitle() const
{
	return title_;
}


std::string Song::getAuthor() const
{
	return author_;
}


std::string Song::getAlbum() const
{
	return album_;
}


//Helper function: determines if 2 objects are the same
//Returns true if members of both objects are equal
bool operator==(const Song& lhs, const Song& rhs)
{
	return ( (lhs.title_ == rhs.title_) && (lhs.author_ == rhs.author_) && (lhs.album_ == rhs.album_) );
}
