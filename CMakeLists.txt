cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 main.cpp Server.h ClientHandler.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h FileCacheManager.cpp FileCacheManager.h CacheManager.cpp CacheManager.h StringReverser.cpp StringReverser.h MyClientHandler.cpp MyClientHandler.h ObjectAdapter.cpp ObjectAdapter.h MyParallelServer.cpp MyParallelServer.h Searcher.h Vertax.cpp Vertax.h State.h SearcheableMatrix.cpp SearcheableMatrix.h Searcheable.h BestFirstSearch.h BFS.h DFS.h AStar.h)
