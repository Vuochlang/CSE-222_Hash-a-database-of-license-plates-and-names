# CSE-222-Introduction-to-Data-Structure
# Programming Assignment: Hash-a-database-of-license-plates-and-names

_ In C, this is a program that can hash a database of license plates and names. 

_ After reading in a  file containing plate/name pairs, the program will let the user enter a license plate, and it will display the corresponding name. 

_ The user can also enter commands instead of a license plate, in order to examine the internal data structure of the hash table.

# Start up:

The executable program named plate and can be run in one of two ways:

      _ plate database_name : it will read the plate information from database_name and save it in a hash table of size 100;
      
      _ plate database_name hash_table_size : it will lets the user to specify the size of the hash table (must be an integer >=1)
      
# User interaction:

User can interact with the program by typing:
    
    *DUMP-----to see all the data in the hashTable
    
    *DUMP n---to see the data in the hashTable at the index(n)
    
    *LOAD-----to see the legnth of each hashTable
    
    (PLATE)---to see the owner of the plate(PLATE)
