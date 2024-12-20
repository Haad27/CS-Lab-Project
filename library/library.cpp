#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // For Windows text-to-speech
#include <sapi.h>    // For Windows SAPI

using namespace std;
bool flag = true;

void readBook(string fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
    {

        cout << "Error: Cannot open file!" << endl;
        return;
    }

    string lines[30]; // Array to store 30 lines
    int pageNumber = 1;
    bool running = true;
    
    ofstream Myfile("books.txt" , ios :: app);
    if(Myfile.is_open())
    {
        Myfile << fileName << endl;
        Myfile.close();
    }
   

    while (running)
    {
        system("cls"); // clears the page
        cout << "===============================\n";
        cout << "    Simple Book Reader        \n";
        cout << "    Page " << pageNumber << "                 \n";
        cout << "===============================\n\n";

        // Read 30 lines into array
        // so we can go to next page by readers will
        int lineCount = 0;
        for (int i = 0; i < 30; i++)
        {
            if (getline(file, lines[i]))
            {
                lineCount++;
            }
        }
 
        // Display the lines we read
        for (int i = 0; i < lineCount; i++)
        {
            cout << lines[i] << endl;
        }

        // If no lines were read, we're at the end
        if (lineCount == 0)
        {
            cout << "\n===============================\n";
            cout << "         End of book!         \n";
            cout << "===============================\n";
            cout << "Press Enter to exit...";
            // to remove trash value otherwise it may get garbage value
            cin.ignore(200, '\n');
            // so it pausses unter user enters any keyword so we can see before the page goes on
            cin.get();
            break;
        }
        bool validChoice = false;
        while (!validChoice)
        {
            cout << "\n-------------------------------\n";
            cout << "1. Next Page\n";
            cout << "2. Exit\n";
            cout << "-------------------------------\n";
            cout << "Choice (1-2): ";

            int choice;
            if (!(cin >> choice))
            {
                cin.clear();           // Clear error flags
                cin.ignore(200, '\n'); // Clear input buffer
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            switch (choice)
            {
            case 1:
                validChoice = true;
                break;
            case 2:
                running = false;
                validChoice = true;
                break;
            default:
                cout << "Please enter a choice between 1 and 2" << endl;
            }
        }
        pageNumber++;
    }

    file.close();
}

void deleteBook(string fileName)
{
    if (remove(fileName.c_str()) == 0)
    {
        cout << "Book '" << fileName << "' deleted successfully!\n";
    }
    else
    {
        cout << "Error: Could not delete file '" << fileName << "'.\n";
    }
}
void createSampleBook()
{
    ofstream file("sample_book.txt"); 
    if (file.is_open())
    {
        // Title and Author
        file << "                        The Little Prince\n";
        file << "                        by Antoine de Saint-Exupery\n\n";

        // Chapter 1
        file << "Chapter 1\n\n";
        file << "Once when I was six years old I saw a magnificent picture in a book,\n";
        file << "called True Stories from Nature, about the primeval forest. It was a\n";
        file << "picture of a boa constrictor in the act of swallowing an animal.\n\n";
        file << "In the book it said: 'Boa constrictors swallow their prey whole,\n";
        file << "without chewing it. After that they are not able to move, and they\n";
        file << "sleep through the six months that they need for digestion.'\n\n";
        file << "I pondered deeply, then, over the adventures of the jungle. And\n";
        file << "after some work with a colored pencil I succeeded in making my\n";
        file << "first drawing. My Drawing Number One.\n\n";

        // Chapter 2
        file << "Chapter 2\n\n";
        file << "I lived my life alone, without anyone that I could really talk to,\n";
        file << "until I had an accident with my plane in the Desert of Sahara, six years ago.\n";
        file << "Something was broken in my engine. And as I had with me neither a mechanic\n";
        file << "nor any passengers, I set myself to attempt the difficult repairs all alone.\n\n";
        file << "It was a question of life or death for me: I had barely enough drinking\n";
        file << "water to last eight days. The first night, then, I went to sleep on\n";
        file << "the sand, a thousand miles from any human habitation.\n\n";

        // Chapter 3
        file << "Chapter 3\n\n";
        file << "It took me a long time to learn where he came from. The little prince,\n";
        file << "who asked me so many questions, never seemed to hear the ones I asked him.\n";
        file << "It was from words dropped by chance that, little by little,\n";
        file << "everything was revealed to me.\n\n";
        file << "When he saw my airplane for the first time, he asked:\n";
        file << "'What is that object?'\n";
        file << "'That is not an object. It flies. It is an airplane.'\n";
        file << "'Oh! You come from the sky then?'\n\n";

        // Chapter 4
        file << "Chapter 4\n\n";
        file << "I had thus learned a second fact of great importance:\n";
        file << "his planet of origin was scarcely any larger than a house!\n";
        file << "But that did not really surprise me much. I knew very well that in\n";
        file << "addition to the great planets such as Earth, Jupiter, Mars, Venus,\n";
        file << "there are also hundreds of others that are sometimes so small that\n";
        file << "one has a hard time seeing them through the telescope.\n\n";

        // Chapter 5
        file << "Chapter 5\n\n";
        file << "Each day I would learn something new about the planet, about the\n";
        file << "departure, about the journey. It would come very slowly, in the\n";
        file << "course of casual remarks. In this way I heard about the flowers.\n\n";
        file << "The little prince had watched very seriously as I unpacked my drawing\n";
        file << "materials. 'What are those?' he asked.\n";
        file << "'These are baobabs.'\n";
        file << "I had been working on my drawing of the baobabs.\n\n";

        // Chapter 6
        file << "Chapter 6\n\n";
        file << "Oh, little prince! Bit by bit I came to understand the secrets of your\n";
        file << "sad little life. For a long time you had found your only entertainment\n";
        file << "in the quiet pleasure of looking at the sunset. I learned that new\n";
        file << "detail on the morning of the fourth day, when you said to me:\n";
        file << "'I am very fond of sunsets. Come, let us go look at a sunset now.'\n\n";

        file.close();
        cout << "Sample book 'sample_book.txt' created successfully!\n";
    }
    else
    {
        cout << "Error creating sample book file!\n";
    }
}
void readBooksFromList()
{
    ifstream bookList("books.txt");
    if (!bookList.is_open())
    {
        cout << "Error: Could not open 'books.txt'.\n";
        return;
    }

    cout << "\nBooks listed in 'books.txt':\n";
    cout << "-----------------------------------------\n";
    string line;
    bool found = false;
    while (getline(bookList, line))
    {
        cout << line << endl;
        found = true;
    }
    if (!found)
    {
        cout << "No books found in 'books.txt'.\n";
    }

    cout << "-----------------------------------------\n";
    bookList.close();
}

int main()
{
    while (true)
    {
        cout << "===============================\n";
        cout << " Welcome to Online Library \n";
        cout << "===============================\n\n";
        cout << "1. See All Books Available in Library\n";
        cout << "2. Exit\n";
        cout << "Choice (1-2): ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Show books and then transition to main menu
            readBooksFromList();

            // Main menu
            while (true)
            {
                cout << "===============================\n";

                cout << "\n=== Book Reader Menu ===\n";
                cout << "===============================\n";

                cout << "===============================\n";

                cout << "1. Create sample book\n";
                cout << "===============================\n";

                cout << "===============================\n";
                cout << "2. Read a book\n";
                cout << "===============================\n";
                cout << "===============================\n";

                cout << "3. Delete a book\n";
                cout << "===============================\n";
                cout << "===============================\n";

                cout << "4. View all available books\n";
                cout << "===============================\n";

                cout << "===============================\n";
                cout << "5. read summary of any book\n";
                cout << "===============================\n";
                cout << "===============================\n";

                cout << "6. Exit to Welcome Menu\n";
                cout << "===============================\n";

                cout << "Choice (1-6): ";

                int mainChoice;
                cin >> mainChoice;

                switch (mainChoice)
                {
                case 1:
                    createSampleBook();
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                    break;

                case 2:
                {
                    string fileName;
                    cout << "===============================\n";
                    cout << "Enter file name to read (e.g., sample_book.txt): ";
                    cout << "===============================\n\n";
                    cin >> fileName;

                    readBook(fileName);
                    break;
                }

                case 3:
                {
                    string fileName;
                    cout << "Enter file name to delete (e.g., sample_book.txt): ";
                    cin >> fileName;
                    deleteBook(fileName);
                    cout << "Press Enter to continue...";
                    cin.ignore(); // if we dont use this then cin.get will not work bec it will have some garbage value
                    cin.get();    // to inout any number so unser than ssee the changes
                    break;
                }

                case 4:
                // all books in library
                    readBooksFromList();
                    break;

                case 5:
                {
                    string fileName;
                    cout << "===============================\n";
                    cout << "Enter file name to read summary of (e.g., sample_book_summary.txt): ";
                    cin >> fileName;
                    cout << "===============================\n\n";
                    readBook(fileName);
                    break;  
                }

                case 6:
                    break; // Exit inner while loop
                }
                if (mainChoice == 6)
                    break; // Exit to Welcome Menu
            }
            break;
        }

        case 2:
            cout << "Thank you for using the Online Library. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please enter 1 or 2.\n";
        }
    }

    return 0;
}
