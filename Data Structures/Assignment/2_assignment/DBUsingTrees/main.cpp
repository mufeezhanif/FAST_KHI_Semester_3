#include <bits/stdc++.h>
#include "BST.h"
#include "AVL.h"
#include "BTree.h"

using namespace std;

vector<int> ids(50000);
vector<string> names(50000);
vector<int> ages(50000);

void generateData()
{
    for (int i = 0; i < 50000; ++i)
    {
        ids[i] = i + 20;
        names[i] = "Person " + to_string(i + 1);
        ages[i] = (i + 18) % 100 + 1;
    }
}

void printHeader(const string& TypeOfTree)
{
    cout << "\n"
         << TypeOfTree << " Performance Results (time in milliseconds):\n";
    cout << setw(10) << "DataSize"
         << setw(15) << "Insert"
         << setw(15) << "Search"
         << setw(15) << "Delete" << endl;
    cout << string(70, '-') << endl;
}

void calcPerformanceOfBST(BST *bst, int dataSize)
{
    // Insert
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < dataSize; ++i)
    {
        bst->insert(ids[i], names[i], ages[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    double insert_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    // Search
    vector<int> searchids = {560, 235, 79, 562, 120, 100, 48, 986, 235, 941, 23, 458, 123, 459, 785, 1004, 896, 234, 150, 123};
    if (dataSize == 10000)
    {
        for (int i = 0; i < 20; ++i)
        {
            searchids[i] += 5000 + i;
        }
    }
    else if (dataSize == 50000)
    {
        for (int i = 0; i < 20; ++i)
        {
            searchids[i] += 12000 + (i * 2);
        }
    }
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20; ++i)
    {
        bst->findEntry(searchids[i]);
    }
    end = chrono::high_resolution_clock::now();
    double search_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    // Delete
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20; ++i)
    {
        bst->deleteVal(searchids[i]);
    }
    end = chrono::high_resolution_clock::now();
    double delete_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    cout << setw(10) << dataSize
         << setw(15) << fixed << setprecision(3) << insert_time
         << setw(15) << search_time
         << setw(15) << delete_time << endl;
}

void calcPerformanceOfAVL(AVL *avl, int dataSize)
{
    // Insert
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < dataSize; ++i)
    {
        avl->insertData(ids[i], names[i], ages[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    double insert_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    // Search
    vector<int> searchids = {560, 235, 79, 562, 120, 100, 48, 986, 235, 941, 23, 458, 123, 459, 785, 1004, 896, 234, 150, 123};
    if (dataSize == 10000)
    {
        for (int i = 0; i < 20; ++i)
        {
            searchids[i] += 5000 + i;
        }
    }
    else if (dataSize == 50000)
    {
        for (int i = 0; i < 20; ++i)
        {
            searchids[i] += 12000 + (i * 2);
        }
    }
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20; ++i)
    {
        avl->search(searchids[i]);
    }
    end = chrono::high_resolution_clock::now();
    double search_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    // Delete
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20; ++i)
    {
        avl->DeleteEntry(searchids[i]);
    }
    end = chrono::high_resolution_clock::now();
    double delete_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    cout << setw(10) << dataSize
         << setw(15) << fixed << setprecision(3) << insert_time
         << setw(15) << search_time
         << setw(15) << delete_time << endl;
}

void calcPerformanceOfBTree(BTree *btree, int dataSize)
{
    // Insert
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < dataSize; ++i)
    {
        btree->insert(ids[i], names[i], ages[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    double insert_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    // Search
    vector<int> searchids = {560, 235, 79, 562, 120, 100, 48, 986, 235, 941, 23, 458, 123, 459, 785, 1004, 896, 234, 150, 123};
    if (dataSize == 10000)
    {
        for (int i = 0; i < 20; ++i)
        {
            searchids[i] += 5000 + i;
        }
    }
    else if (dataSize == 50000)
    {
        for (int i = 0; i < 20; ++i)
        {
            searchids[i] += 12000 + (i * 2);
        }
    }
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20; ++i)
    {
        btree->search_btree(searchids[i]);
    }
    end = chrono::high_resolution_clock::now();
    double search_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    cout << setw(10) << dataSize
         << setw(15) << fixed << setprecision(3) << insert_time
         << setw(15) << search_time
         << setw(15) << "-" << endl;
}

int main()
{
    BST *bst = new BST();
    AVL *avl = new AVL();
    BTree *btree = new BTree(4);

    generateData();
    // cout << "Dataset created successfully:\n";
    // for (int i = 49999; i >= 49900; --i)
    // {
    //     cout << ids[i] << " " << names[i] << " " << ages[i] << endl;
    // }

    // BST Performance
    printHeader("BST");
    calcPerformanceOfBST(bst, 1000);
    delete bst;
    bst = new BST();
    calcPerformanceOfBST(bst, 10000);

    delete bst;
    bst = new BST();
    calcPerformanceOfBST(bst, 50000);
    delete bst;

    // AVL Performance
    printHeader("AVL");
    calcPerformanceOfAVL(avl, 1000);
    calcPerformanceOfAVL(avl, 10000);
    calcPerformanceOfAVL(avl, 50000);
    delete avl;

    // BTree Performance
    printHeader("BTree");
    calcPerformanceOfBTree(btree, 1000);
    calcPerformanceOfBTree(btree, 10000);
    calcPerformanceOfBTree(btree, 50000);
    delete btree;

    return 0;
}
