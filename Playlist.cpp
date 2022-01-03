#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode() {  //default constructor
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}
PlaylistNode::PlaylistNode(string nodeID, string name, string singer, int musicLength, PlaylistNode* valNode) {
    uniqueID = nodeID;
    songName = name;
    artistName = singer;
    songLength = musicLength;
    nextNodePtr = valNode;
}

void PlaylistNode::InsertAfter(PlaylistNode *nodetemp) {
    nodetemp->SetNext(this->GetNext());
    this->SetNext(nodetemp);
}

void PlaylistNode::SetNext(PlaylistNode* nodePoi) {
    nextNodePtr = nodePoi;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName()const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}
PlaylistNode* PlaylistNode::GetNext() const{
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}