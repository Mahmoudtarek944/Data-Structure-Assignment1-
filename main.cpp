#include "Book.h"
#include "BST.h"
#include "AVL.h"

void printSeparator(const string& title) {
    cout << "\n========================================\n";
    cout << "  " << title << "\n";
    cout << "========================================\n";
}

int main() {
    // ============================================================
    //  DATASETS
    // ============================================================
    vector<Book> randomBooks = {
        {101, "The Great Gatsby", "F. Scott Fitzgerald"},
        {55, "1984", "George Orwell"},
        {150, "Brave New World", "Aldous Huxley"},
        {30, "The Catcher in the Rye", "J.D. Salinger"},
        {75, "The Hobbit", "J.R.R. Tolkien"},
        {125, "Fahrenheit 451", "Ray Bradbury"},
        {200, "Moby Dick", "Herman Melville"},
        {10, "War and Peace", "Leo Tolstoy"},
        {45, "Crime and Punishment", "Fyodor Dostoevsky"},
        {65, "The Odyssey", "Homer"},
        {85, "The Divine Comedy", "Dante Alighieri"},
        {115, "Pride and Prejudice", "Jane Austen"},
        {140, "The Brothers Karamazov", "Fyodor Dostoevsky"},
        {160, "Ulysses", "James Joyce"},
        {210, "Don Quixote", "Miguel de Cervantes"},
        {5, "The Iliad", "Homer"},
        {25, "The Old Man and the Sea", "Ernest Hemingway"},
        {95, "Frankenstein", "Mary Shelley"},
        {110, "Dracula", "Bram Stoker"},
        {130, "Les Misérables", "Victor Hugo"}
    };

    vector<Book> sortedBooks = {
        {10, "The Selfish Gene", "Richard Dawkins"},
        {20, "Sapiens", "Yuval Noah Harari"},
        {30, "Guns, Germs, and Steel", "Jared Diamond"},
        {40, "Thinking, Fast and Slow", "Daniel Kahneman"},
        {50, "Brief Answers to the Big Questions", "Stephen Hawking"},
        {60, "The Elegant Universe", "Brian Greene"},
        {70, "The Sixth Extinction", "Elizabeth Kolbert"},
        {80, "Cosmos", "Carl Sagan"},
        {90, "The Gene", "Siddhartha Mukherjee"},
        {100, "Astrophysics for People in a Hurry", "Neil deGrasse Tyson"},
        {110, "The Emperor of All Maladies", "Siddhartha Mukherjee"},
        {120, "Quiet", "Susan Cain"},
        {130, "Outliers", "Malcolm Gladwell"},
        {140, "Atomic Habits", "James Clear"},
        {150, "Deep Work", "Cal Newport"},
        {160, "The Power of Habit", "Charles Duhigg"},
        {170, "Man's Search for Meaning", "Viktor Frankl"},
        {180, "The Alchemist", "Paulo Coelho"},
        {190, "Meditations", "Marcus Aurelius"},
        {200, "The Art of War", "Sun Tzu"}
    };

    // ============================================================
    //  BST BASIC TESTS
    // ============================================================
    printSeparator("BST BASIC TESTS");
    BST bst;
    bst.insert(50, "Data Structures", "Mahmed Tarel");
    bst.insert(30, "C++ Basics", "Ahmed Bahaa");
    bst.insert(70, "Algorithms", "Karem Ahmed");
    bst.insert(20, "Operating Systems", "Ramez Rizk");
    bst.insert(40, "Database Systems", "Osama Ahmed");
    bst.insert(60, "Computer Networks", "Yosef Aymen");
    bst.insert(80, "Artificial Intelligence", "Amr Atef");

    cout << "\n--- Inorder Traversal ---\n";
    bst.inorder();

    cout << "\nSearch 40: " << (bst.search(40) ? "Found" : "Not Found");
    cout << "\nSearch 100: " << (bst.search(100) ? "Found" : "Not Found");

    bst.rangeSearch(35, 65);
    bst.closest(42);

    cout << "\n--- Deletes ---\n";
    bst.searchDeletedNode(20); // leaf
    cout << "After deleting 20:\n"; bst.inorder();

    bst.searchDeletedNode(30); // one child
    cout << "\nAfter deleting 30:\n"; bst.inorder();

    bst.searchDeletedNode(70); // two children
    cout << "\nAfter deleting 70:\n"; bst.inorder();

    bst.searchDeletedNode(50); // root
    cout << "\nAfter deleting 50:\n"; bst.inorder();

    // ============================================================
    //  AVL BASIC TESTS
    // ============================================================
    printSeparator("AVL BASIC TESTS");
    AVL avl;
    for (const auto& b : randomBooks)
        avl.insert(b.id, b.title, b.author);

    cout << "\n--- Inorder Traversal ---\n";
    avl.inorder();

    int steps = 0;
    cout << "\nSearch 45: ";
    if (avl.search(45, steps)) cout << "Found (steps: " << steps << ")";
    else cout << "Not Found";

    cout << "\nSearch 100: ";
    if (avl.search(100, steps)) cout << "Found (steps: " << steps << ")";
    else cout << "Not Found (steps: " << steps << ")";

    avl.rangeSearch(50, 120);
    avl.closest(100);
    avl.closest(42);

    cout << "\n--- Deletes ---\n";
    avl.remove(5);  cout << "After deleting 5:\n";  avl.inorder();
    avl.remove(10); cout << "\nAfter deleting 10:\n"; avl.inorder();
    avl.remove(75); cout << "\nAfter deleting 75:\n"; avl.inorder();
    avl.remove(55); cout << "\nAfter deleting 55:\n"; avl.inorder();

    // ============================================================
    //  PART 4: COMPARISON
    // ============================================================
    printSeparator("PART 4: BST vs AVL COMPARISON");

    // --- Random IDs ---
    BST bstRandom;
    AVL avlRandom;
    for (const auto& b : randomBooks) {
        bstRandom.insert(b.id, b.title, b.author);
        avlRandom.insert(b.id, b.title, b.author);
    }

    cout << "\n--- RANDOM IDs ---\n";
    cout << "BST Height: " << bstRandom.height() << "\n";
    cout << "AVL Height: " << avlRandom.height() << "\n";

    int bstSteps, avlSteps;
    bstRandom.search(95, bstSteps);
    avlRandom.search(95, avlSteps);
    cout << "Search for 95 -> BST steps: " << bstSteps << ", AVL steps: " << avlSteps << "\n";

    // --- Sorted IDs ---
    BST bstSorted;
    AVL avlSorted;
    for (const auto& b : sortedBooks) {
        bstSorted.insert(b.id, b.title, b.author);
        avlSorted.insert(b.id, b.title, b.author);
    }

    cout << "\n--- SORTED IDs ---\n";
    cout << "BST Height: " << bstSorted.height() << "\n";
    cout << "AVL Height: " << avlSorted.height() << "\n";

    bstSorted.search(95, bstSteps);
    avlSorted.search(95, avlSteps);
    cout << "Search for 95 -> BST steps: " << bstSteps << ", AVL steps: " << avlSteps << "\n";

    cout << "\n";
    return 0;
}