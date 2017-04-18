#!/usr/bin/env bash
echo "Inicia compilacion"
g++ *.cpp -l pthread -o programa
echo "Programa compilado para correr ./programa"
