CSCI 103 Twenty One Programming Assignment 

Name: Samuel Lee

Email Address: lee344@usc.ecu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

: CP's everyday (esp. owen) and professor goodney!

================================ Questions ==================================

1. Did you use the 'suit', 'type' and 'value' arrays? What functions are easie
to implement when using these arrays? How do you use them?

: I used suit and type. It made the print card function very easy. If the 
id came within a certain range of numbers,
I knows if it is an D, H, C, or S. I simply need to match it with the
appropriate array in suite[]. Likewise, if the id was in a certain range, 
you can know type. Simple adjust the id to match correct index on type. 

I did not use value. 

2. Did you add any additional functions to your implementation? If so briefly
describe how the functions improved your solution.

: no I did not. But if I did, it may have made my code a lot easier to read. 
For instance, I would have liked to use a void functions that couts whether
the player loses, wins, or ties, followed by the player's score and dealer's
score. It was pretty tedious to write them out for every situation. 

3. There are many ways to shuffle the deck of cards. The method used in our
implementation generates a permutaion of the cards to shuffle. For an array of
size N, how many swap (exchange) operations does this algorithm do? Does the
algorithm require any extra memory to generate a permutation?

: N-1 swaps. It does require extra memory to generate a permutation because
I used a a temporary variable while swapping. I must store the value of one 
the arrays so I dont loose it during theswap 



 
