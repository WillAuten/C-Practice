#include "PlaylistNode.h"
PlaylistNode::PlaylistNode() {
   nextNodePtr = NULL;
}

PlaylistNode::PlaylistNode(string id, string sn,
   string an, int sl) {
   uniqueID = id;
   songName = sn;
   artistName = an;
   songLength = sl;
}
void PlaylistNode::InsertAfter(PlaylistNode* nn) {
   nn->SetNext(this);
}
void PlaylistNode::SetNext(PlaylistNode* nn) {
   nextNodePtr = nn;
}
string PlaylistNode::GetID() const {
   return uniqueID;
}
string PlaylistNode::GetSongName() const {
   return songName;
}
string PlaylistNode::GetArtistName() const {
   return artistName;
}
int PlaylistNode::GetSongLength() {
   return songLength;
}
PlaylistNode* PlaylistNode::GetNext() {
   return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}
Playlist::Playlist() {
   lst = NULL;
}

void Playlist::Add(string id, string sn, string an, int sl) {
   PlaylistNode* PlayN = new PlaylistNode(id, sn, an, sl);
   PlayN->SetNext(NULL);
   PlaylistNode *tt = lst;
   if (tt != NULL) {
       while (tt->GetNext() != NULL)
           tt = tt->GetNext();
       tt->SetNext(PlayN);
   }
   else {
       lst = PlayN;
   }
   nn++;
}

void Playlist::Remove(string id) {
   PlaylistNode *tt = lst;
   if (tt == NULL)
       return;
   if (tt->GetNext() == NULL) {
       delete tt;
       lst = NULL;
   }
   else {
       PlaylistNode *pp = tt;
       do
       {
           if (tt->GetID().compare(id) == 0)
               break;
           pp = tt;
           tt = tt->GetNext();
       } while (tt != NULL);
       pp->SetNext(tt->GetNext());
       cout << tt->GetSongName() << " removed" << endl;
       delete tt;
       nn--;
   }
}

void Playlist::change(int curPos, int newPos) {
   PlaylistNode* head = 0;
   PlaylistNode* tail = 0;
   PlaylistNode* prevCurrentPosition = 0;
   PlaylistNode* currCurrentPosition = head;
   int counter = 1;
   while (currCurrentPosition != NULL && counter != curPos) {
       prevCurrentPosition = currCurrentPosition;
       currCurrentPosition = currCurrentPosition->GetNext();
       counter++;
   }

   PlaylistNode* prevNewPosition = 0;
   PlaylistNode* currNewPosition = head;
   counter = 1;
   while (currNewPosition != NULL && counter != newPos) {
       prevNewPosition = currNewPosition;
       currNewPosition = currNewPosition->GetNext();
       newPos++;
   }
   if (prevCurrentPosition != NULL) {
       prevCurrentPosition->SetNext(currNewPosition);
   }
   else {
       head = currNewPosition;
   }
   if (prevNewPosition != NULL) {
       prevNewPosition->SetNext(currCurrentPosition);
   }
   else {
       head = currCurrentPosition;
   }

   PlaylistNode* temp = currCurrentPosition->GetNext();
   currCurrentPosition->SetNext(currNewPosition->GetNext());
   currNewPosition->SetNext(temp);
   cout << "\"" << currCurrentPosition->GetSongName() << "\""
       << " moved to position " << newPos << endl << endl;
}

void Playlist::printSongsByArtist(string an) {
   PlaylistNode *pp = lst;
   int kk = 0;
   if (pp == NULL) {
       cout << "Playlist is empty" << endl;
       return;
   }
   while (pp != NULL) {
       kk++;
       if (pp->GetArtistName().compare(an) == 0) {
           cout << endl;
           cout << kk << endl;
           pp->PrintPlaylistNode();
       }
       pp = pp->GetNext();
   }
}

void Playlist::printTotalTime() {
   int len = 0;
   PlaylistNode *pp = lst;
   if (pp == NULL) {
       cout << "Playlist is empty" << endl;
   }
   while (pp != NULL) {
       len = len + pp->GetSongLength();
       pp = pp->GetNext();
   }
   cout << "Total time:" << len << endl;
}

void Playlist::printPlaylist() {
   PlaylistNode *pp = lst;
   int kk = 0;
   if (pp == NULL) {
       cout << "Playlist is empty" << endl;
       return;
   }
   while (pp != NULL) {
       kk++;
       cout << endl;
       cout << kk << "." << endl;
       pp->PrintPlaylistNode();
       pp = pp->GetNext();
   }
}