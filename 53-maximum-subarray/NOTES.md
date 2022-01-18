IDEATION
Kadane’s Algorithm can be viewed both as a greedy and DP. As we can see
that we are keeping a running sum of integers and when it becomes less
than 0, we reset it to 0 (Greedy Part). This is because continuing with a
negative sum is way more worse than restarting with a new range. Now it
can also be viewed as a DP, at each stage we have 2 choices: Either take
the current element and continue with previous sum OR restart a new range.
These both choices are being taken care of in the implementation.
​