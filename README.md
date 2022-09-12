# List_catalog
Assignment for Structure Data subject. A C++ code that used to store and sort words into 7 buckets based on initial letters.

## Detail
This is a small script for user to enter words, and place the word into different buckets based on initial letter of that word. Overall there are 7 buckets, range from 0 ~ 6. When a new word was inserted, the ASCII value of its initial letter will be taken to decide which bucket it belongs.

For example, a word "Covid-19" has "C" as initial letter, "C" ASCII value is 67. Since there are 7 buckets, 67 % 7 = 4, hence the word "Covid-19" will be insert in bucket 4.

Based on this rule, "Disease" will be in bucket 5, "Ear" in bucket 6, "Flu" in bucket 0.

When there are multiple words in same bucket, the word that insert earlier will be in front (since it is a list), for example, if user enter "Physics", follow by "Pandemic", bucket 3 will contain "Physics   Pandemic". User is able to sort the words within bucket again. By using function sort(), all bucket will sort inputs alphabetically (after sorting, bucket 3 become "Pandemic  Physics")

### There are 7 functions in this script:
- menu(): User selection option
- hash(): Create an emtpy table with size 7
- push(): Add a new word 
- sort(): Sort the words alphabetically 
- search(): Search a word in the catalog
- show(): Display the list of words in the catalog
- delcat(): Delete a word from the catalog