# Reflection

## 1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

A LinkedList and an ArrayList do not store their data the same way. My concat code moves the existing nodes or array pointers directly, so the other list has to use the same representation. To combine different types, I would need to go through the second list one item at a time and add each item safely.

## 2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.

The three pointers I use are previous, current and next. I save next before changing current's link because that link is the only way to reach the rest of the list. If I lose one of these pointers, part of the list could become disconnected.

## 3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?

For addAnywhere, the position can be from 0 through the current size. For deleteAnywhere, it can be from 0 through size minus 1. If the position is outside that range, my code prints an error message and returns without changing the list.

## 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?

I had to walk to the end because concat attaches the second list after the last node. addFront and deleteFront only use the head, so they do not need to search through the list. A tail pointer would make concat faster, but I would have to update it whenever the last node changes or the list becomes empty.

## 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

For addAnywhere in ArrayList, the pointers after the chosen position have to move one spot to the right. I start at the end and move backward so I do not replace a pointer before moving it. If I shifted from left to right, I could overwrite data that I still need.

## 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.

The line that changes the direction is `tableOne->reverse();`. If this call was missing, the players would still print in the original order after the Reverse card. The scene would say that a Reverse card was played, but nothing would actually change.