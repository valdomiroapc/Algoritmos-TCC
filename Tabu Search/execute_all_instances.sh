#!/bin/bash
instances_path="/home/valdomiro/Programming/Algoritmos-TCC/Instâncias-LKC"
current_folder_path="/home/valdomiro/Programming/Algoritmos-TCC/Tabu\ Search/current_instance.txt"
g++ "/home/valdomiro/Programming/Algoritmos-TCC/Tabu Search/TS.cpp" "/home/valdomiro/Programming/Algoritmos-TCC/Tabu Search/instance_data.cpp" -o "/home/valdomiro/Programming/Algoritmos-TCC/Tabu Search/TS"
sleep 5
for instance in $instances_path/inst*.txt
do
    cp $instance "/home/valdomiro/Programming/Algoritmos-TCC/Tabu Search/current_instance.txt"
    ./$pwd/Tabu\ Search/TS < "/home/valdomiro/Programming/Algoritmos-TCC/Tabu Search/current_instance.txt"
done