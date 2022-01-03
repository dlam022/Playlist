#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_

#include <string>
#include "Playlist.h"

using namespace std;

class PlaylistNode {
    public:
        PlaylistNode(); //default constructor
        PlaylistNode(string nodeID, string name, string singer, int musicLength, PlaylistNode* valNode = nullptr);//parameterized Constructor
        void InsertAfter(PlaylistNode *nodetemp);
        void SetNext(PlaylistNode* nodePoi);
        string GetID() const;
        string GetSongName() const;
        string GetArtistName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext() const;
        void PrintPlaylistNode();
    private:
        string uniqueID; //Initialized to "none" in default constructor
        string songName; //Initialized to "none" in default constructor
        string artistName; //Initialized to "none" in default constructor
        int songLength; //Initialized to 0 in default constructor
        PlaylistNode *nextNodePtr; //Initialized to 0 in default constructor

};

#endif