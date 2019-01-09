CSCI 103 Zombies Programming Assignment 

Name: Samuel Lee

Email Address: lee344@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

:CPs on monday and tuesday. Discussion with peers. 

================================ Questions ==================================

1. Which kind of a loop did you use to iterate through the nights of a
   single simulation?  Why?
   
: I used a while loop because I didn't know how many nights it would take 
  for all the humans to turn into zombies. 

2. Which kind of a loop did you use to perform the M simulations? Why?

  
: I used a for loop because I would know from the user input how many times
  to iterate the simulation. 


3. How did you ensure that if a human was turned into a zombie on a
   particular night that he/she didn't bite anyone until the following
   night?

: I ensured this by using a for loop that only allowed as many bites 
   as there were zombies on that particular day. 


4. Experiment briefly running your program with fewer simulations 
   (smaller M value). One thing computer scientists do often is evaluate 
   trade-offs. Running with a smaller M results in some interesting 
   trade-offs: your program output three values, Average Nights, Max Nights 
   and Min Nights. How will these values be impacted by running fewer 
   simulations? On the other hand, what other property of your program is 
   affected by using a smaller M?

: The fewer the number of simulations, the more the three output values 
  (avg, max, min) converge to the same value. For instance, if only one 
  trial was done, they would all be the exact same. Thus, because max, min,
  and average would be representing a fewer number of instances, it would 
  be less accurate relative to the real life situation we are trying to 
  represent. 
  
  On the other hand, a smaller M would make the program run faster. 
  Using an excessively high amount of Ms would be ineffecient . 


================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:

Do you have any other remarks?

:
