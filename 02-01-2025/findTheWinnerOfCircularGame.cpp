/*
Brute Force:
Initialize a list of friends numbered from 1 to n.
Start from the first friend and count k friends, wrapping around the circle if needed.
The k-th friend is eliminated, and the next round begins with the friend immediately clockwise of the one who was eliminated.
Repeat this process until only one friend remains, and that friend is the winner.*/

/*
Optimally for Brute:
Its a Mathematical solution which works in Big O(n)
The Josephus problem has a well-known recursive solution, which can be expressed as:

For a base case with 1 person, the survivor is at index 0 (josephus(1, k) = 0).
For n people, the position of the survivor is recursively calculated as:

josephus(n,k)=(josephus(n−1,k)+k)%n
Where:

n is the number of people.
k is the step (the number of people to count before eliminating someone).
The above recurrence gives the position of the winner in 0-based indexing. After calculating the winner using the recurrence, we simply adjust the result to 1-based indexing by adding 1.*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;
        
        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i;
        }
        
        return winner + 1;
    }
};
