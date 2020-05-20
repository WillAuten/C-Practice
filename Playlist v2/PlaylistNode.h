#ifndef _playlist_h
#define _playlist_h
#include<iostream>
#include<string>
using namespace std;

class PlaylistNode {
   string uniqueID = "none";
   string songName = "none";
   string artistName = "none";
   int songLength = 0;
   PlaylistNode* nextNodePtr;
public:
   PlaylistNode();
   PlaylistNode(string id, string sn, string an, int sl);
   void InsertAfter(PlaylistNode* nn);
   void SetNext(PlaylistNode* nn);
   string GetID() const;
   string GetSongName() const;
   string GetArtistName() const;
   int GetSongLength();
   PlaylistNode* GetNext();
   void PrintPlaylistNode();
};

class Playlist {
private:
   PlaylistNode *lst;
   int nn = 0;
public:

   Playlist();
   void Add(string id, string sn, string an, int sl);
   void Remove(string id);
   void change(int old, int newInd);
   void printSongsByArtist(string an);
   void printTotalTime();
   void printPlaylist();
};
#endif