/*
There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

 

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
Example 2:

Input: customers = [1], grumpy = [0], minutes = 1
Output: 1
 

Constraints:

n == customers.length == grumpy.length
1 <= minutes <= n <= 2 * 104
0 <= customers[i] <= 1000
grumpy[i] is either 0 or 1.
*/




//First Solution 75/78 test cases passed time limit exceeded
class Solution {
public:
    int change_minutes_window(vector<int>& grumpy,vector<int>& customers)
    {
        int possible_result=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i] !=1)
            {
                possible_result+=customers[i];
            }
        }
        return possible_result;
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> grumpy_change;
        vector <int> result;
        for(int i=0;i<grumpy.size();i++)
        {
            grumpy_change.push_back(grumpy[i]);
        }
        for(int j=0;j<grumpy.size();j++)
        {
            for(int i=j;i<j+minutes &&i<grumpy_change.size();i++)
            {
                grumpy_change[i]=0;
            }
            result.push_back(change_minutes_window(grumpy_change,customers));
            grumpy_change=grumpy;

        }
        int max=0;
        for(int i=0;i<result.size();i++)
        {
            if(result[i]>max)
            max=result[i];
        cout<<result[i]<<" ";
        }
      
        return max;
    }
};

//Second Solution Accepted one 
class Solution {
public:
    int change_minutes_window(vector<int>& grumpy,vector<int>& customers)
    {
        int possible_result=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i] !=1)
            {
                possible_result+=customers[i];
            }
        }
        return possible_result;
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int all_satisfied=0;
        for(int i=0;i<customers.size();i++)
        {   if(grumpy[i]!=1)
            all_satisfied+=customers[i];
        }
        int extra_satisfied=0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)
            {
                extra_satisfied+=customers[i];
            }
        }
        int max_satisfied=extra_satisfied;
        for(int i=minutes;i<customers.size();i++)
        {
            if(grumpy[i]==1)
            {
                extra_satisfied+=customers[i];
            }
            if(grumpy[i-minutes]==1)
            {
                extra_satisfied-=customers[i-minutes];
            }
            max_satisfied=max(max_satisfied,extra_satisfied);


        }
        return max_satisfied+all_satisfied;

    }
       
};