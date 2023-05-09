/** @file main.cpp * /
* @author Valerie Williams
* @date 4/23/2023
* @version 1
* Loads packet data from a file and calculates their size in megabits + how long it
* takes to transfer the packets over a 90mb/s network.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include "MaxHeapArray.h"
#include "Packet.h"

using namespace std;

int main(int argc, char const *argv[])
{
    
    // declare necessary variables
    MaxHeapArray<Packet> packetHeap;
    fstream myFile;
    string toRead;
    

    // create packets from the data in the file
    // open the file
    myFile.open("packets1.txt");

    // loop through the file
    while (!myFile.eof())
    {

        getline(myFile, toRead);

        if (!toRead.empty())
        {

            // create the packet
            Packet currentPacket(toRead);

            // add it to the priority queue
            packetHeap.add(currentPacket);

        }

    }

    // print the current state of the heap
    //packetHeap.printHeap();

    // close the file, we don't need it right now
    myFile.close();

    // initialize counter variables 
    // priority levels
    int priority0 = 0;
    int priority1 = 0;
    int priority2 = 0;
    int priority3 = 0;
    int priority4 = 0;
    int priority5 = 0;
    int priority6 = 0;
    int priority7 = 0;

    // time counts
    double totalTime = 0.0;
    double level0_time = 0.0;
    double level1_time = 0.0;
    double level2_time = 0.0;
    double level3_time = 0.0;
    double level4_time = 0.0;
    double level5_time = 0.0;
    double level6_time = 0.0;
    double level7_time = 0.0;

    // initialize variables needed to go through the queue and perform operations
    Packet currentPacket;
    int size = packetHeap.getItemCount();

    cout << "Testing time with Priority Queue" << endl;

    // goes through the whole priority queue
    for (int i = 0; i < size; i++)
    {
        // reset the megabits and time counter variables for each packet in the queue
        double megabits = 0;
        double time = 0;

        // Convert to megabits
        currentPacket = packetHeap.peek();
        megabits = (currentPacket.getSize()*8);
        packetHeap.remove();

        // Calculate time (90mb/s network)
        time = megabits/90;

        // Display megabits and time
        cout << megabits <<  " megabits transferred in " << time << " seconds from a packet with priority " << currentPacket.getPriority() << endl;

        // Add it to the total time
        totalTime += time;

        // update priority level details
        if (currentPacket.getPriority() == 0)
        {
            level0_time = level0_time + time;
            priority0++;
        }

        else if (currentPacket.getPriority() == 1)
        {
            level1_time += time;
            priority1++;
        }

        else if (currentPacket.getPriority() == 2)
        {
            level2_time += time;
            priority2++;
        }

        else if (currentPacket.getPriority() == 3)
        {
            level3_time += time;
            priority3++;
        }

        else if (currentPacket.getPriority() == 4)
        {
            level4_time += time;
            priority4++;
        }

        else if (currentPacket.getPriority() == 5)
        {
            level5_time += time;
            priority5++;
        }

        else if (currentPacket.getPriority() == 6)
        {
            level6_time += time;
            priority6++;
        }

        else if (currentPacket.getPriority() == 7)
        {
            level7_time += time;
            priority7++;
        }

    } // end if

    // display the results
    cout << "------" << endl;

    cout << "\rTIME STATS" << endl;
    cout << "Total time for all packets: " << totalTime << " seconds" << endl;
    cout << "Time for level 0: " << level0_time << " seconds" << endl;
    cout << "Time for level 1: " << level1_time << " seconds" << endl;
    cout << "Time for level 2: " << level2_time << " seconds" << endl;
    cout << "Time for level 3: " << level3_time << " seconds" << endl;
    cout << "Time for level 4: " << level4_time << " seconds" << endl;
    cout << "Time for level 5: " << level5_time << " seconds" << endl;
    cout << "Time for level 6: " << level6_time << " seconds" << endl;
    cout << "Time for level 7: " << level7_time << " seconds" << endl;

    cout << " " << endl;

    cout << "TOTAL PACKETS BY PRIORITY LEVEL" << endl;
    cout << "Level 0: " << priority0 << " packets" << endl;
    cout << "Level 1: " << priority1 << " packets" << endl;
    cout << "Level 2: " << priority2 << " packets" << endl;
    cout << "Level 3: " << priority3 << " packets" << endl;
    cout << "Level 4: " << priority4 << " packets" << endl;
    cout << "Level 5: " << priority5 << " packets" << endl;
    cout << "Level 6: " << priority6 << " packets" << endl;
    cout << "Level 7: " << priority7 << " packets" << endl;

    cout << " " << endl;

    cout << "Testing time using a normal queue" << endl;

    // reset the counters
    priority0 = 0;
    priority1 = 0;
    priority2 = 0;
    priority3 = 0;
    priority4 = 0;
    priority5 = 0;
    priority6 = 0;
    priority7 = 0;

    totalTime = 0.0;
    level0_time = 0.0;
    level1_time = 0.0;
    level2_time = 0.0;
    level3_time = 0.0;
    level4_time = 0.0;
    level5_time = 0.0;
    level6_time = 0.0;
    level7_time = 0.0;

    // create a normal queue
    queue<Packet> packets2;
    size = 0;

    // load data from the file into the normal queue (in the order they appear in the file)
    
    // open the file again
    myFile.open("packets1.txt");

    // loop through the file
    // create packets from the data in the file and add to queue
    while (!myFile.eof())
    {

        getline(myFile, toRead);

        if (!toRead.empty())
        {

            // create the packet
            Packet currentPacket(toRead);

            // add it to the normal queue
            packets2.push(currentPacket);

            // update the counter of size of the normal queue
            size++;

        }

    }

    // goes through the whole normal queue
    for (int i = 0; i < size; i++)
    {
        // reset the megabits and time counter variables for each packet in the queue
        double megabits = 0;
        double time = 0;

        // get the current packet from the front of the queue
        currentPacket = packets2.front();

        // pop
        packets2.pop();

        // Convert to megabits
        megabits = (currentPacket.getSize()*8);

        // Calculate time (90mb/s network)
        time = megabits/90;

        // Display megabits and time
        cout << megabits <<  " megabits transferred in " << time << " seconds from a packet with priority " << currentPacket.getPriority() << endl;

        // Add it to the total time
        totalTime += time;

        // update priority level details
        if (currentPacket.getPriority() == 0)
        {
            level0_time += time;
            priority0++;
        }

        else if (currentPacket.getPriority() == 1)
        {
            level1_time += time;
            priority1++;
        }

        else if (currentPacket.getPriority() == 2)
        {
            level2_time += time;
            priority2++;
        }

        else if (currentPacket.getPriority() == 3)
        {
            level3_time += time;
            priority3++;
        }

        else if (currentPacket.getPriority() == 4)
        {
            level4_time += time;
            priority4++;
        }

        else if (currentPacket.getPriority() == 5)
        {
            level5_time += time;
            priority5++;
        }

        else if (currentPacket.getPriority() == 6)
        {
            level6_time += time;
            priority6++;
        }

        else if (currentPacket.getPriority() == 7)
        {
            level7_time += time;
            priority7++;
        }

    } // end if

    // display the results
    cout << "------" << endl;

    cout << "\rTIME STATS" << endl;
    cout << "Total time for all packets: " << totalTime << " seconds" << endl;
    cout << "Time for level 0: " << level0_time << " seconds" << endl;
    cout << "Time for level 1: " << level1_time << " seconds" << endl;
    cout << "Time for level 2: " << level2_time << " seconds" << endl;
    cout << "Time for level 3: " << level3_time << " seconds" << endl;
    cout << "Time for level 4: " << level4_time << " seconds" << endl;
    cout << "Time for level 5: " << level5_time << " seconds" << endl;
    cout << "Time for level 6: " << level6_time << " seconds" << endl;
    cout << "Time for level 7: " << level7_time << " seconds" << endl;

    cout << " " << endl;

    cout << "TOTAL PACKETS BY PRIORITY LEVEL" << endl;
    cout << "Level 0: " << priority0 << " packets" << endl;
    cout << "Level 1: " << priority1 << " packets" << endl;
    cout << "Level 2: " << priority2 << " packets" << endl;
    cout << "Level 3: " << priority3 << " packets" << endl;
    cout << "Level 4: " << priority4 << " packets" << endl;
    cout << "Level 5: " << priority5 << " packets" << endl;
    cout << "Level 6: " << priority6 << " packets" << endl;
    cout << "Level 7: " << priority7 << " packets" << endl;


    return 0;

}


