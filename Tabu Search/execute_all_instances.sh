#!/bin/bash
instances_path="/home/valdomiro/Programming/Algoritmos-TCC/Instâncias-LKC"
current_folder_path="/home/valdomiro/Programming/Algoritmos-TCC/Tabu\ Search/current_instance.txt"
for instance in $instances_path/inst*.txt
do
    cp $instance "current_instance.txt"
done