//Programmer: Phillip LaFrance	//Student ID: 12398940
//Intructor: Patrick Taylor		//Section: A		//Date: 03/19/2018
//File: BigInteger.cpp			//Description: Defines functions for BigInteger.h

/* Sample tester
 * We've included std::list below to show you how your types should behave.
 * You can use that for debugging.
 * As in the assignment description, if you use the std::list for your submitted code,
 * you will get a 0.
 * Compile with g++ pa05.cpp BigInteger.cpp -std=c++11
 * Add the -g flag if you want to use GDB like we learned in lab this week.
 */

// USE THIS TO TEST, BUT REMOVE LATER
//#include <list>

#include "BigInteger.h"
#include "MyList.h"

int main()
{

    // Make your hpp file with empty definitions other than your constructor
    // Build one function at a time, and only add one "test" line at a time to this file.
    MyList<int> l;
    //std::list<int> l;

    // Uncommend and add lines below here 1 at a time!

    // Test all your MyList functions here:
    cout << "list size: " << l.size() << endl;
    cout << "Is list empty? ";
    if(l.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    l.push_back(4000);
    cout << "push_back 4000" << endl;
    l.push_back(200);
    cout << "push_back 200" << endl;
    l.push_back(100);
    cout << "push_back 100" << endl;
    l.push_back(50);
    cout << "push_back 50" << endl;
    cout << "list size: " << l.size() << endl;
    l.insert(3, 10);
    cout << "'10' inserted at position 3 of list" << endl;
    cout << "list size: " << l.size() << endl;
    l.erase(3);
    cout << "value at position 3 removed from list" << endl;
    cout << "list size: " << l.size() << endl;
    cout << "FRONT: " << l.front() << endl;
    //l.insert(l.end(), 66);
    cout << "BACK: " << l.back() << endl;
    l.reverse();
    cout << "reverse list" << endl;
    cout << "FRONT: " << l.front() << endl;
    cout << "BACK: " << l.back() << endl;

    cout << "\nDoubly List (back first):" << endl;
    int sizz = l.size();
    for(auto i = 0; i < sizz; i++)
    {
        cout << l.back() << endl;
        l.pop_back();
    }
    cout << "list size: " << l.size() << endl << endl;
    l.assign(6, 70);
    cout << "assign '70' to first 6 positions of list" << endl;
    l.resize(10);
    cout << "resize list to 10" << endl << endl;

    MyList<int> sink;
    sink = l;
    cout << "copy list to new list" << endl;
    //l.push_front(123);

    cout << "FRONT: " << sink.front() << endl;
    cout << "BACK: " << sink.back() << endl;

    cout << "\nDoubly New List (back first):" << endl;
    int siz = sink.size();
    for(auto i = 0; i < siz; i++)
    {
        cout << sink.back() << endl;
        sink.pop_back();
        //cout << "pop_back complete" << endl;
        //cout << "new list size: " << sink.size() << endl;
    }
    cout << "new list size: " << sink.size() << endl << endl;


    l.push_front(423);
    cout << "list push_front 423" << endl;
    cout << "list FRONT: " << l.front() << endl;

/*
    MyList<int> sink;
    sink = l;
    cout << "sink created" << endl;
    cout << "FRONT: " << sink.front() << endl;
    cout << "BACK: " << sink.back() << endl;

    l.insert(l.begin(), 3);
    l.insert(l.end(), 20);
    l.reverse();

    int size1 = l.size();
    int j = 0;
    for(auto i = 0; i < size1 ; i++)
    {
        cout << l.back() << endl;
        l.pop_back();
        j++;
    }
*/
    // Test all your BigInteger functions here:
    cout << endl << "START BIGINTEGER TESTING" << endl;

    std::string init_string("2342323492423");
    std::string my_big_int1_string = "36";
    std::string my_big_int2_string = "6";
    std::string my_big_int_final_string = "100";
    BigInteger my_big_int1(my_big_int1_string);
    BigInteger my_big_int2(my_big_int2_string);
    BigInteger my_big_int_final(my_big_int_final_string);
    long long power = 5;

    cout << "my_big_int1: " << my_big_int1_string << endl;
    cout << "Is my_big_int1 prime? ";
    if(my_big_int1.is_prime())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    my_big_int_final = my_big_int1 + my_big_int2;
    cout << my_big_int1_string << " + " << my_big_int2_string << "\n";
    cout << "my_big_int_final for +: " << my_big_int_final.to_string() << endl;

    my_big_int_final = my_big_int1 - my_big_int2;
    cout << my_big_int1_string << " - " << my_big_int2_string << "\n";
    cout << "my_big_int_final for -: " << my_big_int_final.to_string() << endl;

    my_big_int_final = my_big_int1 * my_big_int2;
    cout << my_big_int1_string << " * " << my_big_int2_string << "\n";
    cout << "my_big_int_final for *: " << my_big_int_final.to_string() << endl;

    my_big_int_final = my_big_int1 / my_big_int2;
    cout << my_big_int1_string << " / " << my_big_int2_string << "\n";
    cout << "my_big_int_final for /: " << my_big_int_final.to_string() << endl;

    my_big_int_final = gcd(my_big_int1, my_big_int2);
    cout << "gcd of " << my_big_int1_string << " & " << my_big_int2_string << "\n";
    cout << "my_big_int_final for gcd: " << my_big_int_final.to_string() << endl;

    my_big_int_final = gefficient_exp(my_big_int1, power);
    cout << my_big_int1_string << " ^ " << power << "\n";
    cout << "my_big_int_final for gefficient_exp: " << my_big_int_final.to_string() << endl;
    //cout << "complete" << endl;
    return 0;
}

