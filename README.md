Link to our wiki : [WIKI](https://github.com/suarezmanuel/Manikel/wiki)

<pre>

Multithreading bloom filter server, with proper error handling <br>

to compile with CMakeLists: <br>
  1. cmake -B build -S .  <br>
  2. cmake --build build
  <br>
  > The files will be created in a "build" folder <br>

the first user to connect will initialize the bloom filter,
client commands:

    1. initialize bloom:       (bloom_filter_size)   (hash_times)   (hash_times) .... (hash_times)  
    2. add to bloom:       1   (string_to_add)
    3. check if in bloom:  2   (string_to_check) 
  <br>
  > returns "true true" if a given string is blacklisted

</pre>
<br><br><br><br>
