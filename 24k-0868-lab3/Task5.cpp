#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node(string s) {
        song = s;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
    }

    void addSong(string song) {
        Node* newNode = new Node(song);
        if (!head) {
            head = tail = newNode;
            tail->next = head; 
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
        cout << "Added: " << song << "\n";
    }

    
    void removeSong() {
        if (!head) {
            cout << "Playlist is empty. Nothing to remove.\n";
            return;
        }
        if (head == tail) { 
            cout << "Removed: " << head->song << "\n";
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            cout << "Removed: " << head->song << "\n";
            head = head->next;
            tail->next = head; 
            delete temp;
        }
    }

    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "Playlist: ";
        Node* temp = head;
        do {
            cout << temp->song << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)\n";
    }

    void searchSong(string song) {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->song == song) {
                cout << "Song \"" << song << "\" found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Song \"" << song << "\" not found in playlist.\n";
    }

    void playSongs(int n) {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "Now playing: \n";
        Node* temp = head;
        for (int i = 0; i < n; i++) {
            cout << temp->song << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    Playlist playlist;
    int choice;
    string song;

    do {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Search Song\n";
        cout << "5. Play Songs (looped)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, song);
                playlist.addSong(song);
                break;
            case 2:
                playlist.removeSong();
                break;
            case 3:
                playlist.displayPlaylist();
                break;
            case 4:
                cout << "Enter song title to search: ";
                getline(cin, song);
                playlist.searchSong(song);
                break;
            case 5:
                int n;
                cout << "Enter number of songs to play: ";
                cin >> n;
                playlist.playSongs(n);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
