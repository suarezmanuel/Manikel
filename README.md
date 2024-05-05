# Manikel <br>

Our Implementation of a bloom filter as a first step in a project-driven course. <br>
Developed using Jira, Docker and in TDD fashion. <br>

The Bloomfilter:
First we implemented the tests as a part of the TDD so they would fit the project criteria. <br>
Then we implemented the logic of the bloom filter so the program will check all the tests. <br>
Lastly, we added more tests and improved the logic of the bloom filter. <br>

The github worflows:
We added the two required workflow. One that will check all the tests and the other that will upload our project to Dockehub. <br>

<pre>
to compile with CMakeLists: 

  1. cmake -B build -S .  

  2. cmake --build build
  
  > The files will be created in a "build" folder named "Main"
  
  To run the file just execute: ./build/Main

  To run the tests run: ctest --test-dir build --output-on-failure
</pre>
