#!/bin/bash
instance_name="inst$1.txt"
instance_path="/home/valdomiro/Programming/Algoritmos-TCC/Instâncias-LKC/$instance_name"
g++ TS.cpp -o TS
./TS<$instance_path
#to execute single test, use "./execute_single_instance.sh n", where n is the instance number.
