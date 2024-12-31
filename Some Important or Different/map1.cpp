/*Say we have our map_name as m. Now we know that with the help of following syntaxes, m[keyName] or m.at("keyName"), we can access the value stored
corresponding to those keys. Now if we pass the key which is not present in the map, then using m.at("keyName") first will throw us an error because the key
doesn't exist, but if we use m[keyName] first, then although the key doesn't exist, but this syntax will lead to the creation of this key and value
corresponding to it will be 0 by default. And if we write m.at("keyName") after writing m[keyName] and try to print the values stored correspondingly, 
both will give 0 as the output. 

Hash codes and compressing functions are fundamental concepts in computer science, especially in data structures, cryptography, and algorithms. 
Here’s a breakdown of each concept:

Hash Code : 
A hash code is a fixed-size numerical or alphanumeric value generated from data of arbitrary size. 
Hash codes are used primarily to quickly look up data, verify data integrity, or map data to fixed-size storage locations (such as in hash tables).

Key Characteristics of Hash Codes:
Deterministic: The same input should always produce the same hash code.
Efficient: Generating the hash code should be computationally efficient.
Uniformity: The hash function should ideally distribute hash codes uniformly across the possible output values to minimize collisions 
(two inputs producing the same hash).
Fixed Size: Regardless of the input size, the hash code is typically a fixed length. For example, MD5 always produces a 128-bit hash.

Common Applications of Hash Codes:
Data Integrity: Hash codes help verify that data hasn’t been altered. For example, file checksums can confirm if a downloaded file is identical to the source.
Data Structures: Hash tables use hash codes to quickly find an item’s location.
Cryptography: Cryptographic hash functions (e.g., SHA-256) are used to secure data by creating unique digital fingerprints.

Hash Functions : 
A hash function generates hash codes by transforming input data into a hash code through mathematical operations. 
Examples include:
Modular Arithmetic: hash(x) = x % table_size
Polynomial Hashing: Common in rolling hash functions and Rabin-Karp string matching.

Compressing Functions : 
A compressing function is a specific type of hash function designed to compress a large amount of data into a smaller fixed size. 
Compressing functions are widely used in hash functions to handle large inputs by breaking them down, processing them iteratively, 
and then combining results into a single, fixed-length output.

Properties of Compressing Functions:
Fixed Output Size: Compresses data into a specific length, such as 128-bit or 256-bit.
Pre-image Resistance: For a cryptographic compressing function, given a hash output, it should be computationally infeasible to reconstruct the input.
Collision Resistance: It should be hard to find two different inputs that produce the same output.
Avalanche Effect: Small changes in the input drastically change the output, ensuring no predictable pattern in hash values for similar inputs.

Differences Between Hash Functions and Compressing Functions : 
Scope: A hash function can transform data into a hash code and may or may not compress data. 
A compressing function always compresses input data to a fixed size.
Use Case: Hash functions are for general purposes (e.g., indexing, checksums), 
while compressing functions are crucial in cryptographic hash functions to secure data integrity and authenticity.

Practical Use Cases in Computer Science : 
Hash Tables: Using hash functions to map keys to indices in an array.
Cryptographic Applications: Protecting data integrity and security using secure hash algorithms.
Checksum and Data Verification: Hashing files to check for corruption or unauthorized changes.
Data Compression: Compressing data to fixed-size outputs for efficient storage and retrieval.


A collision in the context of hash functions and compressing functions occurs when two distinct inputs produce the same hash code or compressed output. 
In other words, a collision happens when:
hash(input1) = hash(input2) and input1 ≠ input2

Why Collisions Happen :
Hash functions map data of arbitrary size to a fixed-size output, 
meaning there are a limited number of possible hash codes but an infinite number of possible inputs. 
This difference makes collisions inevitable for any hash function if enough inputs are processed.

Types of Collisions : 
Simple Collision: Any two different inputs that produce the same hash output.
Birthday Collision: Based on the birthday paradox in probability theory, this type of collision exploits the fact that with a hash function of size n, 
there’s a high probability of finding two inputs with the same hash after roughly square root of (2 to the power n)
inputs, rather than 2^n inputs. This is relevant for cryptographic hash functions.
Cryptographic Collision: Specifically, a collision where a hash function fails to prevent an adversary from finding two different inputs with the same hash, 
compromising data integrity.

Why Collisions Are a Problem : 
Hash Tables: In hash tables, collisions lead to multiple values mapping to the same index. 
This increases retrieval time because the table has to handle several values at one location, 
often using techniques like chaining or open addressing to manage the data.
Data Integrity and Security: In cryptographic applications, a collision can be a major security vulnerability. 
If an attacker finds two inputs that produce the same hash, they could potentially substitute one input for the other without detection. 
This is why cryptographic hash functions like SHA-256 aim to be collision-resistant, 
making it computationally infeasible to find two different inputs with the same hash.

Collision Resistance : 
For a hash function, collision resistance is the property that makes it difficult to find two distinct inputs with the same output. 
Although it’s theoretically impossible to eliminate collisions entirely due to the pigeonhole principle, 
a good hash function minimizes the probability of collisions and makes finding them computationally infeasible.

Methods for Handling Collisions in Hash Tables : 
Chaining: Store colliding elements in a linked list at the index where the collision occurred.
Open Addressing: Use probing to find another empty slot in the table (e.g., linear probing, quadratic probing, or double hashing).
Resizing and Rehashing: Increase the hash table size and recalculate hash values, spreading data across a larger array.
Example of a Collision
Suppose we have a hash function hash(x) = x % 10. If we hash the numbers 15 and 25, both yield a hash code of 5, despite being different values:

hash(15) = 15 % 10 = 5
hash(25) = 25 % 10 = 5
This is a simple collision due to the limited output range of the function. */