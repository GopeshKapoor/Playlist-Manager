#include <iostream>
#include <string>
using namespace std;

const int MAX_PLAYLISTS = 4;
const int MAX_SONGS = 100;

string playlistNames[MAX_PLAYLISTS] = {"Happy", "Sad", "Romantic", "Liked"};

struct Song {
    string name;
    string artist;
    Song* next;
};

struct Playlist {
    string name;
    Song* head;
};

Playlist playlists[MAX_PLAYLISTS];
Song* currentSong = NULL;
string currentPlaylistName = "";
bool isPlaying = false;

void printDivider() {
    cout << "\n------------------------------------------------------------\n";
}

void printHeader(const string& title) {
    printDivider();
    cout << "                       " << title << "\n";
    printDivider();
}

int choosePlaylist() {
    printHeader("Select Playlist");
    for (int i = 0; i < MAX_PLAYLISTS; ++i) {
        cout << " " << i + 1 << ". " << playlistNames[i] << "\n";
    }
    cout << "\nEnter choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice < 1 || choice > MAX_PLAYLISTS) {
        cout << "Invalid choice.\n";
        return -1;
    }
    return choice - 1;
}

void displaySongs(int index) {
    Song* temp = playlists[index].head;
    if (temp==NULL) {
        cout << "\n>> No songs in this playlist.\n";
        return;
    }
    int count = 1;
    while (temp!=NULL) {
        cout << " " << count++ << ". " << temp->name << " - " << temp->artist << "\n";
        temp = temp->next;
    }
}

int chooseSong(int index) {
    Song* temp = playlists[index].head;
    int count = 0;
    Song* songArr[MAX_SONGS];

    while (temp) {
        songArr[count++] = temp;
        temp = temp->next;
    }

    if (count == 0) {
        cout << "\n>> No songs available.\n";
        return -1;
    }

    for (int i = 0; i < count; ++i) {
        cout << " " << i + 1 << ". " << songArr[i]->name << " - " << songArr[i]->artist << "\n";
    }

    cout << "\nEnter song number: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice < 1 || choice > count) {
        cout << "Invalid song choice.\n";
        return -1;
    }

    return choice - 1;
}

void addSong() {
    int index = choosePlaylist();
    if (index == -1) return;

    string name, artist;
    cout << "Enter Song Name: ";
    getline(cin, name);
    cout << "Enter Artist Name: ";
    getline(cin, artist);

    Song* newSong = new Song;
    newSong->name = name;
    newSong->artist = artist;
    newSong->next = NULL;

    if (playlists[index].head == NULL) {
    playlists[index].head = newSong;
} else {
    Song* temp = playlists[index].head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newSong;
}

cout << "\n>> Song added successfully to '" << playlistNames[index] << "'.\n";
}


void playPause() {
    if (currentSong==NULL) {
        cout << "\n>> No song is currently playing.\n";
        return;
    }
    isPlaying = !isPlaying;
    cout << (isPlaying ? "\n>> Resumed: " : "\n>> Paused: ") << currentSong->name << "\n";
}

void deleteSong() {
    int index = choosePlaylist();
    if (index == -1) return;

    Song* &head = playlists[index].head;

    if (head == NULL) {
        cout << "\n>> No songs to delete.\n";
        return;
    }
    Song* temp = head;
    int songNumber = 1;
    while (temp != NULL) {
        cout << " " << songNumber << ". " << temp->name << " - " << temp->artist << "\n";
        temp = temp->next;
        songNumber++;
    }

    cout << "\nEnter song number to delete: ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice < 1 || choice >= songNumber) {
        cout << "Invalid choice.\n";
        return;
    }

    Song* current = head;
    Song* previous = NULL;

    for (int i = 1; i < choice; i++) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        head = head->next;
    } else {
        previous->next = current->next;
    }

    delete current;

    cout << "\n>> Song deleted successfully.\n";
}


void playSong() {
    int index = choosePlaylist();
    if (index == -1) return;

    cout << "\nSongs in '" << playlistNames[index] << "' playlist:\n";
    int songIndex = chooseSong(index);
    if (songIndex == -1) return;

    Song* temp = playlists[index].head;
    for (int i = 0; i < songIndex; ++i)
        temp = temp->next;

    currentSong = temp;
    currentPlaylistName = playlistNames[index];
    isPlaying = true;

    cout << "\n>> Now Playing: " << currentSong->name << " - " << currentSong->artist << "\n";
}


void playNext() {
    if (currentSong == NULL || currentSong->next == NULL) {
        cout << "\n>> No next song in current playlist.\n";
        return;
    }

    currentSong = currentSong->next;
    isPlaying = true;

    cout << "\n>> Now Playing: " << currentSong->name << " - " << currentSong->artist << "\n";
}



void displayMenu() {
    printHeader("PLAYLIST MANAGER - MAIN MENU");
    cout << " 1. Add Song\n";
    cout << " 2. Delete Song\n";
    cout << " 3. Display Playlist\n";
    cout << " 4. Play Song\n";
    cout << " 5. Pause/Resume\n";
    cout << " 6. Play Next Song\n";
    cout << " 7. Exit\n";
    printDivider();
    cout << "Enter your choice: ";
}

int main() {
    for (int i = 0; i < MAX_PLAYLISTS; i++) {
        playlists[i].name = playlistNames[i];
        playlists[i].head = NULL;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3: {
                int index = choosePlaylist();
                if (index != -1)
                    displaySongs(index);
                break;
            }
            case 4:
                playSong();
                break;
            case 5:
                playPause();
                break;
            case 6:
                playNext();
                break;
            case 7:
                cout << "\n>> Exiting Playlist Manager. Thank you!\n";
                break;
            default:
                cout << "\n>> Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
