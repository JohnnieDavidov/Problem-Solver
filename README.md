# Problem-Solver

This program created in Advance Programing course in Bar-Ilan University 2020.

crated by Zvi Arie Berger and Yonatan Davidov.

## Creators
Zvi Arie Berger

- **I.D** : 206126575
- **Submit name** : zviarib

Yonatan Davidov

- **I.D** : 308447234
- **Submit name** : davidoy5

## Description
This project handel eith client who gave search problem of matrix path.
the server manage a cache manager with sulution of problem who already solved and solver
for new problem.
the solver use A* algorithm to find fastest path to the goal state.

## Test Algorithm
to choose the nost powerfull algorithm we do test. we choose random 10 matrix beetween 10x10 to 50x50 and run all 4 algorithm 
(bfs, dfs, best first search. a*) and check who is the most faster and who return the lowest cost. all the deatails we show with graf in
pdf file graf.pdf

## Files
- main.cpp

### server and clinet files
- Server.h
- MySerialServer.h
- MySerialServer.cpp
- MyParallelServer.h
- MyParallelServer.cpp
- ClientHandler.h
- MyClientHsndler.h
- MyClientHsndler.cpp
- MyTestClientHandler.h
- MyTestClientHandler.cpp

### Cahe Manager Files
- CacheManager.h
- CacheManager.cpp
- FileCacheManager.h
- FileCacheManager.cpp

### Solver Files
- Solver.h
- StringReverser.h
- StringReverser.cpp
- ObjectAdapter.h
- ObjectAdapter.cpp

### searcher Files
- Searcher.h
- BFS.h
- DFS.h
- BestFirstSearch.h
- AStar.h

### Searchable Files
- Searcheable.h
- SearcheableMatrix.h
- SearcheableMatrix.cpp
- State.h
- Vertax.h
-Vertax.cpp

### Txt Files
- astar.txt
- bestfs.txt
- bfs.txt
- dfs.txt
- git_log.txt
- matrix.txt
- solve.txt

### PDF Files
- graf.pdf
## Links
- our github link https://github.com/BergerZvika/Problem-Solver.git
