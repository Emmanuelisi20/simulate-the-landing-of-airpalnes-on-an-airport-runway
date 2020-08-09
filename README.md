# simulate-the-landing-of-airpalnes-on-an-airport-runway


In this project, you'll be writing a simulation for a small airport that has one runway. There will be a queue of planes waiting to land and a queue of planes waiting to take off. Only one plane can use the runway at a time. All time is in minutes. Here are the assumptions:
All takeoffs take the same amount of time and all landings take the same amount of time (though these two times may be different).
Planes arrive for landing at random times, but with a specified probability of a plane arriving during any given minute.
Planes arrive for takeoff at random times, but with a specified probability of a plane arriving during any given minute.
Landings have priorities over takeoffs.
Planes arriving for landing have a random amount of fuel and they will crash if they do not land before they run out of fuel.
Planes in the takeoff and landing queue are ordered by time of arrival in the queue (FIFO).
The input to the program should be on the command line. So, for example, you can run the simulation by typing:

./airsim.exe 5 7 .5 .4 360 0 20
Input will be:
The amount of time needed for one plane to land
The amount of time needed for one plane to takeoff
The probability of a plane entering the landing queue in any given minute
The probability of a plane entering the takeoff queue in any given minute
The start time in minutes before midnight
The stop time in minutes before midnight
The maximum minutes until a plane waiting to land will crash
The output of the program will be:

Total simulation time
The number of planes that took off in the simulated time
The number of planes that landed in the simulated time
The number of planes that crashed because they ran out of fuel before they could land
The average time a plane spent in the takeoff queue
The average time a plane spent in the landing queue
When computing the average time, you should not include crashed planes. Crashed planes will be discovered when they are removed from the queue (so you don't need to continually examine all planes in the queue). At the end of the simulation, you should examine the landing queue to determine whether any planes have crashed and should include these planes in the total. The other planes left in the queue at the end of the simulation are ignored.
You'll need to use a queue ADT (called Queue) for the takeoff queue and the landing queue. These should be templated classes, implemented as linked lists. You may use the STL list (described in section 3.3) to implement the queue. You should also define a class called StatKeeper to keep track of statistics for output. I will give you a class called BoolSource and you should create objects of that class for both takeoff and landing. You should also create a Runway class. You will also need an Airplane class, which will serve as the Item type in the queues. For each class you create, you should create both a .h (interface) and .cpp (implementation).

Here is the pseudocode for your main program, which should be stored in airsim.cpp:

Parse the input (you need to check to make sure all arguments are there and print an appropriate error message if not)
Declare the objects (queues, statkeeper, the two bool_sources, and runway).
for (currentMinute=startTime; currentMinute > stopTime; --currentMinute)
Ask the landing BoolSource whether a new plane should enter queue. If yes, then create a plane and enter it into landing queue
Ask the takeoff BoolSource whether a new plane should enter queue. If yes, then create a plane and enter it into takeoff queue
If the runway is not busy
If there is a plane in the landing queue, check to see whether it has crashed. If it has, then tell the Statkeeper about it, remove it from the queue, and check for another plane. When you find one that hasn't crashed, compute waiting time and tell Statkeeper. Tell the Runway to start landing the plane. Remove the plane from the queue.
If there is no landing plane and there is a plane in the takeoff queue, compute waiting time and tell Statkeeper. Tell the Runway to start takeoff for the plane. Remove the plane from the queue.
Tell the Runway that a minute has passed
Examine the landing queue for crashed planes and include them in the total. Print the output.
After you have the program working and have run appropriate simulations, write a brief memo (1 page) to the Lunken Airport about whether they should add a new runway to their airport in the next year. We'll assume they only have one right now. In your report, you should discuss the assumptions you are making (time for takeoff, time for landing, time to run out of fuel, etc.) and what your simulations showed. Allow for growth in number of flights over the next year. A crude (but acceptable) way to determine whether an additional runway would help is to cut the probability of landings and takeoffs by .50 to simulate the addition of a new runway. You should include a copy of this report and hand it in with the project file. Also hand in a programming log that you keep as you work on the project. This log can just be a Word doc with an entry for each time you work on the project including date, time range, what you planned to do, what you did do, and why you stopped working. Also include any discoveries, questions, observations you make during the work session. Be honest on this -- there's no point to making up the data.

You should use good commenting style (described in grading document).

Zip the code (.h and .cpp only), Makefile, and report for this project and use Blackboard to hand in. I will set up a project 1 assignment for this purpose.

Extra credit opportunities
Be sure to let me know if you have done any of these.
Add a second runway and include those simulations in your report.
Add the ability for the airsim.exe user to specify the number of runways on the command line. Use these simulations in your report to let the airport know when they should add one, two, or three runways.
Make the landing and takeoff times random within a certain range. Include these assumptions in your report.
