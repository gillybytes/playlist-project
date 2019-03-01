/*
Author: Gillian Pantaleon
Course: CSCI-235
Project 2

This header file declares the Song class.
*/


#ifndef SONG_H_
#define SONG_H_

#include <string>


class Song
{
	public:
		Song();	//default constructor
		Song(const std::string& title, const std::string& author = "", const std::string& album = "");	//parameterized constructor
		void setTitle(std::string title);	//gives a value to title_
		void setAuthor(std::string author);	//gives a value to author_
		void setAlbum(std::string album);	//gives a value to album_
		std::string getTitle() const;	//returns title_
		std::string getAuthor() const;	//returns author_
		std::string getAlbum() const;	//returns album_
		friend bool operator==(const Song& lhs, const Song& rhs);	//returns true if Song objects are the same
		
	private:
		std::string title_;
		std::string author_;
		std::string album_;
};	//end of Song

#endif

