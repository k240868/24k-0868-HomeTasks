#include <iostream>
using namespace std;

class ResearchPaper
{
    string *authors;
    int n;

public:
    ResearchPaper(int num = 0)
    {
        n = num;
        if (n > 0)
            authors = new string[n];
        else
            authors = NULL;
    }

    ~ResearchPaper()
    {
        delete[] authors;
    }

    ResearchPaper(const ResearchPaper &r)
    {
        n = r.n;
        if (n > 0)
        {
            authors = new string[n];
            for (int i = 0; i < n; i++)
                authors[i] = r.authors[i];
        }
        else
        {
            authors = NULL;
        }
    }

    ResearchPaper &operator=(const ResearchPaper &r)
    {
        if (this != &r)
        {
            delete[] authors;
            n = r.n;
            if (n > 0)
            {
                authors = new string[n];
                for (int i = 0; i < n; i++)
                    authors[i] = r.authors[i];
            }
            else
            {
                authors = NULL;
            }
        }
        return *this;
    }

    void setAuthor(int i, string name)
    {
        if (i >= 0 && i < n)
            authors[i] = name;
    }

    void show()
    {
        cout << "Authors: ";
        for (int i = 0; i < n; i++)
        {
            cout << authors[i];
            if (i != n - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

int main()
{
    ResearchPaper p1(2);
    p1.setAuthor(0, "Ali");
    p1.setAuthor(1, "Bilal");
    cout << "Paper1 -> ";
    p1.show();

    ResearchPaper p2 = p1;
    cout << "Paper2 (copied) -> ";
    p2.show();

    p2.setAuthor(0, "Sara");
    cout << "\nAfter changing Paper2:\n";
    cout << "Paper1 -> ";
    p1.show();
    cout << "Paper2 -> ";
    p2.show();

    ResearchPaper p3(1);
    p3.setAuthor(0, "Usman");
    cout << "\nPaper3 before assignment -> ";
    p3.show();

    p3 = p1;
    cout << "Paper3 after assignment -> ";
    p3.show();

    return 0;
}

