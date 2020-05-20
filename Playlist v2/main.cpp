#include<iostream>
#include<string>
#include<cstdlib>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(string sname) {
   cout << "\n" << sname << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl << endl;
   cout << "Choose an option:";
}

int main() {
   Playlist playlst;
   string sname;
   string id;
   string songname;
   string artistname;
   int len;
   char ch;
   cout << "Enter playlist's title:" << endl;
   getline(cin, sname);
   while (1) {
       PrintMenu(sname);
       cin >> ch;
       cin.ignore();
       if (ch == 'q')
           break;
       switch (ch) {
       case 'a':
           cout << "ADD SONG" << endl;
           cout << "Enter song's unique ID:" << endl;
           getline(cin, id);
           cout << "Enter song's name:" << endl;
           getline(cin, songname);
           cout << "Enter artist's name:" << endl;
           getline(cin, artistname);
           cout << "Enter song's length (in seconds):" << endl;
           cin >> len;
           playlst.Add(id, songname, artistname, len);
           break;
       case 'd':
           cout << "REMOVE SONG" << endl;
           cout << "Enter song's unique ID:";
           getline(cin, id);
           playlst.Remove(id);
           break;
       case 'c': {
           cout << "CHANGE POSITION OF SONG" << endl;
           cout << "Enter song's current position:" << endl;
           int curPos;
           cin >> curPos;
           cout << "Enter new position for song:" << endl;
           int newPos;
           cin >> newPos;
           playlst.change(curPos, newPos);
           break;
       }
       case 's':
           cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
           cout << "Enter artist's name: ";
           getline(cin, artistname);
           playlst.printSongsByArtist(artistname);
           break;
       case 't':
           cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
           playlst.printTotalTime();
           break;
       case 'o':
           cout << "\n" << sname << " - OUTPUT FULL PLAYLIST";
           playlst.printPlaylist();
           break;
       default:
           cout << "INVALID CHOICE" << endl;
   }
}
return 0;
}