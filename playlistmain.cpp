#include <iostream>
#include <string>

using namespace std;

#include "Playlist.h"



void PrintMenu(const string playlistTitle) { //output menu function, if invalid, keep printing menu, implement the word quit
    PlaylistNode *prevNode = nullptr;
    PlaylistNode *headNode = nullptr;
    PlaylistNode *tailNode = nullptr;
    //PlayListNode *newSong = nullptr;
    PlaylistNode *currNode = nullptr;
    char choice = ' ';
    string singerName;
    string musicName;
    string songID;
    int lengthOfSong = 0;
    int songPos = 0;
    int newPos = 0;
    int numNodes = 0;

    while(choice != 'q') {
        choice = ' ';
        cout << playlistTitle << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl << endl;
        while(choice != 'a' && choice != 'd' && choice != 'c' && choice != 's' && choice != 't' && choice != 'o' && choice != 'q') {
            cout << "Choose an option:" << endl;
            cin >> choice;
            cin.ignore();
        }
        // if(choice == 'o') { //output playlist function
        //     int number = 1;
        //     cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
        //     if(headNode == nullptr) { //check if playlist is empty
        //         cout << "Playlist is empty" << endl; 
        //         cout << endl;
        //     }
        //     else{
        //         for(currNode = headNode; currNode != nullptr; currNode = currNode->GetNext()) {
        //             cout << number << "." << endl;
        //             number++;
        //             currNode->PrintPlaylistNode();
        //             cout << endl;
        //         }
        //     }
        // }
        if(choice == 'a') {  //add song function
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> songID;
            cout << "Enter song's name:" << endl;
            cin.ignore();
            getline(cin, musicName);
            cout << "Enter artist's name:" << endl;
            getline(cin, singerName);
            cout << "Enter song's length (in seconds):";
            cin >> lengthOfSong;
            cout << endl;
            cin.ignore();
            PlaylistNode *newSong = new PlaylistNode(songID, musicName, singerName, lengthOfSong, nullptr);
            if(headNode == nullptr) { //if the list is empty, new song becomes the first song
                headNode = newSong;
                tailNode = newSong;
            }
            else{
                tailNode->InsertAfter(newSong); //use to insert the song in the back
                tailNode = newSong;  //the tail becomes the new song
            }
            cout << endl;
        }
        if(choice == 'd') { //remove function
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> songID;
            currNode = headNode;
            bool temp = false; //need bool to check
            while(currNode != nullptr) { //does ID exist
                if(currNode->GetID() == songID) {
                    temp = true;
                    break;
                }
                else{
                    currNode = currNode->GetNext(); //checks through the whole playlist
                }
            }
            if(!temp) {
                cout << "Could not find ID" << endl;
            }
            else if(headNode->GetID() == songID) {
                PlaylistNode *tempVal = headNode;
                cout << "\"" << headNode->GetSongName() << "\"" << " removed." << endl;
                headNode = headNode->GetNext();
                delete tempVal; //no memory leak
            }
            else{
                currNode = headNode;
                while(currNode != nullptr) {
                    if(currNode->GetNext()->GetID() == songID) {
                        if(currNode->GetNext() == tailNode) {
                            cout << "\"" << currNode->GetNext()->GetSongName() << "\"" << " removed." << endl;
                            currNode->SetNext(nullptr); 
                            delete tailNode; //no memory leaks
                            tailNode = currNode;
                            break;
                        }
                    }
                    if(currNode->GetID() == songID) {
                        cout << "\"" << currNode->GetSongName() << "\"" << " removed." << endl;
                        prevNode->SetNext(currNode->GetNext()); //fix the list after song is removed
                        delete currNode; //no memory leaks
                        break;
                    }
                    else{
                        prevNode = currNode;
                        currNode = currNode->GetNext();
                    }

                    
                }
            }
            cout << endl;
        }
        if(choice == 'c') { //change position of the song function
            cout << "CHANGE POSITION OF SONG" << endl;
            bool pos = false;
            bool tempo = true;
            if(headNode == nullptr) {
                cout << "Nothing is changed..." << endl;
                tempo = false;
                pos = true;
            }
            else if(headNode == nullptr && tailNode == headNode) {
                cout << "Nothing is changed..." << endl;
                tempo = false;
                pos = true;
            }
            else if(headNode == tailNode) {
                cout << "Nothing can be changed..." << endl;
                tempo = false;
                pos = true;
            }
            while(!pos) {
                cout << "Enter song's current position:" << endl;
                cin >> songPos;
                cout << "Enter new position for song:" << endl;
                cin >> newPos;
                prevNode = nullptr;
                currNode = headNode;
                numNodes = 0;
                while(currNode != nullptr) {
                    numNodes++;
                    currNode = currNode->GetNext();
                }
                if(numNodes < songPos) {
                    cout << "That position doesn't exist, try again" << endl;
                }
                else if(numNodes < newPos) {
                    cout << "That position doesn't exist, try again" << endl;
                }
                else{
                    pos = true;
                }
                
            }
            if(tempo) {
                int currPos;
                string currSong;
                currNode = headNode;
                for(currPos = 1; (currNode != nullptr && currPos < songPos); currPos++) {
                    prevNode = currNode;
                    currNode = currNode->GetNext();
                }
                currSong = currNode->GetSongName();
                if(prevNode == nullptr) {
                    headNode = currNode->GetNext();
                }
                else{
                    prevNode->SetNext(currNode->GetNext());
                }
                if(currNode == tailNode) {
                    tailNode = prevNode;
                }
                PlaylistNode *kirk = currNode;
                prevNode = nullptr;
                currNode = headNode;
                for(currPos = 1; (currNode != nullptr && currPos < newPos); currPos++) {
                    prevNode = currNode;
                    currNode = currNode->GetNext();
                }
                if(prevNode == nullptr) {
                    kirk->SetNext(headNode);
                    headNode = kirk;
                }
                else{
                    prevNode->InsertAfter(kirk);
                }
                if(currNode == nullptr) {
                    tailNode = kirk;
                }
                cout << "\"" << currSong << "\"" << " moved to position " << newPos << endl;
                cout << endl;
            }
            
        }
        if(choice == 's') { //search songs by specific artist function
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin, singerName);
            cout << endl;
            int num = 1;
            for(currNode = headNode; currNode != nullptr; currNode = currNode->GetNext()) {
                if(currNode->GetArtistName() == singerName) {
                    cout << num << "." << endl;
                    currNode->PrintPlaylistNode();
                    cout << endl;
                    num++;

                }
                else{
                    num++;
                }
            }
        }
        if(choice == 't') { //output time of playlist function
            int time = 0;
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            for(currNode = headNode; currNode != nullptr; currNode = currNode->GetNext()) { //add all the songs length into time
                time += currNode->GetSongLength();
            }
            cout << "Total time: " << time << " seconds" << endl;
            cout << endl;
        }
        if(choice == 'o') { //output playlist function
            int number = 1;
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if(headNode == nullptr) { //check if playlist is empty
                cout << "Playlist is empty" << endl; 
                cout << endl;
            }
            else{
                for(currNode = headNode; currNode != nullptr; currNode = currNode->GetNext()) {
                    cout << number << "." << endl;
                    number++;
                    currNode->PrintPlaylistNode();
                    cout << endl;
                }
            }
        }
    }    


}


int main() {
    string playlistTitle;

    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    cout << endl;

    PrintMenu(playlistTitle);
   
    return 0;
}

